#include <iostream>
using namespace std;
long long dp[210][210][210];
long long pp[210][210][210];
void Solve()
{
	int i, j, k, l;
	memset(dp, 0, sizeof(dp));
	memset(pp, 0, sizeof(pp));
	dp[0][0][0] = 1;
	pp[0][0][0] = 1;
	for (i = 1; i <= 200; i++)
	{
		dp[i][1][i] = 1;
		pp[i][1][i] = 1;
		pp[0][0][i] = 1;
	}
	for (i = 1; i <= 200; i++)
	{
		for (j = 1; j <= i; j++)
		{
			for (k = 1; k <= i-j+1; k++)
			{
				dp[i][j][k] = pp[i-k][j-1][k] ;
				pp[i][j][k] = pp[i][j][k-1] + dp[i][j][k];
			}
			while (k <= 200)
			{
				pp[i][j][k] = pp[i][j][k-1];
				k++;
			}
		}
	}
}
int main()
{
	Solve();
//	cout << "ok\n";
	int x, y;
	while (scanf("%d %d", &x, &y) != EOF)
	{
		if (x + y == 0)
		{
			break;
		}
		printf("%lld\n", pp[x][y][200]);
	}
	return 0;
}