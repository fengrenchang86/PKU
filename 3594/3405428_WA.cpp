#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int inf = 2147483647;
struct ROAD
{
	int next;
	int b,e;
	int time;
};
struct ac
{
	int vec;
	int reach;
	int time;
	bool operator()(const ac&m1, const ac&m2 )
	{
		return m1.time > m2.time;
	}
};
int n,m,S,T;
int finish[110];
vector<ROAD>road[110];
priority_queue<ac,vector<ac>,ac>que;
int c[110][10010];
void input ()
{
	int i,x,y,b,e,time;
	ROAD r;
	scanf("%d%d%d%d",&n,&m,&S,&T);
	for ( i = 0; i <= n; i++ )
		finish[i] = inf;
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d%d%d%d",&x,&y,&b,&e,&time);
		if ( b + time <= e )
		{
			r.b = b;
			r.e = e;
			r.next = y;
			r.time = time;
			road[x].push_back(r);
			if ( finish[y] > e )
				finish[y] = e;
		}
	}
}
void solve ()
{
	int i,j;
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 0; j <= 10000; j++ )
			c[i][j] = inf;
	}
	ac p,q;
	ROAD r;
	p.vec = S;
	p.time = 0;
	for ( i = 0; i <= 10000; i++ )
	{
		c[S][i] = 0;
		p.reach = i;
		que.push(p);
	}
	while ( !que.empty() )
	{
	//	p = que.front();
		p = que.top();
		que.pop();
		if ( c[p.vec][p.reach] < p.time )
			continue;
		i = 0;
		j = road[p.vec].size();
		for ( i = 0; i < j; i++ )
		{
			r = road[p.vec][i];
			if ( p.reach >= r.b && p.reach+r.time <= r.e && c[r.next][p.reach+r.time] > p.time+r.time )
			{
				c[r.next][p.reach+r.time] = p.time+r.time;
				q.vec = r.next;
				q.time = p.time+r.time;
				q.reach = p.reach+r.time;
				que.push(q);
				while ( q.time <= 10000 && q.reach <= finish[q.vec] )
				{
					q.time++;
					q.reach++;
					if ( c[q.vec][q.reach] > q.time )
					{
						c[q.vec][q.reach] = q.time;
						que.push(q);
					}
				}
			}
		}
	}
	j = c[T][0];
	for ( i = 1; i <= 10000; i++ )
	{
		if ( c[T][i] < j )
			j = c[T][i];
	}
	printf("%d\n",j);
}
int main ()
{
	input();
	solve();
	return 0;
}