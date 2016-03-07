#include <iostream>
using namespace std;
const int inf = 2000000000;
int c[200][200];
bool visit[200];
int w[200];
int f,m; 
void input()
{
	int i,j;
	int x,y,z;
	scanf("%d%d",&f,&m);
	for ( i = 0; i <= m; i++ )
	{
		visit[i] = false;
		w[i] = inf;
		for ( j = 0; j <= m; j++ )
			c[i][j] = inf;
	}
	for ( i = 0; i < f; i++ )
	{
		scanf("%d",&j);
		w[j] = 0;
	}
	while ( cin>>x>>y>>z )
	{
		if ( c[x][y] > z )
		{
			c[x][y] = c[y][x] = z;
		}
	}
}
void dij ()
{
	int i,j,k,tmin;
	for ( i = 0; i < m; i++ )
	{
		tmin = inf;
		for ( j = 1; j <= m; j++ )
		{
			if ( visit[j] == false && w[j] < tmin )
			{
				k = j;
				tmin = w[j];
			}
		}
		if ( tmin == inf )
			break;
		visit[k] = true;
		for ( j = 1; j <= m; j++ )
		{
			if ( visit[j] == false && c[k][j] != inf && w[j] > w[k]+c[j][k] )
				w[j] = w[k]+c[j][k];
		}
	}
	k = 1;
	for ( i = 2; i <= m; i++ )
	{
		if ( w[i] > w[k] )
			k = i;
	}
	printf("%d\n",k);
}
int main ()
{
	input();
	dij();
	return 0;
}