#include <iostream>
using namespace std;
int stack[60000100][2];
int begin,end;
int a[120][120];
int v[120][120];
int m,n;
int max = 1;
int visit ( int x, int y )
{
	if ( x-1 >= 0 && a[x-1][y] > a[x][y] )
		return 0;
	if ( y-1 >=0 && a[x][y-1] > a[x][y] )
		return 0;
	if ( x+1 < m && a[x+1][y] > a[x][y] )
		return 0;
	if ( y+1 < n && a[x][y+1] > a[x][y] )
		return 0;
	return 1;
}
void bfs ( int x, int y )
{
	begin = 0;
	end = 1;
	stack[0][0] = x;
	stack[0][1] = y;
	while ( begin < end )
	{
		x = stack[begin][0];
		y = stack[begin][1];
		begin++;
		if ( x-1>=0 && v[x][y]+1 > v[x-1][y] && a[x][y] > a[x-1][y] )
		{
			stack[end][0] = x-1;
			stack[end][1] = y;
			end++;
			v[x-1][y] = v[x][y]+1;
			if ( v[x][y] + 1 > max )
				max = v[x][y]+1;
		}
		if ( y-1>=0 && v[x][y]+1 > v[x][y-1] && a[x][y] > a[x][y-1] )
		{
			stack[end][0] = x;
			stack[end][1] = y-1;
			end++;
			v[x][y-1] = v[x][y]+1;
			if ( v[x][y] + 1 > max )
				max = v[x][y]+1;
		}
		if ( x+1<m && v[x][y]+1 > v[x+1][y] && a[x][y] > a[x+1][y] )
		{
			stack[end][0] = x+1;
			stack[end][1] = y;
			end++;
			v[x+1][y] = v[x][y]+1;
			if ( v[x][y] + 1 > max )
				max = v[x][y]+1;
		}
		if ( y+1<n && v[x][y]+1 > v[x][y+1] && a[x][y] > a[x][y+1] )
		{
			stack[end][0] = x;
			stack[end][1] = y+1;
			end++;
			v[x][y+1] = v[x][y] +1;
			if ( v[x][y] + 1 > max )
				max = v[x][y]+1;
		}
	}
}
int main ()
{
	scanf("%d%d",&m,&n);
	int i,j;
	for ( i = 0; i < m; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			scanf("%d",&a[i][j]);
			v[i][j] = 1;
		}
	}
	for ( i = 0; i < m; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			if ( visit(i,j) == 1 )
			{
				bfs(i,j);
			}
		}
	}
	cout<<max<<endl;
	return 0;
}