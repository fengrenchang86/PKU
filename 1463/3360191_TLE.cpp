#include <iostream>
using namespace std;
bool c[1600][1600];
bool visit[1600];
int xm[1600],ym[1600];
int n;
void init ()
{
	int i;
	for ( i = 0; i < n; i++ )
		visit[i] = false;
	memset(c,false,sizeof(c));
}
void input ()
{
	int id,k,i,j,end;
	for ( i = 0; i < n; i++ )
	{
		scanf("%d:(%d)",&id,&k);
		for ( j = 0; j < k; j++ )
		{
			scanf("%d",&end);
			c[id][end] = c[end][id] = true;
		}
	}
}
bool dfs ( int u )
{
	int i;
	for ( i = 0; i < n; i++ )
	{
		if ( visit[i] == false && c[u][i] == true )
		{
			visit[i] = true;
			if ( ym[i] == -1 || dfs(ym[i]) == true )
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
	for ( i = 0; i < n; i++ )
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
void print()
{
	int i,j;
	for ( i = 0; i < n; i++ )
	{
		for ( j= 0 ; j < n; j++ )
			printf("%d ",c[i][j]==true?1:0);
		printf("\n");
	}
	printf("xm\n");
	for ( i = 0; i < n; i++ )
		printf("%d ",xm[i]);
	printf("\n");
	printf("ym\n");
	for ( i = 0; i < n; i++ )
		printf("%d ",ym[i]);
	printf("\n");
}
int main ()
{
	while ( scanf("%d",&n) != EOF )
	{
		init();
		input();
		printf("%d\n",max_match()/2);
//		print();
	}
	return 0;
}