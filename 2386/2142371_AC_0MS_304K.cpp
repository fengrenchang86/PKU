#include <iostream>
using namespace std;
char a[120][120];
int m,n;
void dfs ( int x, int y )
{
	if ( x > 0 && a[x-1][y] == 'W' )//up
	{
		a[x-1][y] = '.';
		dfs(x-1,y);
	}
	if ( x < m && a[x+1][y] == 'W' )//down
	{
		a[x+1][y] = '.';
		dfs(x+1,y);
	}
	if ( y > 0 && a[x][y-1] == 'W' )
	{
		a[x][y-1] = '.';
		dfs(x,y-1);
	}
	if ( y < n && a[x][y+1] == 'W' )
	{
		a[x][y+1] = '.';
		dfs(x,y+1);
	}
	if ( x > 0 && y > 0 && a[x-1][y-1] == 'W' )
	{
		a[x-1][y-1] = '.';
		dfs(x-1,y-1);
	}
	if ( x < m && y < n && a[x+1][y+1] == 'W' )
	{
		a[x+1][y+1] = '.';
		dfs(x+1,y+1);
	}
	if ( x > 0 && y < n && a[x-1][y+1] == 'W' )
	{
		a[x-1][y+1] = '.';
		dfs(x-1,y+1);
	}
	if ( x < m && y > 0 && a[x+1][y-1] == 'W' )
	{
		a[x+1][y-1] = '.';
		dfs(x+1,y-1);
	}
}
int main ()
{
	int count = 0;
	int i,j;
	cin>>m>>n;
	for ( i = 0; i < m; i++ )
		cin>>a[i];
	for ( i = 0; i < m; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			if ( a[i][j] == 'W' )
			{
				count++;
				a[i][j] = '.';
				dfs(i,j);
			}
		}
	}
	cout<<count<<endl;
	return 0;
}