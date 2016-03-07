#include <iostream>
#include <queue>
using namespace std;
const int inf = 2147483647;
struct ac
{
	int x,y,cost;
}d[110];
__int64 cost[110][110];
queue<ac>que;
int n,m,k;
void solve (  )
{
	int i,j;
	ac p,q;
	for ( i = 0; i < 110; i++ )
		for ( j= 0 ; j < 110; j++ )
			cost[i][j] = inf;
	for ( i = 0; i < k; i++ )
		scanf("%d%d%d",&d[i].x,&d[i].y,&d[i].cost);
	while ( !que.empty() )
		que.pop();
	p.x = 0;
	p.y = 0;
	p.cost = 0;
	cost[0][0] = 0;
	que.push(p);
	while ( !que.empty() )
	{
		p = que.front();
		que.pop();
		if ( cost[p.x][p.y] < p.cost )
			continue;
		for ( i = 0; i < k; i++ )
		{
			if ( p.x+d[i].x <= n && p.y+d[i].y <= m && p.y+d[i].y >= 0 && cost[p.x+d[i].x][p.y+d[i].y] > p.cost+d[i].cost )
			{
				cost[p.x+d[i].x][p.y+d[i].y] = p.cost+d[i].cost;
				q.x = p.x+d[i].x;
				q.y = p.y+d[i].y;
				q.cost = p.cost+d[i].cost;
				que.push(q);
			}
		}
	}
	if ( cost[n][m] != inf )
		printf("%lld\n",cost[n][m]);
	else
		printf("-1\n");
}
int main ()
{
	while ( scanf("%d%d%d",&n,&m,&k)!=EOF )
	{
		if ( n == 0 && m == 0 && k == 0 )
			break;
		solve();
	}
	return 0;
}