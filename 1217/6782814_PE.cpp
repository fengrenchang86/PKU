#include <iostream>
using namespace std;
int m;
double dp[30][200];
double p[7] = {0.0625, 0, 0.125, 0.375, 0.25, 0.125, 0.0625};
void Solve()
{
	int i, j, k;
	for (i = 0; i <= 20; i++)
	{
		for (j = 0; j < 200; j++)
		{
			dp[i][j] = 0.0;
		}
	}
	m = 60;
	for (i = -3; i <= 3; i++)
	{
		dp[1][i+m] = p[i+3];
	}
	for (i = 2; i <= 20; i++)
	{
		for (j = -i*3; j <= i*3; j++)
		{
			dp[i][j+m] = 0.0;
			for (k = -3; k <= 3; k++)
			{
				dp[i][j+m] += dp[i-1][j+m+k] * p[3-k];
			}
		}
	}
	double pro;
	printf("Round   A wins    B wins    Tie\n");
	for (i = 1; i <= 20; i++)
	{
		printf("%5d   ", i);
		pro = 0.0;
		for (j = m+1; j <= 2 * m; j++)
		{
			pro += dp[i][j];
		}
		
		printf("%7.4lf%%", pro * 100);
		pro = 0.0;
		for (j = 0; j < m; j++)
		{
			pro += dp[i][j];
		}
		printf("%8.4lf%%", pro * 100);
		pro = dp[i][m];
		printf("%8.4lf%%\n", pro * 100);
	}
}
int main()
{
	Solve();
	return 0;
}