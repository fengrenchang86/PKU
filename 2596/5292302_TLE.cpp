#include <iostream>
using namespace std;
int dice[20][6];
int dp[20][8];
int p[6] = {5, 3, 4, 1, 2, 0};
int f[20][6];
int a[20][6];
bool visit[20];
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
			k = -1;
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
void dfs(int lay, int pre)
{
	int i, j, k;
	if(lay == n)
	{
		return;
	}
	for(k = 0; k < n; k++)
	{
		if(visit[k])
			continue;
		visit[k] = true;
		if(lay == 0)
		{
			for(i = 0; i < 6; i++)
			{
				dp[k][i] = f[k][i];
				if(dp[k][i] > ans)
					ans = dp[k][i];
			}
		}
		else
		{
			for(i = 0; i < 6; i++)
			{
				dp[k][i] = 0;
				for(j = 0; j < 6; j++)
				{
					if(dice[k][p[i]] == dice[pre][j])
					{
						if(dp[k][i] < dp[pre][j] + f[k][i])
							dp[k][i] = dp[pre][j] + f[k][i];
					}
				}
				if(dp[k][i] > ans)
					ans = dp[k][i];
			}
		}
		dfs(lay+1, k);
		visit[k] = false;
	}
	
}
void Solve()
{
	getf();
	ans = 0;
	memset(visit, false, sizeof(visit));
	dfs(0, -1);
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