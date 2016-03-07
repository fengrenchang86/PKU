#include <iostream>
using namespace std;
bool dp[2][110110];
short use[2][110110];
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
	int i, j, k;
	for(j = 0; j <= m; j++)
	{
		dp[0][j] = 0;
		dp[1][j] = 0;
		use[0][j] = -1;
		use[1][j] = -1;
	}
	dp[0][0] = dp[1][0] = 1;
	for(k = 1; k <= n; k++)
	{
		i = k % 2;
		for(j = 0; j <= m; j++)
		{
			if(dp[(i+1)%2][j])
			{
				dp[i][j] = true;
				use[i][j] = c[k];
			}
			else
				use[i][j] = -1;
		}
		for(j = 0; j <= m; j++)
		{
			if(j + a[k] <= m && use[i][j + a[k]] == -1 && use[i][j] > 0)
			{
				dp[i][j + a[k]] = true;
				use[i][j + a[k]] = use[i][j] - 1;
			}
		}
	}
	j = 0;
	for(i = 1; i <= m; i++)
	{
		if(dp[n%2][i])
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