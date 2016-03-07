#include <iostream>
using namespace std;
char a[30][30];
int m,n;
int count;
void dfs( int x, int y )
{
	if ( x > 0 )
	if ( a[x-1][y] == '.' )
	{
		a[x-1][y] = '*';
		count++;
		dfs(x-1,y);
	}
	if ( x < m-1 )
	if ( a[x+1][y] == '.' )
	{
		a[x+1][y] = '*';
		count++;
		dfs(x+1,y);
	}
	if ( y > 0 )
	if ( a[x][y-1] == '.' )
	{
		a[x][y-1] = '*';
		count++;
		dfs(x,y-1);
	}
	if ( y < n-1 )
	if ( a[x][y+1] == '.' )
	{
		a[x][y+1] = '*';
		count++;
		dfs(x,y+1);
	}
}
int main ()
{
	int i,j;
	char ch[30];
	while ( scanf("%d%d",&n,&m) && !(m==0&&n==0) )
	{
		memset(ch,'*',sizeof(ch));
		for ( i = 0; i < m; i++ )
			scanf("%s",a[i]);
		for ( i = 0; i < m; i++ )
		{
			for ( j =0; j < n; j++ )
				if ( a[i][j] == '@' )
					break;
			if ( a[i][j] == '@' )
				break;
		}
		count = 1;
		dfs(i,j);
		cout<<count<<endl;
	}
	return 0;
}