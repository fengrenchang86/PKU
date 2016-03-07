#include <iostream>

using namespace std;
bool c[10010][10010];
bool visit[10010];
int n, m;
int cnt;
void dfs(int v)
{
	cnt ++;
	visit[v] = true;
	int i;
	for(i = 1; i <= n; i++)
	{
		if(!visit[i] && !c[v][i])
			dfs(i);
	}
}
int main()
{
	int x, y, i;
	int tc = 1;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		if(n == 0 && m == 0)
			break;
		memset(c, 0, sizeof(c));
		for(i = 0; i < m; i++)
		{
			scanf("%d %d", &x, &y);
			c[x][y] = c[y][x] = true;
		}
		memset(visit, 0, sizeof(visit));
		cnt = 0;
		dfs(1);
		printf("Case %d: %d\n", tc++, cnt - 1);
	}
	return 0;
}