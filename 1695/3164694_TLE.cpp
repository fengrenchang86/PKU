#include <iostream>
using namespace std;
bool visit[40];
int c[40][40][40];
int d[40][40];
int n,minTime;
void init ()
{
	memset(visit,false,sizeof(visit));
	int i,j,k;
	for ( i = 1; i < n; i++ )
	{
		for ( j = i+1; j <= n; j++ )
		{
			scanf("%d",&d[i][j]);
			d[j][i] = d[i][j];
		}
	}
	for ( i = 1; i <= n; i++ )
		for ( j = 1; j <= n; j++ )
			for ( k = 1; k <= n; k++ )
				c[i][j][k] = 2000000000;
	minTime = 2000000000;
}
void updata ( int &x, int &y, int &z )
{
	int k;
	if ( x > y )
	{
		k = x;
		x = y;
		y = k;
	}
	if ( z >= x && z < y )
	{
		k = z;
		z = y;
		y = k;
	}
	else if ( z < x )
	{
		k = z;
		z = y;
		y = x;
		x = k;
	}
}
void dfs ( int x, int y, int z, int time )
{
	if ( time >= minTime )
		return;
	updata(x,y,z);
	if ( z == n )
	{
		if ( time < minTime )
			minTime = time;
		return;
	}
	if ( c[x][y][z] <= time )
		return;
	c[x][y][z] = time;
	int i;
	for ( i = 1; i <= z+1; i++ )
	{
		if ( x != i )
			dfs(i,y,z,d[x][i]+time);
		if ( y != i )
			dfs(x,i,z,d[i][y]+time);
		if ( z != i )
			dfs(x,y,i,d[i][z]+time);
	}
}
int main ()
{
	int tc;
	cin>>tc;
	while ( tc-- )
	{
		cin>>n;
		init();
		dfs(1,1,1,0);
		cout<<minTime<<endl;
	}
	return 0;
}