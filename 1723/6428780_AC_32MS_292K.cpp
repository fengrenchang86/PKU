#include <iostream>
#include <stdlib.h>
using namespace std;
int a[12000], b[12000];
int c[12000];
int n;
int cmp(const void*a, const void*b)
{
	return *(int*)a - *(int*)b;
}
void Input()
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i], &b[i]);
	}
}
int Erfen(int *t, int val)
{
	int nBegin = 0;
	int nEnd = n - 1;
	int nMid;
	while (nBegin < nEnd)
	{
		nMid = (nBegin + nEnd) / 2;
		if (t[nMid] > val)
		{
			nEnd = nMid;
		}
		else if (t[nMid] < val)
		{
			nBegin = nMid + 1;
		}
		else
			return nMid;
	}
	return nBegin;
}
int GetAns(int *t)
{
	int i, j, k;
	int ans = 2000000000;
	qsort(t, n, sizeof(t[0]), cmp);
	c[0] = t[0];
	for (i = 1; i < n; i++)
	{
		c[i] = c[i-1] + t[i];
	}
	for (i = 0; i < n; i++)
	{
		if (t[i] == t[0])
		{
			k = c[n-1] - n * t[0];
		}
		else if (t[i] == t[n-1])
		{
			k = n * t[n-1] - c[n-1];
		}
		else
		{
			j = Erfen(t, t[i]);
			k = j * t[i] - c[j-1] + c[n-1] - c[j-1] - (n - j) * t[i];
		}
		if (k < ans)
		{
			ans = k;
		}
	}
	return ans;
}
void Solve()
{
	int ans;
	ans = GetAns(b);
	qsort(a, n, sizeof(a[0]), cmp);
	int i;
	for (i = 0; i < n; i++)
	{
		a[i] -= i;
	}
	ans += GetAns(a);
	printf("%d\n", ans);
}
int main()
{
	scanf("%d", &n);
	Input();
	Solve();
	return 0;
}