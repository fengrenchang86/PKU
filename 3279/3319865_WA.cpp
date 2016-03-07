#include <iostream>
using namespace std;
const int inf = 2000000000;
int a[20][20];
int v[20][20];
int b[20][20];
int p[20][20];
int n,m,ans;
void input ()
{
	int i,j;
	ans = inf;
	for ( i = 1; i <= n; i++ )
	{
		for ( j =1 ; j <= m; j++ )
		{
			scanf("%d",&a[i][j]);
			v[i][j] = 0;
		}
	}
}
bool match( )
{
	int i,j;
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= m; j++ )
		{
			if ( a[i][j] != v[i][j] )
				return false;
		}
	}
	return true;
}
void update ( int x, int y )
{
	v[x][y] = !v[x][y];
	if ( x >= 2 )
		v[x-1][y] = !v[x-1][y];
	if ( x < n )
		v[x+1][y] = !v[x+1][y];
	if ( y >= 2 )
		v[x][y-1] = !v[x][y-1];
	if ( y < m )
		v[x][y+1] = !v[x][y+1];
}
void dfs ( int lay, int num )
{
	if ( lay <= m )
	{
		p[1][lay] = 0;
		dfs(lay+1,num);
		p[1][lay] = 1;
		update(1,lay);
		dfs(lay+1,num+1);
		p[1][lay] = 0;
		update(1,lay);
	}
	else
	{
		memset(p,0,sizeof(p));
		int i,j,k=0;
		for ( i = 2; i <= n; i++ )
		{
			for ( j =1; j <= m; j++ )
			{
				if ( a[i-1][j] != v[i-1][j] )
				{
					p[i][j] = 1;
					update(i,j);
					k++;
				}
			}
		}
		if ( match() == true )
		{
			if ( ans > k )
			{
				ans = k;
				for ( i =1; i <= n; i++ )
				{
					for ( j =1 ;j <= m; j++ )
						b[i][j] = p[i][j];
				}
			}
		}
	}
}
int main ()
{
	int i,j;
	while ( scanf("%d%d",&n,&m) != EOF )
	{
		input();
		dfs(1,0);
		if ( ans == inf )
			cout<<"IMPOSSIBLE"<<endl;
		else
		{
			cout<<ans<<endl;
			for ( i = 1; i <= n; i++ )
			{
				for ( j = 1; j <= m; j++ )
					printf("%d ",b[i][j]);
				printf("\n");
			}
		}
	}
	return 0;
}