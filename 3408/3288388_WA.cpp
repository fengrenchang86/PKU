
#include <iostream>
#include <vector>
#include<queue>
const int MAXN = 1100;
const int inf = 2147483647;
using namespace std;
struct node
{
	int w,id;
	friend bool operator<(const node&m1,const node&m2 )
	{
		return m1.w > m2.w ;
	}
};
struct chang
{
	int y;
	int len;
};
priority_queue<node>que;
vector<chang>a[MAXN];
int dist[MAXN];
bool visit[MAXN];
int n;
int dij ( int begin )
{
	while ( !que.empty() )
		que.pop();
	int i;
	node p,temp;
	chang q;
	for ( i = 0; i < MAXN; i++ )
	{
		dist[i] = inf;
		visit[i] = false;
	}
	dist[begin] = 0;
	p.id = begin;
	p.w = 0;
	que.push(p);
	while ( !que.empty())
	{
		p = que.top();
		que.pop();
		if ( p.w == inf )
			break;
		visit[p.id] = true;
		for ( i = 0; i < a[p.id].size(); i++ )
		{
			if ( visit[a[p.id][i].y] == true )
				continue;
			q = a[p.id][i];
			if ( dist[p.id]+q.len<dist[q.y] )
			{
				dist[q.y] = dist[p.id]+q.len;
				temp.id = q.y;
				temp.w = dist[q.y];
				que.push(temp);
			}
		}
	}
	int tmin = dist[1];
	for ( i = 2; i <= n; i++ )
	{
		if ( dist[i] > tmin )
			tmin = dist[i];
	}
	return tmin;
}
void input ()
{
	int i,j,k,x;
	chang cc;
	for ( i = 0; i < MAXN; i++ )
		a[i].clear();
	for ( i = 1; i <= n; i++ )
	{
		scanf("%d",&k);
		for ( j = 0; j < k; j++ )
		{
			scanf("%d",&x);
			cc.y = x;
			cc.len = 1;
			a[i].push_back(cc);
		}
	}
}
int main ()
{
	int i,k,x,y;
	cin>>n;
	input();
	y = inf;
	for ( i = n; i > 0; i-- )
	{
		k = dij(i);
		if ( k < y )
		{
			x = i;
			y = k;
		}
	}
	if ( y == inf )
		printf("impossible\n");
	else
		printf("%d %d\n",x,y);
	return 0;
}
