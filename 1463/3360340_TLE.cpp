#include <iostream>
using namespace std;
const int inf = 2000000000;
int dp[1600][2];
bool c[1501][1501];
bool visit[1600];
int n;
void init ()
{
	int i;
	for ( i = 0; i < n; i++ )
	{
		visit[i] = false;
	}
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
int tmin ( int x, int y )
{
	return x<y?x:y;
}
int dfs ( int v )
{
	visit[v] = true;
	int i=0,t=inf,k=0,sy=0,sx=0;
	for ( i = 0; i < n; i++ )
	{
		if ( c[i][v] == false )
			continue;
		if ( visit[i] == false )
			k++;
	}
	for ( i = 0; i < n; i++ )
	{
		if ( c[i][v] == false )
			continue;
		if ( visit[i] == false )
		{
			k = dfs(i);
			sy += dp[i][1];
			sx += tmin(dp[i][0],dp[i][1]);
			if ( k < t )
				t = k;
		}
	}
	if ( t == inf )
	{
		dp[v][1] = 1;
		dp[v][0] = 0;
		return 1;
	}
	else if ( t == 1 )
	{
		dp[v][1] = dp[v][0] = 1;
		return 2;
	}
	else
	{
		dp[v][1] = sx+1;
		dp[v][0] = sy;
		return t+1;
	}
}
int main ()
{
	while ( scanf("%d",&n) != EOF )
	{
		init();
		input();
		dfs(0);
		printf("%d\n",dp[0][0],dp[0][1]);
	}
	return 0;
}