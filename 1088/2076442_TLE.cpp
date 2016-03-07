#include <iostream>
using namespace std;
int X, Y;
int a[120][120];
int b[120][120];
int max = 1;
void bfs ( int x, int y, int lay )
{
	if ( lay > max )
	{
		max = lay;
		a[X][Y] = max;
	}
	if ( a[x-1][y] < a[x][y] )
	{
			b[x-1][y] = 1;
			bfs(x-1,y,lay+1);
	}
	if ( a[x][y-1] < a[x][y] )
	{
			b[x][y-1] = 1;
			bfs ( x, y-1 ,lay+1);
	}
	if ( a[x][y+1] < a[x][y] )
	{
			b[x][y+1] = 1;
			bfs ( x, y+1 ,lay+1);
	}
	if ( a[x+1][y] < a[x][y] ) 
	{
			b[x+1][y] = 1;
			bfs ( x+1, y ,lay+1);
	}
}
int main ()
{
	int m,n,i,j;
	cin>>m>>n;
	for ( i = 1; i <= m; i++ )
		for ( j = 1; j<=n; j++ )
			b[i][j] = 0;
	for ( i = 1; i <= m; i++ )
		a[i][0] = a[i][n+1] = 9999999;
	for ( j = 1; j <= n; j++ )
		a[0][j] = a[m+1][j] = 9999999;
	for ( i = 1; i <= m; i++ )
		for ( j = 1;  j<= n; j++ )
			cin>>a[i][j];	
	for ( i = 1; i <= m; i++ )
	{
		for ( j = 1; j <= n ;j++ )
		{
			X =i;
			Y = j;
			if ( b[i][j] == 0 )
			{
				bfs(i,j,1);
			}
		}
	}
	cout<<max<<endl;
	return 0;
}