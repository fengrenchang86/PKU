#include <iostream>
using namespace std;
bool c[420][420];
bool visit[420];
int w[420];
int path[420];
int n,m,N;
void init ()
{
	int i,j,k,d;
	N=n+m+1;
	for ( i = 0; i <= N; i++ )
	{
		for ( j = 0; j <= N; j++ )
			c[i][j] = false;
	}
	for ( i = 1; i <= n; i++ )
	{
		c[0][i] = true;
		scanf("%d",&k);
		for ( j = 1; j <= k; j++ )
		{
			scanf("%d",&d);
			c[i][d+n] = true;
			c[d+n][N] = true;
		}
	}
}
void run ( int x )
{
	if ( x == 0 )
		return;
	c[path[x]][x] = false;
	c[x][path[x]] = true;
	run(path[x]);
}
int dij ()
{
	memset(visit,false,sizeof(visit));
	int i,j,k,min;
	for ( i = 1; i <= N; i++ )
		w[i] = 2000000000;
	w[0] = 0;
	for ( i = 0; i <= N; i++ )
	{
		min = 2000000000;
		for ( j = 0; j <= N;j++ )
		{
			if ( w[j] < min && visit[j] == false )
			{
				k = j;
				min = w[j];
			}
		}
		if ( min == 2000000000 )
			break;
		visit[k] = true;
		for ( j = 0; j <= N; j++ )
		{
			if ( visit[j] == false && w[j] > w[k]+1 && c[k][j] == true )
			{
				w[j] = w[k]+1;
				path[j] = k;
			}
		}
	}
	if ( w[N] == 2000000000 )
		return 0;
	run(N);
	return 1;
}
int main ()
{
	int t;
	while ( scanf("%d%d",&n,&m)!= EOF )
	{
		t = 0;
		init();
		while ( dij() )
		{
			t++;
		}
		cout<<t<<endl;
	}
	return 0;
}