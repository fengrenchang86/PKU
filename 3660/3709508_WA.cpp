#include <iostream>
using namespace std;
bool visit[120];
bool c[120][120];
int FinishTime[120];
int Tp[120];
int n,m,count;
void init ()
{
	int i,j;
	for ( i = 0; i <= n; i++ )
	{
		visit[i] = false;
		for ( j = 0; j <= n; j++ )
			c[i][j] = false;
	}
	count = 0;
}
void fDFS ( int nNode )
{
	int i;
	visit[nNode] = true;
	for ( i = 1; i <= n; i++ )
	{
		if ( !visit[i] && c[nNode][i] )
			fDFS(i);
	}
	FinishTime[nNode] = ++count;
	Tp[count] = nNode;
}
void DeepFS ( int nStart, int nNode )
{
	visit[nNode] = true;
	if ( nStart != nNode )
		c[nStart][nNode] = true;
	int i;
	for ( i = 1; i <= n; i++ )
	{
		if ( c[nNode][i] && !visit[i] )
			DeepFS(nStart,i);
	}
}
void input ()
{
	scanf("%d%d",&n,&m);
	init();
	int i,j,x,y;
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d",&x,&y);
		c[x][y] = true;
	}
	for ( i = 1; i <= n; i++ )
	{
		memset(visit,false,sizeof(visit));
		DeepFS(i,i);
		for ( j = 1; j <= n; j++ )
			c[i][j] = visit[j];
		c[i][i] = false;
	}
	memset(visit,false,sizeof(visit));
	for ( i = 1; i <= n; i++ )
	{
		if ( !visit[i] )
			fDFS(i);
	}
}
void solve ()
{
	int i,j,k,ans=0;
	memset(visit,false,sizeof(visit));
	for ( i = 1; i <= n; i++ )
	{
		if ( visit[Tp[i]] )
			continue;
		k = i;
		for ( j = i+1; j <= n; j++ )
		{
			if ( c[Tp[j]][Tp[i]] == false )
				visit[Tp[j]] = true;
			else
				k++;
		}
		if ( k == n )
			ans++;
	}
	printf("%d\n",ans);
}
int main ()
{
	input();
	solve();
	return 0;
}