#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int v;
	ac *next;
}*list[120];
struct msg
{
	int node;
	int f;
}a[120];
int n,count;
int cmp ( const void*a, const void *b )
{
	msg *c = (msg*)a;
	msg *d = (msg*)b;
	return d->f-c->f;
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
	scanf("%d",&n);
	int i,y;
	a[0].f = 999999;
	for ( i = 1; i <= n; i++ )
	{
		a[i].node = i;
		a[i].f = 0;
		list[i] = NULL;
		while ( scanf("%d",&y) && y )
			insert(i,y);
	}
	count = 1;
}
void dfs ( int node )
{
	ac *p = list[node];
	while ( p != NULL )
	{
		if ( a[p->v].f == 0 )
		{
			a[p->v].f = -1;
			dfs(p->v);
		}
		p = p->next;
	}
	a[node].f = count++;
}
void solve ()
{
	int i;
	input();
	for ( i = 1; i <= n; i++ )
	{
		if ( a[i].f == 0 )
			dfs(i);
	}
	qsort(a,n+1,sizeof(a[0]),cmp);
	for ( i = 1; i <= n; i++ )
		printf("%d ",a[i].node);
	printf("\n");
}
int main ()
{
	solve();
	return 0;
}