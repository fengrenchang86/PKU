#include <iostream>
#include <queue>
using namespace std;
#define INF 2000000000
int dis[520];
int nDis[520];
bool visit[520];
int n, m;
struct ac
{
	int dis;
	int nId;
	bool operator()(ac& m1, ac& m2)
	{
		return m1.dis > m2.dis;
	}
};
priority_queue<ac, vector<ac>, ac>que;

struct node
{
	int v;
	int len;
	node *next;
}*list[520];
void Init()
{
	int i;
	for(i = 0; i <= n; i++)
	{
		dis[i] = INF;
		list[i] = NULL;
	}
}
void Insert(int x, int y, int len)
{
	node *p = new node;
	p->len = len;
	p->v = y;
	p->next = list[x];
	list[x] = p;
}
void Input()
{
	Init();
	int i, x, y, len;
	for(i = 0; i < m; i++)
	{
		scanf("%d", &x);
		dis[x] = 0;
	}
	for(i = 0; i <= n; i++)
	{
		nDis[i] = dis[i];
	}
	while(scanf("%d %d %d", &x, &y, &len) != EOF)
	{
		Insert(x, y, len);
	}
}
int Dij()
{
	while(!que.empty())
		que.pop();
	ac p, q;
	node *pn;
	int i, j;
	for(i = 1; i <= n; i++)
	{
		if(dis[i] == 0)
		{
			p.dis = 0;
			p.nId = i;
			que.push(p);
			visit[i] = true;
		}
	}
	memset(visit, false, sizeof(visit));
	for(i = 0; i < n; i++)
	{
		p = que.top();
		que.pop();
		if(p.dis > dis[p.nId])
			continue;
		pn = list[p.nId];
		visit[p.nId] = true;
		while(pn != NULL)
		{
			if(!visit[pn->v] && dis[pn->v] > pn->len + dis[p.nId])
			{
				dis[pn->v] = pn->len + dis[p.nId];
				q.dis = dis[pn->v];
				q.nId = pn->v;
				que.push(q);
			}
			pn = pn->next;
		}
	}
	j = 1;
	for(i = 2; i <= n; i++)
	{
		if(dis[i] > dis[j])
			j = i;
	}
	return dis[j];
}
void Solve()
{
	int ans = INF;
	int i, j, k, ansid = -1;
	for(i = 1; i <= n; i++)
	{
		if(nDis[i] == 0)
			continue;
		for(j = 1; j <= n; j++)
			dis[j] = nDis[j];
		dis[i] = 0;
		k = Dij();
		if(ans == -1 || k < ans)
		{
			ans = k;
			ansid = i;
		}
	}
	printf("%d\n", ansid);
}
int main()
{
	scanf("%d %d", &m, &n);
	Input();
	Solve();
	return 0;
}