#include <iostream>
using namespace std;
char a[30][30];
int row,col,x,y,ans;
void dfs ( int i, int j )
{
	if ( i > 0 && a[i-1][j] == '.' || i == 0)
		ans++;
	if ( j+1 < col && a[i][j+1] == '.' || j+1 == col)
		ans++;
	if ( i+1 < row && a[i+1][j] == '.' || i+1 == row)
		ans++;
	if ( j > 0 && a[i][j-1] == '.' || j== 0)
		ans++;
	a[i][j] = 'x';
	if ( i > 0 && a[i-1][j] == 'X' )
		dfs(i-1,j);
	if ( j > 0 && a[i][j-1] == 'X' )
		dfs(i,j-1);
	if ( i+1 < row && a[i+1][j] == 'X' )
		dfs(i+1,j);
	if ( j+1 < col && a[i][j+1] == 'X' )
		dfs(i,j+1);
	if ( i > 0 && j > 0 && a[i-1][j-1] == 'X' )
		dfs(i-1,j-1);
	if ( i > 0 && j+1<col && a[i-1][j+1] == 'X' )
		dfs(i-1,j+1);
	if ( i+1 < row && j > 0 && a[i+1][j-1] == 'X')
		dfs(i+1,j-1);
	if ( i+1 < row && j+1 < col && a[i+1][j+1] == 'X' )
		dfs(i+1,j+1);
}
int main ()
{
	int i;
	while ( cin>>row>>col>>x>>y )
	{
		if ( row+col+x+y==0)
			break;
		x--;
		y--;
		for ( i = 0; i < row; i++ )
			cin>>a[i];
		ans = 0;
		dfs(x,y);
		cout<<ans<<endl;
	}
	return 0;
}