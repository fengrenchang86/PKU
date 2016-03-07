#include <iostream>
using namespace std;
struct ac
{
	int v;
	ac *next;
}*list[51000];
int w[51000];
int in[51000];
int n;
void init ()
{
	int i;
	for ( i = 0; i <= n; i++ )
	{
		w[i] = -1;
		in[i] = 0;
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
int dfs ( int node )
{
	ac *p = list[node];
	if ( p == NULL )
	{
		w[node] = 1;
		return 1;
	}
	int k = 0;
	while ( p != NULL )
	{
		if ( w[p->v] != -1 )
			k += w[p->v];
		else
			k += dfs(p->v);
		p = p->next;
	}
	w[node] = k;
	return k;
}
void input ()
{
	int m,i,x,y,k;
	scanf("%d%d",&n,&m);
	init();
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d",&x,&y);
		if ( x > y )
		{
			k = x;
			x = y;
			y = k;
		}
		insert(x,y);
		in[y] = 1;
	}
	for ( i = 1; i <= n; i++ )
	{
		if ( in[i] == 0 )
			insert(0,i);
	}
	dfs(0);
	printf("%d\n",w[0]);
}
int main ()
{
	input();
	return 0;
}