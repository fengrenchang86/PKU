#include <iostream>
using namespace std;
#define INF 10000000000000000
__int64 dp[1110][110][2];
int n, t;
void Init()
{
	int i, j;
	for(i = 0; i <= 1100; i++)
	{
		for(j = 0; j <= 100; j++)
			dp[i][j][0] = dp[i][j][1] = 0;
	}
	for(i = 1; i <= 1100; i++)
		dp[i][1][0] = 1;
}
void Solve(int nBegin, int nEnd)
{
	int i, j, k;
	for(i = nBegin; i <= nEnd; i++)
	{
		for(j = 2; j <= i && j <= 100; j++)
		{
			if(i == j)
				dp[i][j][0] = 1;
/*			for(k = 1; k <= j; k++)
			{
				dp[i][j][0] += dp[i-j][k][0];
				dp[i][j][1] += dp[i-j][k][1];
				if(dp[i][j][0] > INF)
				{
					dp[i][j][1] += dp[i][j][0] / INF;
					dp[i][j][0] %= INF;
				}
			}
			*/
			dp[i][j][0] += dp[i][j-1][0];
			dp[i][j][1] += dp[i][j-1][1];
			dp[i][j][0] += dp[i-j][j][0];
			dp[i][j][1] += dp[i-j][j][1];
			if(dp[i][j][0] > INF)
			{
				dp[i][j][1] += dp[i][j][0] / INF;
				dp[i][j][0] %= INF;
			}
		}
		while(j <= 100)
		{
			dp[i][j][0] = dp[i][j-1][0];
			dp[i][j][1] = dp[i][j-1][1];
			j++;
		}
	}
}
int main()
{
	Init();
	Solve(1, 1000);
	while(scanf("%d %d", &n, &t) != EOF)
	{
		if(dp[n][t][1] == 0)
			printf("%I64d\n", dp[n][t][0]);
		else
			printf("%I64d%016I64d\n", dp[n][t][1], dp[n][t][0]);
	}
	return 0;
}