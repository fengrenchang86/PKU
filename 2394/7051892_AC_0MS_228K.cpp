#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1000000000
struct EDGE
{
	int v, len;
};
struct ACM
{
	int dis;
	int v;
	bool operator()(ACM &m1, ACM &m2)
	{
		return m1.dis > m2.dis;
	}
};
priority_queue<ACM, vector<ACM>, ACM>que;
vector<EDGE>pList[600];
int F, P, C, M;
bool visit[600];
int dist[600];
void Insert(int x, int y, int len)
{
	EDGE e;
	e.len = len;
	e.v = y;
	pList[x].push_back(e);
}
void Dij();
void Input()
{
	int i, x, y, len;
	for (i = 0; i <= 500; i++)
	{
		pList[i].clear();
	}
	scanf("%d %d %d %d", &F, &P, &C, &M);
	for (i = 0; i < P; i++)
	{
		scanf("%d %d %d", &x, &y, &len);
		Insert(x, y, len);
		Insert(y, x, len);
	}
	Dij();
	memset(visit, 0, sizeof(visit));
	y = 0;
	for (i = 0; i < C; i++)
	{
		scanf("%d", &x);
		if (dist[x] <= M)
		{
			visit[i+1] = true;
			y++;
		}
	}
	printf("%d\n", y);
	for (i = 1; i <= C; i++)
	{
		if (visit[i])
		{
			printf("%d\n", i);
		}
	}
}
void Dij()
{
	while (!que.empty())
	{
		que.pop();
	}
	int i, j, k;
	memset(visit, 0, sizeof(visit));
	for (i = 0; i <= F; i++)
	{
		dist[i] = INF;
	}
	ACM p, q;
	EDGE e;
	p.dis = 0;
	p.v = 1;
	que.push(p);
	dist[1] = 0;
	while (!que.empty())
	{
		p = que.top();
		que.pop();
		if (p.dis > dist[p.v] || visit[p.v])
		{
			continue;
		}
		visit[p.v] = true;
		for (i = 0; i < pList[p.v].size(); i++)
		{
			e = pList[p.v][i];
			if (!visit[e.v] && dist[e.v] > e.len + p.dis)
			{
				dist[e.v] = e.len + p.dis;
				q.v = e.v;
				q.dis = dist[e.v];
				que.push(q);
			}
		}
	}
}
int main()
{
	Input();
	return 0;
}