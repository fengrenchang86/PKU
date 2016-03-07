
#include <iostream>
using namespace std;
struct ac
{
	int path;
	int high;
	int rout[4];
	bool down;
	ac()
	{
		down = false;
		high = 0;
		path = 0;
		int i;
		for ( i = 0; i < 4; i++ )
			rout[i] = 1;
	}
}a[101][101];
int m,n;
int save[10002][2];
int l[101][101] ;
int end = 0;
int max = 1;
void dfs ( int x, int y, int lay )
{
	if ( lay > max )
		max = lay;
	if ( x >= 1 )
	{
		if ( a[x][y].high < a[x-1][y].high  )
		{
			if ( lay+1 > a[x-1][y].path )
			{
				a[x-1][y].path = lay+1;
				dfs(x-1,y,lay+1);
			}
		}
	}
	if ( y < n-1 )
	{
		if ( a[x][y].high < a[x][y+1].high  )
		{
			if ( lay+1 > a[x][y+1].path )
			{
				a[x][y+1].path = lay+1;
				dfs(x,y+1,lay+1);
			}
		}
	}
	if ( x < m-1 )
	{
		if ( a[x][y].high < a[x+1][y].high  )
		{
			if ( lay+1 > a[x+1][y].path )
			{
				a[x+1][y].path = lay+1;
				dfs(x+1,y,lay+1);
			}
		}
	}
	if ( y >= 1 )
	{
		if ( a[x][y].high < a[x][y-1].high  )
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
	memset(l,-1,sizeof(l));
	int i,j,k;
	int c;
	scanf("%d%d",&m,&n);
	for ( i = 0; i < m; i++ )
	{
		a[i][0].rout[3] = -1;
		a[i][n-1].rout[1] = -1;
	}
	for ( i = 0; i < n; i++ )
	{
		a[0][i].rout[0] = -1;
		a[m-1][i].rout[2] = -1;
	}
	for ( i = 0; i < m; i++ )
		for ( j = 0; j < n; j++ )
			scanf("%d",&a[i][j].high);
/*	for ( i = 0; i < m; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			c = 0;
			if ( a[i][j].rout[0] != -1 )
			{
				if ( a[i][j].high <= a[i-1][j].high )
				{
					a[i][j].rout[0] = -1;
					c++;
				}
			}
			else
				c++;
			if ( a[i][j].rout[1] != -1 )
			{
				if ( a[i][j].high <= a[i][j+1].high )
				{
					a[i][j].rout[1] = -1;
					c++;
				}
			}
			else
				c++;
			if ( a[i][j].rout[2] != -1 )
			{
				if ( a[i][j].high <= a[i+1][j].high )
				{
					a[i][j].rout[2] = -1;
					c++;
				}
			}
			else
				c++;
			if ( a[i][j].rout[3] != -1 )
			{
				if ( a[i][j].high <= a[i][j-1].high )
				{
					a[i][j].rout[3] = -1;
					c++;
				}
			}
			else
				c++;
			if ( c == 4 )
			{
				a[i][j].down = true;
				save[end][0] = i;
				save[end++][1] = j;
			}
		}
	}*/
	for ( i = 0; i < m; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			if ( a[i][j].path == 0 )
				dfs(i,j,1);
		}
	}
	cout<<max<<endl;
	return 0;
} 