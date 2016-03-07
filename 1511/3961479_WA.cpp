#include<iostream>
#include<queue>
#define  N 1000010
#define  inf 2147483647

using namespace std;
struct ac
{
	int w, id;
	bool operator()(ac &m1, ac &m2)
	{
		return m1.w < m2.w;
	}
};
struct NODE
{
	int v, len;
	NODE *next;
}*list[N], *flist[N];
priority_queue<ac, vector<ac>, ac>que;
int dis[N];
bool visit[N];
int n, m;
__int64 HH;

void init()
{
	int i;
	for(i = 1; i <= n; i++)
	{
		dis[i] = inf;
		visit[i] = false;
	}
}
void insert(int x, int y, int z)
{
	NODE *p = new NODE;
	p->v = y;
	p->len = z;
	p->next = list[x];
	list[x] = p;

	p = new NODE;
	p->v = x;
	p->len = z;
	p->next = flist[y];
	flist[y] = p;
}
void DijOne()
{
	init();
	dis[1] = 0;
	NODE *q;
	ac p, t;
	p.id = 1;
	p.w = 0;
	que.push(p);
	while(!que.empty())
	{
		p = que.top();
		que.pop();
		if(visit[p.id] || dis[p.id] > p.w)
			continue;
		visit[p.id] = true;
		q = list[p.id];
		while(q != NULL)
		{
			if(dis[q->v] > dis[p.id]+q->len)
			{
				dis[q->v] = dis[p.id] + q->len;
				t.id = q->v;
				t.w = dis[q->v];
				que.push(t);
			}
			q = q->next;
		}
	}
	int i;
	for(i = 2; i <= n; i++)
		HH += dis[i];
}
void DijTwo()
{
	init();
	dis[1] = 0;
	NODE *q;
	ac p, t;
	p.id = 1;
	p.w = 0;
	que.push(p);
	while(!que.empty())
	{
		p = que.top();
		que.pop();
		if(visit[p.id] || dis[p.id] > p.w)
			continue;
		visit[p.id] = true;
		q = flist[p.id];
		while(q != NULL)
		{
			if(dis[q->v] > dis[p.id]+q->len)
			{
				dis[q->v] = dis[p.id] + q->len;
				t.id = q->v;
				t.w = dis[q->v];
				que.push(t);
			}
			q = q->next;
		}
	}
	int i;
	for(i = 2; i <= n; i++)
		HH += dis[i];
}
void MissHH()
{
	int i, x, y, z;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; i++)
		list[i] = flist[i] = NULL;
	for(i = 0; i < m; i++)
	{
		scanf("%d%d%d",&x, &y, &z);
		insert(x, y, z);
	}
}
void LoveHH()
{
	HH = 0;
	DijOne();
	DijTwo();
	printf("%I64d\n", HH);
}
int main ()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		MissHH();
		LoveHH();
	}
	return 0;
}