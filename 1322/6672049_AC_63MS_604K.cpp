#include <iostream>
#include <math.h>
using namespace std;
double dp[1200][102];
int n, m, c;
void Solve()
{
	int i, j;
	dp[0][0] = 1.0;
	dp[1][1] = 1.0;
	dp[1][0] = 0.0;
	for (i = 2; i <= n; i++)
	{
		for (j = 0; j <= c && j <= i; j++)
		{
			dp[i][j] = 0.0;
			if (j+1 <= i-1 && j < c)
			{
				dp[i][j] += (double)dp[(i-1)][j+1] * (double)(j+1) / (double)c;
			}
			if (j-1 >= 0)
			{
				dp[i][j] += (double)dp[(i-1)][j-1] * (double)(c-j+1) / (double)(c);
			}
		}
		if (i-2 >= m && (n-i)%2 == 0 && i >= 100 && fabs((double)dp[i][m] - (double)dp[(i-2)][m]) < 0.000001)
		{
			printf("%.3lf\n", dp[i][m]);
			return;
		}
	}
	printf("%.3lf\n", dp[n][m]);
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
		if (m > c || m > n || (n-m)%2==1)
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