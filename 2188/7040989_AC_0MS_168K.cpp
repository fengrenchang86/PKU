#include <iostream>
using namespace std;
int x[1200], y[1200], z[1200];
int n;
void Input()
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d", &j, &y[i]);
		x[j] = i;
	}
	for (i = 1; i <= n; i++)
	{
		y[i] = x[y[i]];
	}
}
int Merge(int nBegin, int nEnd)
{
	if (nBegin == nEnd)
	{
		return 0;
	}
	int k = 0;
	int nMid = (nBegin + nEnd) / 2;
	k += Merge(nBegin, nMid);
	k += Merge(nMid+1, nEnd);
	int i = nBegin, j = nMid+1;
	int pos = nBegin;
	while (i <= nMid || j <= nEnd)
	{
		if (i <= nMid && j <= nEnd)
		{
			if (y[i] < y[j])
			{
				z[pos++] = y[i++];
			}
			else
			{
				z[pos++] = y[j++];
				k += (nMid - i + 1);
			}
		}
		else if (i <= nMid)
		{
			z[pos++] = y[i++];
		}
		else
		{
			z[pos++] = y[j++];
			k += (nMid - i + 1);
		}
	}
	for (i = nBegin; i <= nEnd; i++)
	{
		y[i] = z[i];
	}
	return k;
}
void Solve()
{
	int k = Merge(1, n);
	printf("%d\n", k);
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}