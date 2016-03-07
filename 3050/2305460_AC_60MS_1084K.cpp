#include <iostream>
using namespace std;
bool v[1000000];
int a[5][5];
int count = 0;
void dfs ( int x, int y, int lay, int sum )
{
	if ( lay == 6 )
	{
		if ( v[sum] == false )
		{
			v[sum] = true;
			count++;
		}
		return;
	}
	if ( x-1 >= 0 )
		dfs ( x-1, y, lay+1, sum*10+a[x-1][y]);
	if ( y-1 >= 0 )
		dfs ( x, y-1, lay+1, sum*10+a[x][y-1]);
	if ( x+1 < 5 )
		dfs ( x+1, y, lay+1, sum*10+a[x+1][y]);
	if ( y+1 < 5 )
		dfs ( x, y+1, lay+1, sum*10+a[x][y+1]);
}
int main ()
{
	int i,j;
	for ( i = 0; i < 1000000; i++ )
		v[i] = false;
	for ( i = 0; i < 5; i++ )
		for ( j = 0; j < 5; j++ )
			scanf("%d",&a[i][j]);
	for ( i = 0; i < 5; i++ )
	{
		for ( j = 0; j < 5; j++ )
			dfs(i,j,0,0);
	}
	cout<<count<<endl;
	return 0;
}