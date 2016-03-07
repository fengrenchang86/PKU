
#include <iostream>
using namespace std;
const int inf = 2147483647;
bool visit[1200];
int dis[1200];
int c[1200][1200];
int n;

int dij ( int begin )
{
	memset(visit,false,sizeof(visit));
	int i,j,k,tmin;
	for ( i = 0; i <= n; i++ )
		dis[i] = inf;
	dis[begin] = 0;
	for ( i = 0; i < n; i++ )
	{
		tmin = inf;
		for ( j = 1; j <= n; j++ )
		{
			if ( visit[j] == false && dis[j] < tmin )
			{
				tmin = dis[j];
				k = j;
			}
		}
		if ( tmin == inf )
			break;
		visit[k] = true;
		for ( j = 1; j <= n; j++ )
		{
			if ( visit[j] == false && c[k][j] != inf && dis[j] > dis[k]+c[k][j] )
				dis[j] = dis[k]+c[k][j];
		}
	}
	tmin = dis[1];
	for ( i = 2; i <= n; i++ )
	{
		if ( dis[i] > tmin )
			tmin = dis[i];
	}
	return tmin;
}
void input ()
{
	int i,j,m,x,y;
	for ( i = 0; i <= n; i++ )
		for ( j= 0; j <= n; j++ )
			c[i][j] = inf;
	for ( i = 1; i <= n; i++ )
	{
		cin>>m;
		for ( j = 1; j <= m; j++ )
		{
			cin>>x;
			c[i][x] = 1;
		}
	}
}
int main ()
{
	int i,k,x,y;
	while ( cin>>n && n)
	{
		input();
		y = inf;
		for ( i = 1; i <= n; i++ )
		{
			k = dij(i);
			if ( k == -1 )
				continue;
			if ( k < y )
			{
				y = k;
				x = i;
			}
		}
		if ( y == inf )
			printf("impossible\n");
		else
			printf("%d\n%d\n",y,x);
	}
	return 0;
}
