#include <iostream>
using namespace std;
bool c[110][110];
int n,m,t,ans,p;
void init()
{
	int i,j;
	for( i = 0; i < n; i++ )
		for ( j = 0; j < m; j++ )
			c[i][j] = false;
}
void dfs ( int x, int y )
{
	p++;
	c[x][y] = false;
	if ( x-1 >= 0 && c[x-1][y] == true )
		dfs(x-1,y);
	if ( x+1 < n && c[x+1][y] == true )
		dfs(x+1,y);
	if ( y-1 >= 0 && c[x][y-1] == true )
		dfs(x,y-1);
	if ( y+1 < m && c[x][y+1] == true )
		dfs(x,y+1);
}
int main ()
{
	cin>>n>>m>>t;
	init();
	int i,j,x,y;
	for ( i = 0; i < t; i++ )
	{
		cin>>x>>y;
		x--;
		y--;
		c[x][y] = true;
	}
	ans = 0;
	for ( i = 0; i < n; i++ )
	{
		for ( j= 0 ; j < m; j++ )
		{
			if ( c[i][j] == true )
			{
				p = 0;
				dfs(i,j);
				if ( p > ans )
					ans = p;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
