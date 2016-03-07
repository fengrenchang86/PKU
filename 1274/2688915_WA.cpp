#include <iostream>
using namespace std;
int m,n;
bool c[210][210];
int xm[210],ym[210];
bool visit[210];
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
	int i,j,d,x;
	scanf("%d%d",&n,&m);
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= m; j++ )
			c[i][j] = false;
		scanf("%d",&d);
		for ( j = 1; j <= d; j++ )
		{
			scanf("%d",&x);
			c[i][x] = true;
		}
	}
	printf("%d\n",max_match());
/*
	printf("xm: \n");
	for ( i = 1; i <= n; i++ )
	{
		if ( xm[i] != -1 )
			printf("%d ",xm[i]);
	}
	printf("\n");
	printf("ym: \n");
	for ( i = 1; i <= n; i++ )
	{
		if ( ym[i] != -1 )
			printf("%d ",ym[i]);
	}
	printf("\n");
	*/
	return 0;
}
