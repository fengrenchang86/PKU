#include <iostream>
using namespace std;
const int inf = 2000000000;
int dp[1600][2];
struct node
{
	int v;
	node *next;
}*list[1600];
bool visit[1600];
int n;
void init ()
{
	int i;
	for ( i = 0; i < n; i++ )
	{
		visit[i] = false;
		list[i] = NULL;
	}
}
void insert ( int begin ,int end )
{
	node *p = new node;
	p->v = end;
	p->next = list[begin];
	list[begin] = p;
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
			insert(id,end);
			insert(end,id);
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
	node *p = list[v];
	while ( p != NULL )
	{
		if ( visit[p->v] == false )
			k++;
		p = p->next;
	}
	p = list[v];
	while ( p != NULL )
	{
		if ( visit[p->v] == false )
		{
			k = dfs(p->v);
			sy += dp[p->v][1];
			sx += tmin(dp[p->v][0],dp[p->v][1]);
			i++;
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