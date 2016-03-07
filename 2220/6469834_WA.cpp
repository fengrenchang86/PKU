#include <iostream>
using namespace std;
int t, h;
int a[10][10];
int c[10];
bool visit[10];
int b[10];
int ansC[10];
int ansB[10];
int ans;
void dfs(int lay, int pos)
{
	int i;
	if (lay == h)
	{
		int j = 0, k;
		int nMin(1000000000), nMax(-1000000000);
		b[h] = t;
		b[0] = 0;
		for (i = 1; i <= h; i++)
		{
			k = 0;
			for (j = b[i-1]; j < b[i]; j++)
			{
				k += a[i-1][c[j]];
			}
			if (k < nMin)
			{
				nMin = k;
			}
			if (k > nMax)
			{
				nMax = k;
			}
		}
		if (nMax - nMin < ans)
		{
			ans = nMax - nMin;
			for (i = 0; i < t; i++)
			{
				ansC[i] = c[i];
			}
			for (i = 0; i < h; i++)
			{
				ansB[i] = b[i];
			}
		}
		return;
	}
	for (i = pos; i < t; i++)
	{
		b[lay] = i;
		if (i < t || i == t && lay + 1 == h)
		{
			dfs(lay + 1, i);
		}
	}
}
void Meiju(int lay)
{
	if (lay == t)
	{
		dfs(1, 0);
		return;
	}
	int i;
	for (i = 0; i < t; i++)
	{
		if (!visit[i])
		{
			visit[i] = 1;
			c[lay] = i;
			Meiju(lay + 1);
			visit[i] = 0;
		}
	}
}
int main()
{
	int it = 1;
	int i, j, k;
	char ch[100];
	while (scanf(" %s", &ch) != EOF)
	{
		if (it > 1)
		{
			printf("%\n");
		}
		it++;
		scanf("%d %d", &t, &h);
		for (i = 0; i < h; i++)
		{
			for (j = 0; j < t; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		ans = 2000000000;
		scanf(" %s", &ch);
		Meiju(0);
		ansB[h] = t;
		ansB[0] = 0;
		for (i = 1; i <= h; i++)
		{
			k = 0;
			for (j = ansB[i-1]; j < ansB[i]; j++)
			{
				printf("%d ", ansC[j] + 1);
				k += a[i-1][ansC[j]];
			}
			printf("%d\n", k);
		}
	}
	return 0;
}