#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int beginX,beginY,endX,endY,n,m,v;
int w[51000];
int b[51000];
struct ac
{
	int x,y,id;
	double dis;
}a[51000];
struct wa
{
	int v,dis;
	wa *next;
}*list[51000];
int cmp ( const void*a, const void*b )
{
	ac *c = (ac*)a;
	ac *d = (ac*)b;
	return c->dis>d->dis?1:-1;
}
void insert ( int x, int y, int dis )
{
	wa *p = new wa;
	p->dis = dis;
	p->v = y;
	p->next = list[x];
	list[x] = p;
}
void input ()
{
	int i,x,y,dis;
	scanf("%d %d %d",&n,&m,&v);
	list[0] = NULL;
	a[0].dis = 0;
	a[0].id = 0;
	w[0] = 0;
	w[n+1] = 2000000000;
	for ( i = 1; i <= n; i++ )
	{
		w[i] = 2000000000;
		list[i] = NULL;
		a[i].id = i;
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d%d",&x,&y,&dis);
		insert(x,y,dis);
		insert(y,x,dis);
	}
	scanf("%d%d%d%d",&beginX,&beginY,&endX,&endY);
	a[0].x = beginX;
	a[0].y = beginY;
	a[n+1].x = endX;
	a[n+1].y = endY;
	a[n+1].id = n+1;
	for ( i = 0; i <= n+1; i++ )
	{
		a[i].dis = sqrt(double(a[i].x-beginX)*double(a[i].x-beginX)+double(a[i].y-beginY)*double(a[i].y-beginY));
		a[i].dis /= double(v);
	}
	qsort(a,n+1,sizeof(a[0]),cmp);
	for ( i = 0; i <= n; i++ )
		b[a[i].id] = i;
}
int run ()
{
	wa *p = list[0];
	while ( p != NULL )
	{
		if ( p->dis < a[b[p->v]].dis )
			w[p->v] = p->dis;
		p = p->next;
	}
	int i;
	for ( i = 1; i <= n; i++ )
	{
		if ( w[a[i].id] == 2000000000 )
			continue;
		p = list[a[i].id];
		while ( p != NULL )
		{
			if ( w[a[i].id] + p->dis < w[p->v] && (b[p->v] > i||p->v==n+1) )
				w[p->v] = w[a[i].id] + p->dis;
			p = p->next;
		}
	}
	if ( w[n+1] == 2000000000 )
		return -1;
	else
		return w[n+1];
}
int main ()
{
	int k;
	input();
	k = run();
	if ( k == -1 )
		printf("Impossible\n");
	else
		printf("%d\n",k);
	return 0;
}
