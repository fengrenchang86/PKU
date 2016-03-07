#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 11000;
const int inf = 2147483647;
class road
{
public:
	int x,y;
	int len;
};
class ac
{
public:
	int x,y;
	char str[100];
	friend bool operator<(const ac&m1, const ac&m2 )//优先队列大的优先，若要改变方向，修改此函数
	{
		if ( m1.x != m2.x )
			return m1.x<m2.x;
		else
			return m1.y>m2.y;
	}
};
struct node
{
	int w,id;
	friend bool operator<(const node&m1, const node&m2 )
	{
		return m1.w > m2.w;
	}
};
struct chang
{
	int y;
	int len;
};
priority_queue<node>que;//优先队列，w值小的优先出队
vector<chang>a[MAXN],b[MAXN];//相当于邻接表，a[i][j] = k 表示i到k有通路
vector<road>r;//所有边按输入顺序存储在r
int dist[MAXN],fdist[MAXN];//正向最短路，反向最短路
bool visit[MAXN];
int n,m,k;
void dij ()
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
	dist[1] = 0;
	p.id = 1;
	p.w = 0;
	que.push(p);
	while ( !que.empty() )
	{
		p = que.top();
		que.pop();
		if ( visit[p.id] == true )
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
}
void fdij ()
{
	while ( !que.empty() )
		que.pop();
	int i;
	node p,temp;
	chang q;
	for ( i = 0; i < MAXN; i++ )
	{
		fdist[i] = inf;
		visit[i] = false;
	}
	fdist[n] = 0;
	p.id = n;
	p.w = 0;
	que.push(p);
	while ( !que.empty() )
	{
		p = que.top();
		que.pop();
		if ( visit[p.id] == true )
			break;
		visit[p.id] = true;
		for ( i = 0; i < b[p.id].size(); i++ )
		{
			if ( visit[b[p.id][i].y] == true )
				continue;
			q = b[p.id][i];
			if ( fdist[p.id]+q.len<fdist[q.y] )
			{
				fdist[q.y] = fdist[p.id]+q.len;
				temp.id = q.y;
				temp.w = fdist[q.y];
				que.push(temp);
			}
		}
	}
}
int main ()
{
	int i;
	road z;
	chang cc;
	r.clear();
	scanf("%d%d%d",&n,&m,&k);
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d%d",&z.x,&z.y,&z.len);
		r.push_back(z);
		cc.y = z.y;
		cc.len = z.len;
		a[z.x].push_back(cc);
		cc.y = z.x;
		b[z.y].push_back(cc);
	}
	dij();
	fdij();
	int c=0;
	int t = r.size();
	for ( i = 0; i < t; i++ )
	{
		z = r[i];
		if ( fdist[z.y] == inf )
			continue;
		if ( dist[z.x]+fdist[z.y]-k+z.len <= dist[n] )
			c++;
	}
	cout<<c<<endl;
	for ( i = 0; i < t; i++ )
	{
		z = r[i];
		if ( fdist[z.y] == inf )
			continue;
		if ( dist[z.x]+fdist[z.y]-k+z.len <= dist[n] )
			cout<<i+1<<endl;
	}
//	for ( i = 1; i <= n; i++ )
//		printf("dist[%02d]=%d\n",i,dist[i]);
//	for ( i = 1; i <= n; i++ )
//		printf("fdist[%02d]=%d\n",i,fdist[i]);
	return 0;
}