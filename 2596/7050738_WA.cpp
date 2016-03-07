#include <iostream>
using namespace std;
int dice[20][6];
int dp[1026][10][6];
int p[6] = {5, 3, 4, 1, 2, 0};
int f[20][6];
int ans;
int n;
void getf()
{
	int a, b, i, j;
	int k;
	for(i = 0; i < n; i++)
	{
		for(a = 0; a < 6; a++)
		{
			k = -1000000000;
			b = p[a];
			for(j = 0; j < 6; j++)
			{
				if(j == a || j == b)
					continue;
				if(dice[i][j] > k)
				{
					k = dice[i][j];
				}
			}
			f[i][a] = k;
		}
	}
}
void dfs(int x, int y, int z)
{
	if (dp[x][y][z] > -1000000000)
	{
		return;
	}
	int xx = x;
	int i, j, k = 1;
	x = x & (~(1 << y));
	if (x == 0)
	{
		dp[xx][y][z] = f[y][z];
		return;
	}
	for (i = 0; i < n; i++)
	{
		if ((x & k))
		{
			for (j = 0; j < 6; j++)
			{
				if (dice[y][p[z]] == dice[i][j])
				{
					dfs(x, i, j);
					if (dp[xx][y][z] < dp[x][i][j] + f[y][z])
					{
						dp[xx][y][z] = dp[x][i][j] + f[y][z];
					}
				}
			}
		}
		k <<= 1;
	}
}
void Input()
{
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < 6; j++)
		{
			scanf("%d", &dice[i][j]);
		}
	}
}
void Solve()
{
	ans = 0;
	getf();
	int i, j, k;
	for (i = 1 << n; i >= 0; i--)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < 6; k++)
			{
				dp[i][j][k] = -1000000000;
			}
		}
	}
	k = (1 << n) - 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 6; j++)
		{
			if (ans < dice[i][j])
			{
				ans = dice[i][j];
			}
			dfs(k, i, j);
			if (ans < dp[k][i][j])
			{
				ans = dp[k][i][j];
			}
		}
	}
	printf("%d\n", ans);
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