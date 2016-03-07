#include <iostream>
using namespace std;
double p[1010][40];
double dp[40][40];
int m, t, n;
void Input()
{
	int i, j;
	for (i = 0; i < t; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%lf", &p[i][j]);
		}
	}
}
void Solve()
{
	double ans, tmp, d;
	int i, j, k;
	ans = 1.0;
	for (i = 0; i < t; i++)
	{
		tmp = 1.0;
		for (j = 0; j < m; j++)
		{
			tmp *= (double)(1.0 - p[i][j]);
		}
		ans *= (double)(1.0 - tmp);
	}
	tmp = 1.0;
	for (k = 0; k < t; k++)
	{
		for (i = 0; i < m; i++)
		{
			for (j = 0; j <= m; j++)
			{
				dp[i][j] = 0.0;
			}
		}
		dp[0][0] = 1.0 - p[k][0];
		dp[0][1] = p[k][0];
		for (i = 1; i < m; i++)
		{
			dp[i][0] = dp[i-1][0] * (1.0 - p[k][i]);
			for (j = 1; j <= m; j++)
			{
				dp[i][j] = dp[i-1][j] * (1.0 - p[k][i]) + dp[i-1][j-1] * p[k][i];
			}
		}
		d = 0.0;
		for (j = 1; j < n; j++)
		{
			d += (double)(dp[m-1][j]);
		}
		tmp *= (double)(d);
	}
	ans -= (double)(tmp);
	printf("%.3lf\n", ans);
}
int main()
{
	while (scanf("%d %d %d", &m, &t, &n) != EOF) 
	{
		if (m + t + n == 0)
		{
			return 0;
		}
		Input();
		Solve();
	}
	return 0;
}