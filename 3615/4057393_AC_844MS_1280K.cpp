#include <iostream>
#include <queue>
using namespace std;
const int inf = 2147483647;
class ac
{
public:
	int vecID;
	int w;
	bool operator()(const ac&m1, const ac&m2){return m1.w > m2.w;}
};
struct NODE
{
	int v,len;
	NODE *next;
}*list[310];
int dis[310][310];
bool visit[310];
int N,M,T;
priority_queue<ac,vector<ac>,ac>que;
void init()
{
	int i,j;
	for ( i = 0; i <= N; i++ )
	{
		for ( j = 0; j <= N; j++ )
			dis[i][j] = inf;
		list[i] = NULL;
	}
}
void insert ( int x, int y, int z )
{
	NODE *p = new NODE;
	p->v = y;
	p->len = z;
	p->next = list[x];
	list[x] = p;
}
void input()
{
	int i,x,y,z;
	scanf("%d%d%d",&N,&M,&T);
	init();
	for ( i = 0; i < M; i++ )
	{
		scanf("%d%d%d",&x,&y,&z);
		insert(x,y,z);
	}
}
void dij ( int begin )
{
	ac p,t;
	NODE *q;
	int k;
	p.vecID = begin;
	p.w = 0;
	dis[begin][begin] = 0;
	que.push(p);
	memset(visit,false,sizeof(visit));
	visit[begin] = true;
	while ( !que.empty() )
	{
		p = que.top();
		que.pop();
		if ( dis[begin][p.vecID] < p.w )
			continue;
		visit[p.vecID] = true;
		q = list[p.vecID];
		while ( q != NULL )
		{
			if ( visit[q->v] )
			{
				q = q->next;
				continue;
			}
			k = dis[begin][p.vecID]>q->len ? dis[begin][p.vecID]:q->len;
			if ( k < dis[begin][q->v] )
			{
				dis[begin][q->v] = k;
				t.vecID = q->v;
				t.w = k;
				que.push(t);
			}
			q = q->next;
		}
	}
}
void solve ()
{
	int i,x,y;
	for ( i = 1; i <= N; i++ )
	{
		dij(i);
	}
	for ( i = 0; i < T; i++ )
	{
		scanf("%d%d",&x,&y);
		if ( dis[x][y] != inf )
			printf("%d\n",dis[x][y]);
		else
			printf("-1\n");
	}
}
int main ()
{
	input();
	solve ();
	return 0;
}