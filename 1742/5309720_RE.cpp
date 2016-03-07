#include <iostream>
using namespace std;
bool dp[110][110110];
int use[110][110110];
int a[110];
int c[110];
int n, m;
void Input()
{
	int i;
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
	}
}
void Solve()
{
	int i, j;
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j < 100100; j++)
		{
			dp[i][j] = 0;
			use[i][j] = -1;
		}
	}
	for(i = 0; i <= m; i++)
		dp[i][0] = true;
	for(i = 1; i <= n; i++)
	{
		for(j = 0; j <= m; j++)
		{
			if(dp[i-1][j])
			{
				dp[i][j] = true;
				use[i][j] = c[i];
			}
			else
				use[i][j] = -1;
		}
		for(j = 0; j <= m; j++)
		{
			if(dp[i][j] && use[i][j + a[i]] == -1 && use[i][j] > 0)
			{
				dp[i][j + a[i]] = true;
				use[i][j + a[i]] = use[i][j] - 1;
			}
		}
	}
	j = 0;
	for(i = 1; i <= m; i++)
	{
		if(dp[n][i])
			j++;
	}
	printf("%d\n", j);
}
int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		if(n == 0 && m == 0)
			break;
		Input();
		Solve();
	}
	return 0;
}