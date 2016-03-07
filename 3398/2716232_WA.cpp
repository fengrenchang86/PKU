#include <iostream>
#include <stdlib.h>
using namespace std;
int visit[10100];
struct ac
{
	int v;
	ac *next;
}*list[10010];
struct wa
{
	int num,id;
}v[10100];
int cmp ( const void *a, const void*b )
{
	struct wa *c = (wa*)a;
	struct wa *d = (wa*)b;
	return d->num - c->num;
}
void insert ( int x, int y )
{
	ac *p = new ac;
	p->v = y;
	p->next = list[x];
	list[x] = p;
}
bool check ( int i )
{
	ac *p = list[i];
	while ( p != NULL )
	{
		if ( visit[p->v] == 1 )
			return false;
		p = p->next;
	}
	return true;
}
void vis ( int i )
{
	visit[i] = 2;
	ac *p = list[i];
	while ( p != NULL )
	{
		if ( visit[p->v] != 2 )
			visit[p->v] = 1;
		p = p->next;
	}
}
int main ()
{
	int i,k,n,x,y;
	while ( scanf("%d",&n) && n!=-1 )
	{
		for ( i = 0; i <= n; i++ )
		{
			list[i] = NULL;
			visit[i] = 0;
			v[i].id = i;
			v[i].num = 0;
		}
		v[0].num = 2000000000;
		for ( i = 1; i < n; i++ )
		{
			scanf("%d%d",&x,&y);
			insert(x,y);
			insert(y,x);
			v[x].num++;
			v[y].num++;
		}
		qsort(v,n+1,sizeof(v[0]),cmp);
		k = 0;
		for ( i = 1; i <= n; i++ )
		{
			if ( visit[i] != 0 )
				continue;
			if ( check ( v[i].id ) == true )
			{
				k++;
				vis(v[i].id);
			}
		}
		cout<<k<<endl;
	}
	return 0;
}