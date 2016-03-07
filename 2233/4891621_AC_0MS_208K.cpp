#include <iostream>
using namespace std;
int xm[60], ym[60];
bool visit[60];
bool c[60][60];
int n;
bool dfs(int u)
{
	int i;
	for(i = 1; i <= n; i++)
	{
		if(!visit[i] && c[u][i])
		{
			visit[i] = true;
			if(ym[i] == -1 || dfs(ym[i]))
			{
				ym[i] = u;
				xm[u] = i;
				return true;
			}
		}
	}
	return false;
}
int MaxMatch()
{
	int u;
	int ret = 0;
	memset(xm, -1, sizeof(xm));
	memset(ym, -1, sizeof(ym));
	for(u = 1; u <= n; u++)
	{
		if(xm[u] == -1)
		{
			memset(visit, false, sizeof(visit));
			if(dfs(u))
				ret ++;
		}
	}
	return ret;
}
void Solve()
{
	int ans = MaxMatch();
	if(ans == n)
		printf("bob\n");
	else
		printf("alice\n");
}
void Input()
{
	int m, i, x, y;
	for(i = 0; i <= n; i++)
	{
		for(int j = 0; j <= n; j++)
			c[i][j] = false;
	}
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		c[x][y] = c[y][x] = true;
	}
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