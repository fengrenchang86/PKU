#include <iostream>
using namespace std;
bool c[510][510];
int m,n;
int xm[510],ym[510];
bool visit[510];
bool dfs ( int u )
{
	int i;
	for ( i = 1; i <= n; i++ )
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
	memset(c,false,sizeof(c));
	int k,i,j;
	int x,y;
	bool flag;
	scanf("%d%d",&n,&m);
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d",&x,&y);
		c[x][y] = true;
	}
	cout<<max_match()<<endl;
	return 0;
}