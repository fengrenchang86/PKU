#include <iostream>
#include <string.h>
using namespace std;
char a[120][120];
void dfs ( int x, int y, int ex, int ey )//x and y 表示当前坐标， ex，ey表示结束坐标
{
	a[x][y] = '*';
	if ( a[x-1][y] == '@' )
		dfs(x-1,y,ex,ey);
	if ( a[x-1][y-1] == '@' )
		dfs(x-1,y,ex,ey);
	if ( a[x-1][y+1] == '@' )
		dfs(x-1,y,ex,ey);
	if ( a[x][y-1] == '@' )
		dfs(x,y-1,ex,ey);
	if ( a[x][y+1] == '@' )
		dfs(x,y+1,ex,ey);
	if ( a[x+1][y-1] == '@' )
		dfs(x+1,y-1,ex,ey);
	if ( a[x+1][y] == '@' )
		dfs(x+1,y,ex,ey);
	if ( a[x+1][y+1] == '@' )
		dfs(x+1,y+1,ex,ey);
}
int main ()
{
	int x,y;
	int i,j;
	int count;
	char ch[200];
	while ( scanf("%d%d",&x,&y) && !(x==0&&y==0) )
	{
		count = 0;
		for ( i = 0; i <= x+1; i++ )
			for ( j = 0; j <= y+1; j++ )
				a[i][j] = '*';
		for ( j = 0; j < x; j++ )
		{
			scanf("%s",ch);
			for ( i = 0; i < y; i++ )
				a[j+1][i+1] = ch[i];
		}
		for ( i = 1; i<=x; i++ )
		{
			for ( j = 1; j <= y; j++ )
			{
				if ( a[i][j] == '@' )
				{
					count++;
					dfs(i,j,x,y);
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}