#include <iostream>
#include <queue>
using namespace std;
bool c[2100][2100];
bool visit[2100];
int key[2100];
int n;
queue<int>que;
void init ()
{
	memset(c,false,sizeof(c));
	memset(visit,false,sizeof(visit));
	int i;
	for ( i = 0; i <= n; i++ )
		key[i] = -1;
}
bool bfs ( )
{
	int i,j,k;
	while ( !que.empty() )
		que.pop();
	for ( i = 1; i <= n; i++ )
	{
		if ( visit[i] == true )
			continue;
		key[i] = 0;
		visit[i] = true;
		que.push(i);
		while ( !que.empty() )
		{
			k = que.front();
			que.pop();
			for ( j = 1; j <= n; j++ )
			{
				if ( c[j][k] == false )
					continue;
				if ( visit[j] == false )
				{
					visit[j] = true;
					key[j] = !key[k];
					que.push(j);
				}
				else if ( key[j] != !key[k] && j!=k )
					return false;
			}
		}
	}
	return true;
}
int main ()
{
	int it,tcase;
	scanf("%d",&tcase);
	int i,m,x,y;
	for ( it = 1; it<=tcase; it++ )
	{
		scanf("%d%d",&n,&m);
		init();
		for ( i = 0; i < m; i++ )
		{
			scanf("%d%d",&x,&y);
			c[x][y] = c[y][x] = true;
		}
		printf("Scenario #%d:\n",it);
		if ( bfs() )
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");
		printf("\n");
	}
	return 0;
}