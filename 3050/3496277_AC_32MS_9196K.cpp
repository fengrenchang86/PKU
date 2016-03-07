
//#pragma warning(disable:4786)
#include <iostream>
//#include <map>
using namespace std;
bool visit[6][6][200100];
bool v[2000100];
int a[6][6];
int ans;
void init ()
{
	memset(visit,false,sizeof(visit));
	memset(v,false,sizeof(v));
	int i,j;
	for ( i = 0; i < 5; i++ )
	{
		for ( j = 0; j < 5; j++ )
		{
			scanf("%d",&a[i][j]);
			if ( a[i][j] == 0 )
				a[i][j] = 10;
		}
	}
	ans = 0;
}
void dfs ( int x, int y, int lay, int k )
{
	k *= 11;
	if ( lay == 5 )
	{
		if ( x > 0 && v[k+a[x-1][y]] == false )
		{
			v[k+a[x-1][y]] = true;
	//		printf("%d\n",k+a[x-1][y]);
			ans++;
		}
		if ( x < 4 && v[k+a[x+1][y]] == false )
		{
			v[k+a[x+1][y]] = true;
	//		printf("%d\n",k+a[x+1][y]);
			ans++;
		}
		if ( y > 0 && v[k+a[x][y-1]] == false )
		{
			v[k+a[x][y-1]] = true;
	//		printf("%d\n",k+a[x][y-1]);
			ans++;
		}
		if ( y < 4 && v[k+a[x][y+1]] == false )
		{
			v[k+a[x][y+1]] = true;
	//		printf("%d\n",k+a[x][y+1]);
			ans++;
		}
	}
	else
	{
		if ( x > 0 && visit[x-1][y][k+a[x-1][y]] == false )
		{
			visit[x-1][y][k+a[x-1][y]] = true;
			dfs(x-1,y,lay+1,k+a[x-1][y]);
		}
		if ( x < 4 && visit[x+1][y][k+a[x+1][y]] == false )
		{
			visit[x+1][y][k+a[x+1][y]] = true;
			dfs(x+1,y,lay+1,k+a[x+1][y]);
		}
		if ( y > 0 && visit[x][y-1][k+a[x][y-1]] == false )
		{
			visit[x][y-1][k+a[x][y-1]] = true;
			dfs(x,y-1,lay+1,k+a[x][y-1]);
		}
		if ( y < 4 && visit[x][y+1][k+a[x][y+1]] == false )
		{
			visit[x][y+1][k+a[x][y+1]] = true;
			dfs(x,y+1,lay+1,k+a[x][y+1]);
		}
	}
}
int main ()
{
	int i,j;
//	while ( 1 )
	{
		init();
		for ( i = 0; i < 5; i++ )
		{
			for ( j = 0; j < 5; j++ )
			{
				dfs(i,j,1,a[i][j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}