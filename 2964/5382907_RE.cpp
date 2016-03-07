#include <iostream>
using namespace std;
char a[120][120];
int dp[120][120][120];
int n, m;
void Input()
{
	int i;
	scanf("%d %d", &m, &n);
	for(i = 0; i < n; i++)
	{
		scanf("%s", &a[i]);
	}
}
void Solve()
{
	int i, j, k, v;
	for(i = 0; i < 120; i++)
	{
		for(j = 0; j < 120; j++)
		{
			for(k = 0; k < 120; k++)
				dp[i][j][k] = -12312312;
		}
	}
	if(a[0][0] == '*')
		dp[0][0][0] = 1;
	else
		dp[0][0][0] = 0;
	for (i = 1; i <= n + m - 2; i++)
	{
		for (j = 0; j < m && j < i; j++)
		{
			if (i - j >= n)
			{
				continue;
			}
			for (k = j; k < m && k <= i; k++)
			{
				if (i - k >= n)
				{
					continue;
				}
				v = 0;
				if(a[i-j][j] == '*')
					v++;
				else if(a[i-j][j] == '#')
					continue;
				if(a[i-k][k] == '*' && j != k)
					v++;
				else if(a[i-k][k] == '#')
					continue;
				if (j > 0)
				{
					if (k > 0)
					{
						if(dp[i-1][j-1][k-1] + v > dp[i][j][k])
							dp[i][j][k] = dp[i-1][j-1][k-1] + v;
					}
					if(dp[i-1][j-1][k] + v > dp[i][j][k])
						dp[i][j][k] = dp[i-1][j-1][k] + v;
				}
				if (k > 0)
				{
					if(dp[i-1][j][k-1] + v > dp[i][j][k])
						dp[i][j][k] = dp[i-1][j][k-1] + v;
				}
				if(dp[i-1][j][k] + v > dp[i][j][k])
					dp[i][j][k] = dp[i-1][j][k] + v;
			}
		}
	}
	printf("%d\n", dp[n+m-2][m-1][m-1]);
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		Input();
		Solve();
	}
	return 0;
}