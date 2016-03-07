#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int v,len,num;
	ac *next;
}*list[10100];
int n;
struct wa
{
	int x,y,len,num;
	__int64 d;
}road[10100];
int data[10100];
int cmp ( const void*a, const void*b )
{
	struct wa *c = (wa*)a;
	struct wa *d = (wa*)b;
	return d->d-c->d;
}
int cmp2 ( const void*a, const void*b )
{
	struct wa *c = (wa*)a;
	struct wa *d = (wa*)b;
	return c->d-d->d;
}
bool visit[10100];
void insert(int x, int y, int len, int num )
{
	ac *p = new ac;
	p->v = y;
	p->len = len;
	p->num = num;
	p->next = list[x];
	list[x] = p;
}
int dfs ( int node )
{
	visit[node] = true;
	int k = 0;
	int c = 1;
	ac *p = list[node];
	while ( p != NULL )
	{
		if ( visit[p->v] == false )
		{
			c = dfs(p->v);
			road[p->num].d = __int64(c*(n-c));
			k += c;
		}
		p = p->next;
	}
	return k+1;
}
int main ()
{
	int k,sk,sc,i;
	scanf("%d%d%d%d",&n,&k,&sk,&sc);
	for ( i = 0; i <= n; i++ )
	{
		list[i] = NULL;
		visit[i] = false;
		data[i] = -1;
	}
	for ( i = 1; i <= n-1; i++ )
	{
		scanf("%d%d%d",&road[i].x,&road[i].y,&road[i].len);
		road[i].num = i;
		insert(road[i].x,road[i].y,road[i].len,i);
		insert(road[i].y,road[i].x,road[i].len,i);
	}
	dfs(1);
	for ( i= 1; i < n; i++ )
		road[i].d = __int64(road[i].len)*road[i].d;
	road[0].d = 200000000000000;
	if ( sk <= sc )
		qsort(road,n,sizeof(road[0]),cmp);
	else
		qsort(road,n,sizeof(road[0]),cmp2);
	for ( i = 1; i < k; i++ )
		printf("%d ",road[i].num);
	printf("%d\n",road[k].num);
	return 0;
}