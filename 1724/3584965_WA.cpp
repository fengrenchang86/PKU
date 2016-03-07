#include <iostream>
#include <queue>
using namespace std;
const int inf = 2000000000;
int c[110][110];
int cost[110][110];
int dis[110];
int money[110];
int w[110];
bool visit[110];
int n,m,r;
void init ()
{
	int i,j;
	for ( i= 0 ; i <= n; i++ )
	{
		for ( j=0; j <= n; j++ )
		{
			c[i][j] = cost[i][j] = inf;
		}
	}
}
void Dij_cost ()
{
	memset(visit,false,sizeof(visit));
	int i,j,k,tmin;
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
		for ( j = 1; j <= n; j++ )
		{
			if ( !visit[j] && c[j][k] != inf && w[j] > w[k]+cost[j][k] )
				w[j] = w[k]+cost[j][k];
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
		for ( j = 1; j <= n; j++ )
		{
			if ( !visit[j] && c[k][j] != inf && dis[j] > dis[k]+c[k][j] && money[k]+cost[k][j]+w[j] <= m )
			{
				dis[j] = dis[k]+c[k][j];
				money[j] = money[k]+cost[k][j];
			}
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
		c[x][y] = a;
		cost[x][y] = b;
	}
	Dij_cost();
	Dij_dis();
	return 0;
}