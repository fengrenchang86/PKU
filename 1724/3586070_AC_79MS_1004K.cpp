#include <iostream>
#include <queue>
using namespace std;
const int inf = 2000000000;
int dis[110];
int money[110];
int w[110];
bool visit[110];
int n,m,r;
struct ac
{
	int dis,cost;
	int v;
	ac *next;
}*list[110],*vlist[110];
void init ()
{
	int i;
	for ( i= 0 ; i <= n; i++ )
	{
		list[i] = vlist[i] = NULL;
	}
}
void insert ( int x, int y, int a, int b )
{
	ac *p = new ac;
	p->v = y;
	p->dis = a;
	p->cost = b;
	p->next = list[x];
	list[x] = p;
	p = new ac;
	p->v = x;
	p->dis = a;
	p->cost = b;
	p->next = vlist[y];
	vlist[y] = p;
}
void Dij_cost ()
{
	memset(visit,false,sizeof(visit));
	int i,j,k,tmin;
	ac *p;
	for ( i = 0; i <= n; i++ )
		w[i] = inf;
	w[n] = 0;
	for ( i = 0; i < n; i++ )
	{
		tmin = inf;
		for ( j = 1; j <= n; j++ )
		{
			if ( !visit[j] && w[j] < tmin )
			{
				k = j;
				tmin = w[j];
			}
		}
		if ( tmin == inf )
			break;
		visit[k] = true;
		p = vlist[k];
		while ( p != NULL )
		{
			if ( !visit[p->v] && w[p->v] > w[k]+p->cost )
				w[p->v] = w[k]+p->cost;
			p = p->next;
		}
	}
}
void Dij_dis ()
{
	memset(visit,false,sizeof(visit));
	int i,j,k,tmin;
	for ( i = 0; i <= n; i++ )
	{
		dis[i] = inf;
		money[i] = 0;
	}
	ac *p;
	dis[1] = 0;
	money[0] = 0;
	for ( i = 0; i < n; i++ )
	{
		tmin = inf;
		for ( j = 1; j <= n; j++ )
		{
			if ( !visit[j] && dis[j] < tmin )
			{
				k = j;
				tmin = dis[j];
			}
		}
		if ( tmin == inf )
			break;
		visit[k] = true;
		p = list[k];
		while ( p != NULL )
		{
			if ( !visit[p->v] && dis[p->v] > dis[k]+p->dis && money[k]+p->cost+w[p->v] <= m )
			{
				dis[p->v] = dis[k]+p->dis;
				money[p->v] = money[k]+p->cost;
			}
			p = p->next;
		}
	}
	if ( dis[n] == inf )
		printf("-1\n");
	else
		printf("%d\n",dis[n]);
}
int main ()
{
	int i,x,y,a,b;
	scanf("%d%d%d",&m,&n,&r);
	init();
	for ( i =0 ; i < r; i++ )
	{
		scanf("%d%d%d%d",&x,&y,&a,&b);
		insert(x,y,a,b);
	}
	Dij_cost();
	Dij_dis();
	return 0;
}