#include <iostream>
using namespace std;
const int inf = 2000000000;
int c[100][100];
int visit[100];
int w[100];
int next[100];
int n,m;
void input()
{
	int i,j,x,y,z;
	scanf("%d",&m);
	for ( i = 1; i <= n; i++ )
	{
		w[i] = inf;
		visit[i] =false;
		for ( j = 1; j <= n; j++ )
		{
			c[i][j] = -1;
		}
	}
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d%d",&x,&y,&z);
		if ( c[x][y] == -1 )
			c[x][y] = c[y][x] = z;
		else if ( c[x][y] > z )
			c[x][y] = c[y][x] = z;
	}
}
void solve ()
{
	visit[1] = true;
	int i,j,k,tmin,ans=0;
	for ( i = 2; i <= n; i++ )
	{
		if ( c[1][i] != -1 )
		{
			w[i] = c[1][i];
			next[i] = 1;
		}
	}
	for ( i = 1; i < n; i++ )
	{
		tmin = inf;
		for ( j = 2; j <= n; j++ )
		{
			if ( !visit[j] && w[j] < tmin )
			{
				tmin = w[j];
				k = j;
			}
		}
		ans += c[next[k]][k];
		visit[k] = true;
		for ( j = 2; j <= n; j++ )
		{
			if ( !visit[j] && c[k][j] != -1 && w[j] > c[k][j] )
			{
				w[j] = c[k][j];
				next[j] = k;
			}
		}
	}
	printf("%d\n",ans);
}
int main ()
{
	while ( scanf("%d",&n) != EOF )
	{
		if ( n == 0 )
			break;
		input();
		solve();
	}
	return 0;
}