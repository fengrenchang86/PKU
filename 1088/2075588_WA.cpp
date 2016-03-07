#include <iostream>
using namespace std;

int a[120][120];
int max = 0;
void bfs ( int x, int y, int lay )
{
	if ( lay > max )
		max = lay;
	if ( a[x-1][y] < a[x][y] )
		bfs(x-1,y,lay+1);
	if ( a[x-1][y+1] < a[x][y] )
		bfs(x-1,y+1,lay+1);
	if ( a[x-1][y-1] < a[x][y] )
		bfs(x-1,y-1,lay+1);
	if ( a[x][y-1] < a[x][y] )
		bfs ( x, y-1 ,lay+1);
	if ( a[x][y+1] < a[x][y] )
		bfs ( x, y+1 ,lay+1);
	if ( a[x+1][y-1] < a[x][y] )
		bfs ( x+1, y-1,lay+1 );
	if ( a[x+1][y] < a[x][y] ) 
		bfs ( x+1, y ,lay+1);
	if ( a[x+1][y+1] < a[x][y] )
		bfs ( x+1, y+1,lay+1 );
}
int main ()
{
	int m,n,i,j;
	cin>>m>>n;
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
			bfs(i,j,0);
		}
	}
		cout<<max<<endl;
	return 0;
}