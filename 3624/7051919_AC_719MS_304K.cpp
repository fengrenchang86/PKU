#include <iostream>
using namespace std;
int dp[2][13000];
int d[4000];
int sum[4000];
int w[4000];
int n, m;
int GetMax(int x, int y)
{
	return x > y ? x : y;
}
int GetMax(int x, int y, int z)
{
	return GetMax(x, GetMax(y, z));
}
void Input()
{
	int i;
	sum[0] = 0;
	for(i = 1; i <= n; i++)
	{
		scanf("%d %d", &w[i], &d[i]);
		sum[i] = sum[i-1] + w[i];
	}
	for(i = 0; i <= m; i++)
	{
		dp[0][i] = 0;
	}
}
void Solve()
{
	int i, j, k;
	for(i = 1; i <= n; i++)
	{
		k = sum[i] < m ? sum[i] : m;
		for(j = 1; j <= k; j++)
		{
			dp[i%2][j] = GetMax(dp[(i+1)%2][j], dp[i%2][j-1]);
			if(j >= w[i])
				dp[i%2][j] = GetMax(dp[i%2][j], dp[(i+1)%2][j-w[i]] + d[i]);
		}
	}
	printf("%d\n", dp[n%2][m]);
}
int main()
{
	scanf("%d %d", &n, &m);
	Input();
	Solve();
	return 0;
}