#include <iostream>
using namespace std;
struct ac
{
	int v;
	ac *next;
}*list[1200];
bool visit[1200];
int n,m;
void init ()
{
	int i;
	for ( i = 0; i < 1200; i++ )
	{
		visit[i] = false;
		list[i] = NULL;
	}
}
void insert ( int x, int y )
{
	ac *p = new ac;
	p->v = y;
	p->next = list[x];
	list[x] = p;
}
void input ()
{
	scanf("%d%d",&n,&m);
	int i,x,y;
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d",&x,&y);
		insert(x,y);
	}
}
void dfs ( int node )
{
	visit[node] = true;
	ac *p = list[node];
	while ( p != NULL )
	{
		if ( !visit[p->v] )
			dfs(p->v);
		p = p->next;
	}
}
void solve ()
{
	int i,j=0;
	for ( i = 1; i <= n; i++ )
	{
		memset(visit,false,sizeof(visit));
		dfs(i);
		for ( j = 1; j <= n; j++ )
		{
			if ( visit[j] == false )
				break;
		}
		if ( j <= n )
		{
			printf("No\n");
			return;
		}
	}
	printf("Yes\n");
}
int main ()
{
	int tc;
	scanf("%d",&tc);
	while ( tc-- )
	{
		init();
		input();
		solve();
	}
	return 0;
}