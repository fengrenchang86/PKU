#include <iostream>
using namespace std;
__int64 dp[20][2100];
int a[20], b[20];
int n, m;
__int64 Solve()
{
	int i, j, k, y;
	__int64 t = 0;
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= m; j++)
		{
			dp[i][j] = 0;
		}
	}
	a[1] = 1;
	for(i = 2; i <= n; i++)
		a[i] = a[i-1] * 2;
	b[n] = m;
	for(i = n - 1; i >= 1; i--)
		b[i] = b[i+1] / 2;
	for(i = 1; i <= n; i++)
	{
		if(a[i] > b[i])
			return 0;
	}
//	b[1] = 1;
	dp[0][0] = 1;
	for(i = 1; i <= n; i++)
	{
		for(j = a[i]; j <= b[i]; j++)
		{
			y = j / 2;
			for(k = a[i-1]; k <= y; k++)
			{
				dp[i][j] += dp[i-1][k];
			}
		}
	}
	t = 0;
	for(j = a[n]; j <= b[n]; j++)
	{
		t += dp[n][j];
	}
	return t;
}
int main()
{
	int i, tc;
	__int64 ans;
	scanf("%d", &tc);
	for(i = 1; i <= tc; i++)
	{
		scanf("%d %d", &n, &m);
		ans = Solve();
		printf("Case %d: n = %d, m = %d, # lists = %I64d\n", i, n, m, ans);
	}
	return 0;
}