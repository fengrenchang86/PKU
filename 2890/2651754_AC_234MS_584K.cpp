#include <iostream>
using namespace std;
struct ac
{
	int v;
	ac *next;
}*list[1200];
bool visit[1200];
void insert ( int x, int y )
{
	ac *p = new ac;
	p->v = y;
	p->next = list[x];
	list[x] = p;
}
void dfs ( int node )
{
	ac *p = list[node];
	while( p != NULL )
	{
		if ( visit[p->v] == false )
		{
			visit[p->v] = true;
			dfs(p->v);
		}
		p = p->next;
	}
}
int main ()
{
	int n,m;
	int x,y,i,j;
	while ( scanf("%d%d",&n,&m) != EOF )
	{
		for ( i = 0; i < n; i++ )
			list[i] = NULL;
		for ( i = 0; i < m; i++ )
		{
			scanf("%d%d",&x,&y);
			insert(x,y);
		}
		x = 0;
		for ( i = 0; i < n; i++ )
		{
			for ( j = 0; j < n; j++ )
				visit[j] = false;
			visit[i] = true;
			dfs(i);
			for ( j = 0; j < n; j++ )
			{
				if ( visit[j] == true )
					x++;
			}
		}
		cout<<x<<endl;
	}
	return 0;
}