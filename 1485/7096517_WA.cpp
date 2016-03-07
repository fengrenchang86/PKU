#include <iostream>
#include <queue>
using namespace std;
#define INF 2000000000
int a[220];
int n, m;
int sum[220];
int dp[220][50];
int v[220][50];
int path[220][50];
void ShowAns(int pos, int val)
{
	int x;
	if (pos == 1)
	{
		x = 0;
	}
	else
	{
		x = path[val][pos];
	}
	int i = (val - x - 1) / 2 + x + 1;
	if (pos > 1)
	{
		ShowAns(pos-1, x);
	}
	if (x + 1 != val)
	{
		printf("Depot %d at restaurant %d serves restaurants %d to %d\n", pos, i, x+1, val);
	}
	else
	{
		printf("Depot %d at restaurant %d serves restaurant %d\n", pos, i, val);
	}
}
void Solve(int tc)
{
	int i, j, k;
	for (i = 1; i <= n; i++)
	{
		for (j = 2; i+j-1 <= n; j++)
		{
			v[i][j] = a[i+(j-1)/2] * ((j-1)/2+1) - sum[i+(j-1)/2] + sum[i-1] +
				(sum[i+j-1] - sum[i+(j-1)/2]) - (j - (j-1)/2 - 1) * a[i+(j-1)/2];
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			dp[i][j] = INF;
		}
	}
	dp[1][1] = 0;
	for (i = 2; i <= n; i++)
	{
		dp[i][1] = v[1][i];
		for (j = 2; j <= i && j <= m; j++)
		{
			for (k = 1; k < i; k++)
			{
				if (dp[k][j-1] != INF && dp[i][j] > dp[k][j-1] + v[k+1][i-k])
				{
					dp[i][j] = dp[k][j-1] + v[k+1][i-k];
					path[i][j] = k;
				}
			}
		}
	}
	printf("Chain %d\n", tc);
	ShowAns(m, n);
	printf("Total distance sum = %d\n\n", dp[n][m]);
}
void Input()
{
	int i;
	sum[0] = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum[i] = sum[i-1] + a[i];
		v[i][1] = 0;
	}
}
int main()
{
	int tc = 1;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		if (n + m == 0)
		{
			break;
		}
		Input();
		Solve(tc);
		tc++;
	}
	return 0;
}