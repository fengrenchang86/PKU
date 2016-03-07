#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int v;
	ac *next;
}*list[17000];
struct acm
{
	int id;
	int x,y;
}a[17000];
bool visit[17000];
int w[17000];
int n,m,count;
void insert ( int x, int y )
{
	ac *p = new ac;
	p->v = y;
	p->next = list[x];
	list[x] = p;
}
int cmp ( const void *a, const void*b )
{
	return *(int*)b - *(int*)a;
}
int cmpx ( const void *a, const void*b )
{
	struct acm*c = (acm*)a;
	struct acm*d = (acm*)b;
	if ( c->x != d->x )
		return c->x - d->x;
	else
		return c->y - d->y;
}
int cmpy ( const void *a, const void*b )
{
	struct acm*c = (acm*)a;
	struct acm*d = (acm*)b;
	if ( c->y != d->y )
		return c->y - d->y;
	else
		return c->x - d->x;
}
void dfs ( int node )
{
	count++;
	visit[node] = true;
	ac *p = list[node];
	while ( p != NULL )
	{
		if ( visit[p->v] == false )
			dfs(p->v);
		p = p->next;
	}
}
void solve ()
{
	scanf("%d%d",&n,&m);
	int i,j;
	for ( i = 0; i < n;i++ )
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].id = i;
	}
	qsort(a,n,sizeof(a[0]),cmpx);
	for ( i = 1; i < n; i++ )
	{
		if ( a[i].x != a[i-1].x )
			continue;
		if ( a[i].y - a[i-1].y == 1 )
		{
			insert(a[i].id,a[i-1].id);
			insert(a[i-1].id,a[i].id);
		}
	}
	qsort(a,n,sizeof(a[0]),cmpy);
	for ( i = 1; i < n; i++ )
	{
		if ( a[i].y != a[i-1].y )
			continue;
		if ( a[i].x - a[i-1].x == 1 )
		{
			insert(a[i].id,a[i-1].id);
			insert(a[i-1].id,a[i].id);
		}
	}
	j = 0;
	memset(visit,false,sizeof(visit));
	for ( i = 0; i < n; i++ )
	{
		if ( !visit[i] )
		{
			count = 0;
			dfs(i);
			w[j++] = count;
		}
	}
	qsort(w,j,sizeof(w[0]),cmp);
	i = 0;
	for ( j = 0; j < m; j++ )
	{
		i += w[j];
	}
	printf("%d\n",i);
}
int main ()
{
	solve();
	return 0;
}