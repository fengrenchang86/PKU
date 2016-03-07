#include <iostream>
#include <stdlib.h>
using namespace std;
#define inf 2000000000
int a[600], sum[600];
int dp[600][600];
int n, m;
int acMin(int x, int y)
{
	return x < y ? x : y;
}
int acMax(int x, int y)
{
	return x > y ? x : y;
}
void Init()
{
	int i, j = 0;
	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= m; j++)
			dp[i][j] = inf;
	}
	sum[0] = 0;
	for(i = 1; i <= n; i++)
	{
		sum[i] = sum[i-1] + a[i];
		dp[i][1] = sum[i];
	}
}
void Solve()
{
	int i, j, k, t;
	dp[0][1] = 0;
	for(i = 2; i <= n; i++)
	{
		for(j = 2; j <= i && j <= m; j++)
		{
			for(k = 0; k < i; k++)
			{
				t = acMax(dp[k][(j-1)], sum[i] - sum[k]);
				if(dp[i][j] > t)
				{
					dp[i][j] = t;
				}
			}
		}
	}
	t = dp[n][m];
	memset(sum, 0, sizeof(sum));
	j = 0;
	k = m;
	for(i = n; i >= 1; i--)
	{
		if(j + a[i] > t || k > i)
		{
			j = a[i];
			k--;
			sum[i] = 1;
		}
		else
			j += a[i];
	}
	for(i = 1; i < n; i++)
	{
		printf("%d ", a[i]);
		if(sum[i] == 1)
		{
			printf("/ ");
		}
	}
	printf("%d\n", a[n]);
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d %d", &n, &m);
		Init();
		Solve();
	}
	return 0;
}