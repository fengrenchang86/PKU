#include <iostream>
#include <queue>
using namespace std;
#define N 5005
#define inf 2000000000
struct ac
{
	int v, len;
	ac *next;
}*plist[N];
int dis[N][2];
bool visit[N];
int n, m;
struct wa
{
	int id, dis;
	bool operator()(wa &m1, wa &m2)
	{
		return m1.dis > m2.dis;
	}
};
priority_queue<wa, vector<wa>, wa>que;
void insert(int x, int y, int len)
{
	ac *p = new ac;
	p->len = len;
	p->v = y;
	p->next = plist[x];
	plist[x] = p;
}
void Input()
{
	int i, x, y, z;
	for(i = 0; i < n; i++)
		plist[i] = NULL;
	for(i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		insert(x-1, y-1, z);
		insert(y-1, x-1, z);
	}
}
void dij()
{
	wa q,t;
	ac *p = NULL;
	int i;
	for(i = 0; i < n; i++)
	{
		dis[i][0] = dis[i][1] = inf;
		visit[i] = false;
	}
	q.id = 0;
	q.dis = 0;
	visit[0] = true;
	while(que.empty() == false)
		que.pop();
	que.push(q);
	dis[0][0] = 0;
	while(!que.empty())
	{
		q = que.top();
		que.pop();
		if(dis[q.id][0] < q.dis)
			continue;
		visit[q.id] = true;
		p = plist[q.id];
		while(p != NULL)
		{
			if(!visit[p->v] && dis[p->v][0] > q.dis + p->len)
			{
				dis[p->v][0] = q.dis + p->len;
				t.dis = dis[p->v][0];
				t.id = p->v;
				que.push(t);
			}
			p = p->next;
		}
	}
	for(i = 0; i < n; i++)
	{
		t.id = i;
		t.dis = dis[i][0];
		que.push(t);
		visit[i] = false;
	}
	while(!que.empty())
	{
		q = que.top();
		que.pop();
		if(dis[q.id][1] < q.dis)
			continue;
		p = plist[q.id];
		while(p != NULL)
		{
			if(dis[p->v][0] < dis[q.id][0] + p->len && dis[p->v][1] > dis[q.id][0] + p->len)
			{
				dis[p->v][1] = dis[q.id][0] + p->len;
				t.id = p->v;
				t.dis = dis[p->v][1];
				que.push(t);
			}
			if(dis[p->v][0] < dis[q.id][1] + p->len && dis[p->v][1] > dis[q.id][1] + p->len)
			{
				dis[p->v][1] = dis[q.id][1] + p->len;
				t.id = p->v;
				t.dis = dis[p->v][1];
				que.push(t);
			}
			p = p->next;
		}
	}
	printf("%d\n", dis[n-1][1]);
}
int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		Input();
		dij();
	}
	return 0;
}