#include <iostream>
#include <math.h>
using namespace std;
double dp[120][120][2];
double p[120];
int n,t,l,b;
double ans[120][120];
bool Lose[120], Back[120];
void Solve()
{
	int i, j, k;
	for (i = 0; i <= n; i++)
	{
		Lose[i] = Back[i] = 0;
	}
	for (i = 0; i < l; i++)
	{
		scanf("%d", &j);
		Lose[j] = 1;
	}
	for (i = 0; i < b; i++)
	{
		scanf("%d", &j);
		Back[j] = 1;
	}
	for (i = 1; i <= n; i++)
	{
		dp[0][i][0] = dp[0][i][1] = 0.0;
		ans[0][i] = 0.0;
		p[i] = 0.0;
	}
	dp[0][0][0] = 1.0;
	dp[0][0][1] = 0.0;
	ans[0][0] = 1.0;
	double dTmp;
	for (i = 1; i <= t; i++)
	{
		dTmp = 0.0;
		for (j = 0; j <= n; j++)
		{
			dp[i][j][0] = dp[i][j][1] = 0.0;
			if (!Lose[j])
			{
				for (k = 1; k <= 6 && k <= j; k++)
				{
					dp[i][j][0] += dp[i-1][j-k][0] / 6.0;
				}
				if (n - j <= 6 && j != n)
				{
					for (k = 2 * n - 6 - j; k <= n; k++)
					{
						if (k >= 0 && k != n)
						{
							dp[i][j][0] += dp[i-1][k][0] / 6.0;
						}
					}
				}
				if (Back[j])
				{
					dp[i][0][0] += dp[i][j][0];
					dp[i][j][0] = 0.0;
				}
			}
			else
			{
				for (k = 1; k <= 6 && k <= j; k++)
				{
					dp[i][j][1] += dp[i-1][j-k][0] / 6.0;
				}
				if (n - j <= 6 && j != n)
				{
					for (k = 2 * n - 6 - j; k <= n; k++)
					{
						if (k >= 0 && k != n)
						{
							dp[i][j][1] += dp[i-1][k][0] / 6.0;
						}
					}
				}
				dp[i][j][0] = dp[i-1][j][1];
			}
			ans[i][j] = ans[i-1][j] + dp[i][j][0] + dp[i][j][1];
		}
		for (j = 0; j <= n; j++)
		{
			dTmp += dp[i][j][0] + dp[i][j][1];
		}
	}
	printf("%.6lf\n", ans[t][n]);
//	printf("%.6lf\n", dp[t][n][0] + dp[t][n][1]);
}
int main()
{
	while (scanf("%d %d %d %d", &n, &t, &l, &b) != EOF)
	{
		if (n + t + l + b == 0)
		{
			break;
		}
		Solve();
	}
}