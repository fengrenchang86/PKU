#include <iostream>
using namespace std;
bool c[20][20];
__int64 dp[17000][15][15];
__int64 num[17000][15][15];
int val[20];
int a[20];
int n, m;
void Init()
{
	int i, j, k;
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= n; j++)
			c[i][j] = false;
	}
	for(i = 1; i <= n; i++)
		c[0][i] = true;
	int x = 1 << (n+1);
	for(i = 0; i <= x; i++)
	{
		for(j = 0; j < 15; j++)
		{
			for(k = 0; k < 15; k++)
			{
				dp[i][j][k] = -1;
				num[i][j][k] = 0;
			}
		}
	}
}
void Input()
{
	scanf("%d %d", &n, &m);
	Init();
	int i, x, y;
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &val[i]);
	}
	val[0] = 0;
	for(i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		c[x][y] = c[y][x] = true;
	}
}
void dfs(unsigned int status, int x, int y)
{
	unsigned int t = (1<<y);
	t = ~t;
	unsigned int nStatus = status;
	dp[status][x][y] = 0;
	status = (status & t);
	if(status == 1)
	{
		dp[nStatus][x][y] = val[y];
		num[nStatus][x][y] = 1;
		return;
	}
	else if(x == 0)
	{
		dp[nStatus][x][y] = -2;
		return;
	}
	__int64 j;
	int k;
	
	for(k = n; k >= 0; k--)
	{
		t = (1 << k);
		if((status | t) == status && c[k][x])
		{
			if(dp[status][k][x] == -1)
			{
				dfs(status, k, x);
			}
			if(dp[status][k][x] == -2)
				continue;
			j = dp[status][k][x] + val[y] + val[x] * val[y] + val[k] * val[x] * val[y];
			if(j > dp[nStatus][x][y])
			{
				dp[nStatus][x][y] = j;
				num[nStatus][x][y] = num[status][k][x];
			}
			else if(j == dp[nStatus][x][y])
				num[status][x][y] += num[status][k][x];
		}
	}
	if(dp[nStatus][x][y] == 0)
		dp[nStatus][x][y] = -2;
}
void Solve()
{
	if(n == 1)
	{
		printf("%d 1\n", val[1]);
		return;
	}
	unsigned int v = (1<<(n+1)) - 1;
	int i, j;
	__int64 ans = 0, k = 0;
	for(i = 1; i <= n; i++)
	{
		dp[1<<i][0][i] = val[i];
		num[1<<i][0][i] = 1;
	}
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if(i != j && c[i][j] == true)
			{
				dfs(v, i, j);
				if(dp[v][i][j] > ans)
				{
					ans = dp[v][i][j];
					k = num[v][i][j];
				}
				else if(dp[v][i][j] == ans)
				{
					k += num[v][i][j];
				}
			}
		}
	}
	printf("%I64d %I64d\n", ans, k/2);
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		Input();
		Solve();
	}
	return 0;
}