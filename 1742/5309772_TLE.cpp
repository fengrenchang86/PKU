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
	int i, j;
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j <= m; j++)
		{
			dp[i][j] = 0;
			use[i][j] = -1;
		}
	}
	for(i = 0; i < 2; i++)
		dp[i][0] = true;
	for(i = 1; i <= n; i++)
	{
		for(j = 0; j <= m; j++)
		{
			if(dp[(i-1)%2][j])
			{
				dp[i%2][j] = true;
				use[i%2][j] = c[i];
			}
			else
				use[i%2][j] = -1;
		}
		for(j = 0; j <= m; j++)
		{
			if(j + a[i] <= m && use[i%2][j + a[i]] == -1 && use[i%2][j] > 0)
			{
				dp[i%2][j + a[i]] = true;
				use[i%2][j + a[i]] = use[i%2][j] - 1;
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