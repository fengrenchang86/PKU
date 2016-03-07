#include <iostream>
using namespace std;
const int inf = 2000000000;
int dp[1600][2];
bool c[1501][1501];
bool visit[1600];
int n;
struct ac
{
	int v;
	ac *next;
}*list[1600];
void init ()
{
	int i;
	for ( i = 0; i < n; i++ )
	{
		visit[i] = false;
		list[i] = NULL;
	}
}
void insert ( int begin, int end )
{
	ac *p = new ac;
	p->v = end;
	p->next = list[begin];
	list[begin] = p;
}
int input ()
{
	int id,k,i,j,end;
	for ( i = 0; i < n; i++ )
	{
		scanf("%d:(%d)",&id,&k);
		for ( j = 0; j < k; j++ )
		{
			scanf("%d",&end);
			insert(id,end);
			visit[end] = true;
		}
	}
	for ( i = 0; i < n; i++ )
	{
		if ( visit[i] == false )
			break;
	}
	return i;
}
int tmin ( int x, int y )
{
	return x<y?x:y;
}
int dfs ( int v )
{
	ac *p=list[v];
	visit[v] = true;
	int i=0,t=inf,k=0,sy=0,sx=0;
//	for ( i = 0; i < n; i++ )
	while( p != NULL )
	{
		i = p->v;
		if ( visit[i] == false )
		{
			k = dfs(i);
			sy += dp[i][1];
			sx += tmin(dp[i][0],dp[i][1]);
			if ( k < t )
				t = k;
		}
		p = p->next;
	}
	if ( t == inf )
	{
		dp[v][1] = 1;
		dp[v][0] = 0;
		return 1;
	}
/*	else if ( t == 1 )
	{
		dp[v][1] = dp[v][0] = 1;
		return 2;
	}
*/	else
	{
		dp[v][1] = sx+1;
		dp[v][0] = sy;
		return t+1;
	}
}
int main ()
{
	int k;
	while ( scanf("%d",&n) != EOF )
	{
		init();
		k = input();
		memset(visit,false,sizeof(visit));
		dfs(k);
		printf("%d\n",tmin(dp[k][0],dp[k][1]));
	}
	return 0;
}