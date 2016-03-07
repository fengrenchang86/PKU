#include <iostream>
#include <map>
using namespace std;
bool visit[10010];
int n, m;
int cnt;
map<int, bool>ma;
void dfs(int v)
{
	cnt ++;
	visit[v] = true;
	int i, j;
	for(i = 0; i < v; i++)
	{
		if(!visit[i] && 0 == ma[v*10000+i])
			dfs(i);
	}
	i++;
	while(i < n)
	{
		if(!visit[i] && 0 == ma[i*10000+v])
			dfs(i);
		i++;
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
//		memset(c, 0, sizeof(c));
		ma.clear();
		for(i = 0; i < m; i++)
		{
			scanf("%d %d", &x, &y);
			x--;
			y--;
			ma[x*10000+y] = 1;
			ma[y*10000+x] = 1;
		}
		memset(visit, 0, sizeof(visit));
		cnt = 0;
		dfs(0);
		printf("Case %d: %d\n", tc++, cnt - 1);
	}
	return 0;
}