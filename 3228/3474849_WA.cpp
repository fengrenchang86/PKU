#include <iostream>
using namespace std;
const int N=211;
const int inf = 2000000000;
int storage[N],storehouse[N];
int path[N];
bool visit[N];
int w[N];
int c[N][N];
int f[N][N];
int n,m,q;
int max ( int x, int y )
{
	return x>y?x:y;
}
void maininit ()
{
	int i,j;
	for ( i = 0; i < N; i++ )
	{
		for ( j = 0; j < N; j++ )
		{
			c[i][j] = -1;
			f[i][j] = inf;
		}
	}
	q = 0;
}
void input ()
{
	int i,x,y,z;
	for ( i = 1; i <= n; i++ )
		scanf("%d",&storage[i]);
	for ( i = 1; i <= n; i++ )
		scanf("%d",&storehouse[i]);
	scanf("%d",&m);
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d%d",&x,&y,&z);
		if ( c[x][y] == -1 || c[x][y] > z )
			c[x][y] = c[y][x] = z;
	}
}
void init( )
{
	int i;
	for ( i = 1; i <= n; i++ )
	{
		f[0][i] = storage[i];
		f[i][0] = 0;
		f[i][n+1] = storehouse[i];
		f[n+1][i] = 0;
		if ( storage[i] != 0 )
		{
			c[0][i] = 0;
			c[i][0] = 0;
		}
		if ( storehouse[i] != 0 )
		{
			c[i][n+1] = 0;
			c[n+1][i] = 0;
		}
	}
	w[n+1] = inf;
}
int MaxFlow ( )
{
	int i,j,k,tmin,t;
	memset(visit,false,sizeof(visit));
	for ( i = 0; i <= n+1; i++ )
	{
		w[i] = inf;
		path[i] = -1;
	}
	w[0] = 0;
	for ( i = 0; i <= n+1; i++ )
	{
		tmin = inf;
		for ( j = 0; j <= n+1; j++ )
		{
			if ( !visit[j] && w[j] < tmin )
			{
				tmin = w[j];
				k = j;
			}
		}
		visit[k] = true;
		if ( k == n+1 || tmin == inf )
			break;
		for ( j = 0; j <= n+1; j++ )
		{
			if ( c[j][k] == -1 )
				continue;
			t = max(w[k],c[k][j]);
			if ( !visit[j] && w[j] > t && f[k][j] > 0 )
			{
				w[j] = t;
				path[j] = k;
			}
		}
	}
	k = path[n+1];
	tmin = inf;
	if ( k == -1 )
		return 0;
	k = n+1;
	while ( path[k] != -1 )
	{
		if ( f[path[k]][k] < tmin )
			tmin = f[path[k]][k];
		k = path[k];
	}
	k = n+1;
	while ( path[k] != -1 )
	{
		f[path[k]][k] -= tmin;
		f[k][path[k]] += tmin;
		k = path[k];
	}
	q += tmin;
	return w[n+1];
}

void solve ( )
{
	int k=1;
	int ans = 0;
	int i,x=0,y=0;
	for ( i = 1; i <= n; i++ )
		x += storage[i];
	while ( k != 0 )
	{
		k = MaxFlow();
		if ( k > ans )
			ans = k;
	}
	if ( q == x )
		printf("%d\n",ans);
	else
		printf("No Solution\n");
}
int main ()
{
	while ( scanf("%d",&n) != EOF )
	{
		if ( n == 0 )
			break;
		maininit();
		input();
		init();
		solve();
	}
	return 0;
}