#include <iostream>
#include <math.h>
using namespace std;
double dp[3][1000];
int n, m, c;
void Solve()
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j <= 500; j++)
		{
			dp[i][j] = 0.0;
		}
	}
	dp[0][0] = 1.0;
	dp[1][1] = 1.0;
	dp[1][0] = 0.0;
	for (i = 2; i <= n; i++)
	{
		for (j = 0; j <= c && j <= i; j++)
		{
			dp[i%3][j] = 0;
			if (j+1 <= i-1 && j < c)
			{
				dp[i%3][j] += dp[(i-1)%3][j+1] * (double)(j+1) / (double)c;
			}
			if (j-1 >= 0)
			{
				dp[i%3][j] += dp[(i-1)%3][j-1] * (double)(c-j+1) / (double)(c);
			}
			if (dp[i%3][j] > 1.0)
			{
				break;
			}
		}
		if (fabs(dp[i%3][m] - dp[(i-2)%3][m]) < 0.00001 && (n-i)%2==0 && i-2 >= m)
		{
			printf("%.3lf\n", dp[i%3][m]);
			return;
		}
	}
	printf("%.3lf\n", dp[n%3][m]);
}
int main()
{
	while (scanf("%d", &c) != EOF)
	{
		if (c == 0)
		{
			break;
		}
		scanf("%d %d", &n, &m);
		if (m > c || m > n)
		{
			printf("0.000\n");
		}
		else
		{
			Solve();
		}
	}
	return 0;
}