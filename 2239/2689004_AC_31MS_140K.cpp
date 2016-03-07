#include <iostream>
using namespace std;
bool c[310][100];
int xm[310],ym[100];
bool visit[100];
int n,m=100;
bool dfs ( int u )
{
	int i;
	for ( i = 1; i <= m; i++ )
	{
		if ( visit[i] == false && c[u][i] == true )
		{
			visit[i] = true;
			if ( ym[i] == -1 || dfs(ym[i])==true )
			{
				ym[i] = u;
				xm[u] = i;
				return true;
			}
		}
	}
	return false;
}
int max_match()
{
	memset(xm,-1,sizeof(xm));
	memset(ym,-1,sizeof(ym));
	int i,c=0;
	for ( i = 1; i <= n; i++ )
	{
		if ( xm[i] == -1 )
		{
			memset(visit,false,sizeof(visit));
			if ( dfs(i) == true )
				c++;
		}
	}
	return c;
}
int main ()
{
	int i,j,x,y,d;
	while ( scanf("%d",&n)!=EOF )
	{
		for ( i=1;i<=n;i++)
		{
			for ( j = 1; j <= 100; j++ )
				c[i][j] = false;
			scanf("%d",&d);
			for ( j = 0; j < d;j++)
			{
				scanf("%d%d",&x,&y);
				c[i][12*(x-1)+y] = true;
			}
		}
		printf("%d\n",max_match());
	}
	return 0;
}