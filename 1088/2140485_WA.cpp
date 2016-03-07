#include <iostream>
using namespace std;
int a[120][120];
int path[120][120];
int v[120][2];
int end = 0;
int max = 0;
bool flag = false;
void find ( int x, int y, int lay )
{
	if ( lay > max )
		max = lay;
	if ( a[x][y] < a[x-1][y] && lay+1 > path[x-1][y] )
	{
		path[x-1][y] = lay+1;
		find(x-1,y,lay+1);
	}
	if ( a[x][y] < a[x+1][y] && lay+1 > path[x+1][y] )
	{
		path[x+1][y] = lay + 1;
		find(x+1,y,lay+1);
	}
	if ( a[x][y] < a[x][y-1] && lay+1 > path[x][y-1] )
	{
		path[x][y-1] = lay + 1 ;
		find ( x,y-1,lay+1);
	}
	if ( a[x][y] < a[x][y+1] && lay + 1 > path[x][y+1] )
	{
		path[x][y+1] = lay+1;
		find(x,y+1,lay+1);
	}
}
int main ()
{
	int i,j;
	for ( i = 0; i < 120; i++ )
	{
		for ( j = 0; j < 120; j++ )
		{
			a[i][j] = 0;
			path[i][j] = 0;
		}
		v[i][0] = v[i][1] = 0;
	}
	int m,n;
	cin>>m>>n;
	for ( i = 0; i <= m+1; i++ )
		a[i][0] = a[i][n+1] = 0;
	for ( j = 0; j <= n+1; j++ )
		a[0][j] = a[m+1][j] =0;
	for ( i = 1; i <= m; i++ )
	{
		for ( j = 1; j <= n; j++ )
			cin>>a[i][j];
	}
	for ( i = 1; i <= m; i++ )
	{
		for ( j = 1; j <= n; j++ )
		{
			if ( j == 1 || j > 1 && a[i][j-1] > a[i][j] )
			{
				if ( i == 1 || i > 1 && a[i-1][j] > a[i][j] )
				{
					if ( j == n || j < n && a[i][j+1] > a[i][j] )
					{
						if ( i == m || i < m && a[i+1][j] > a[i][j] )
						{
							v[end][0] = i;
							v[end][1] = j;
							end++;
						}
					}
				}
			}
		}
	}
	for ( i = 0; i < end; i++ )
		find(v[i][0],v[i][1],1);
	cout<<max<<endl;
	return 0;
}