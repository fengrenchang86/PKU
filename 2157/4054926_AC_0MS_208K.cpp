#include <iostream>
using namespace std;
char a[30][30];
bool visit[30][30];
int key[6];
int door[6];
int x[6];
int y[6];
int n,m,bx,by;
bool acm;
void input()
{
	int i,j;
	for ( i = 0; i < n; i++ )
		scanf(" %s",a[i]);
	for ( i = 0; i < 5; i++ )
	{
		key[i] = 0;
		door[i] = 0;
	}
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < m; j++ )
		{
			visit[i][j] = false;
			if ( a[i][j] >= 'a' && a[i][j] <= 'e' )
				key[a[i][j]-'a']++;
			else if ( a[i][j] >= 'A' && a[i][j] <= 'E' )
			{
				x[a[i][j]-'A'] = i;
				y[a[i][j]-'A'] = j;
			}
			else if ( a[i][j] == 'S' )
			{
				bx = i;
				by = j;
			}
		}
	}
}
void dfs ( int x, int y )
{
	visit[x][y] = true;
	if ( a[x][y] == 'G' || acm )
	{
		acm = true;
		return;
	}
	if ( a[x][y] >= 'a' && a[x][y] <= 'e' )
		key[a[x][y]-'a']--;
	else if ( a[x][y] >= 'A' && a[x][y] <= 'E' )
	{
		door[a[x][y]-'A'] = 1;
		return;
	}
	a[x][y] = '.';
	if ( x-1 >= 0 && a[x-1][y] != 'X' && !visit[x-1][y] )
		dfs(x-1,y);
	if ( x+1 < n && a[x+1][y] != 'X' && !visit[x+1][y] )
		dfs(x+1,y);
	if ( y-1 >= 0 && a[x][y-1] != 'X' && !visit[x][y-1] )
		dfs(x,y-1);
	if ( y+1 < m && a[x][y+1] != 'X' && !visit[x][y+1] )
		dfs(x,y+1);
}
void solve ( )
{
	acm = false;
	int i,k=1;
	dfs(bx,by);
	while ( k==1 )
	{
		k = 0;
		for ( i = 0; i < 5; i++ )
		{
			if ( door[i] == 1 && key[i] == 0 )
			{
				k = 1;
				a[x[i]][y[i]] = '.';
				dfs(x[i],y[i]);
				door[i] = 0;
			}
		}
	}
	if ( acm )
		printf("YES\n");
	else
		printf("NO\n");
}
int main ()
{
	while ( scanf("%d%d",&n,&m) != EOF )
	{
		if ( n == 0 && m == 0 )
			break;
		input();
		solve();
	}
	return 0;
}