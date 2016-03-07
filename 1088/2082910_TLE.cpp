
#include <iostream>
using namespace std;
struct ac
{
	int path;
	int high;
	ac()
	{
		path = 0;
	}
}a[102][102];
int m,n;
int max = 1;
void dfs ( int x, int y, int lay )
{
	if ( lay > max )
		max = lay;
	{
		if ( a[x][y].high > a[x-1][y].high  )
		{
			if ( lay+1 > a[x-1][y].path )
			{
				a[x-1][y].path = lay+1;
				dfs(x-1,y,lay+1);
			}
		}
	}
	{
		if ( a[x][y].high > a[x][y+1].high  )
		{
			if ( lay+1 > a[x][y+1].path )
			{
				a[x][y+1].path = lay+1;
				dfs(x,y+1,lay+1);
			}
		}
	}
	{
		if ( a[x][y].high > a[x+1][y].high  )
		{
			if ( lay+1 > a[x+1][y].path )
			{
				a[x+1][y].path = lay+1;
				dfs(x+1,y,lay+1);
			}
		}
	}
	{
		if ( a[x][y].high > a[x][y-1].high  )
		{
			if ( lay+1 > a[x][y-1].path )
			{
				a[x][y-1].path = lay+1;
				dfs(x,y-1,lay+1);
			}
		}
	}
}
int main ()
{
	int ex,ey;
	int i,j;
	int c;
	scanf("%d%d",&m,&n);
	for ( i = 0; i <= n+1; i++ )
		a[0][i].high = a[m+1][i].high = 20000;
	for ( i = 0; i <= m+1; i++ )
		a[i][0].high = a[i][n+1].high = 20000;
	for ( i = 1; i <= m; i++ )
		for ( j = 1; j <= n; j++ )
			scanf("%d",&a[i][j].high);
	while ( 1 )
	{
		c = -1;
		for ( i = 1; i <= m; i++ )
		{
			for ( j = 1; j <= n; j++ )
			{
				if ( a[i][j].path == 0 && a[i][j].high > c)
				{
					c = a[i][j].high;
					ex = i;
					ey = j;
				}
			}
		}
		if ( c == -1 )
			break;
		a[ex][ey].path = 1;
		dfs(ex,ey,1);
	}
	cout<<max<<endl;
	return 0;
}
