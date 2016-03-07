#include <iostream>
using namespace std;
#define INF 2000000000
int dis[20][20];
int degree[20];
bool visit[20];
int nSumLen;
int ans;
int n, m;
void Input()
{
	scanf("%d", &m);
	int i, j, x, y, len;
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= n; j++)
			dis[i][j] = INF;
		dis[i][i] = 0;
		degree[i] = 0;
	}
	nSumLen = 0;
	for(i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &len);
		nSumLen += len;
		if(dis[x][y] > len)
		{
			dis[x][y] = len;
			dis[y][x] = len;
		}
		degree[x]++;
		degree[y]++;
	}
}
void dfs(int lay, int sum)
{
	if(lay == m / 2)
	{
		if(sum < ans)
			ans = sum;
		return;
	}
	int i, j;
	for(i = 0; i < m; i++)
	{
		if(!visit[degree[i]])
			break;
	}
	visit[degree[i]] = true;
	for(j = i + 1; j < m; j++)
	{
		if(!visit[degree[j]])
		{
			visit[degree[j]] = true;
			dfs(lay + 1, sum + dis[degree[i]][degree[j]]);
			visit[degree[j]] = false;
		}
	}
	visit[degree[i]] = false;
}
void Solve()
{
	int i, j, k;
	m = 0;
	for(i = 1; i <= n; i++)
	{
		if(degree[i] % 2)
			degree[m++] = i;
	}
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			for(k = 1; k <= n; k++)
			{
				if(dis[k][j] > dis[i][k] + dis[i][j])
					dis[k][j] = dis[i][k] + dis[i][j];
			}
		}
	}
	ans = INF;
	memset(visit, false, sizeof(visit));
	dfs(0, 0);
	printf("%d\n", nSumLen + ans);
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
			break;
		Input();
		Solve();
	}
	return 0;
}