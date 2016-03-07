
#include <iostream>
using namespace std;
#define INF 300
struct ac
{
	int val;
	int nCount;
	int data;
}a[210][210];
int c[210][210];
int d[210][210];
int g_nDis, g_nCount, g_nVal;
int n;
void Input()
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &c[i][j]);
		}
	}
}
int Solve(int x, int y)
{
	int i, j, k;
	int t = n * n - 1;
	for (k = 1; k <= t; k++)
	{
		g_nCount = 0;
		for (i = 0; i <= k; i++)
		{
			j = k - i;
			if (x - i >= 1 && y - j >= 1)
			{
				if (c[x-i][y-j])
				{
					g_nCount++;
					g_nVal = c[x-i][y-j];
				}
			}
			if (x - i >= 1 && y + j <= n && j != 0)
			{
				if (c[x-i][y+j])
				{
					g_nCount++;
					g_nVal = c[x-i][y+j];
				}
			}
			if (x + i <= n && y - j >= 1 && i != 0)
			{
				if (c[x+i][y-j])
				{
					g_nCount++;
					g_nVal = c[x+i][y-j];
				}
			}
			if (x + i <= n && y + j <= n && j != 0 && i != 0)
			{
				if (c[x+i][y+j])
				{
					g_nCount++;
					g_nVal = c[x+i][y+j];
				}
			}
		}
		if (g_nCount == 1)
		{
			return g_nVal;
		}
		else if (g_nCount > 1)
		{
			return 0;
		}
	}
	return 0;
}
void Solve()
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <=n ; j++)
		{
			if (c[i][j])
			{
				d[i][j] = c[i][j];
				continue;
			}
			d[i][j] = Solve(i, j);
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
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
