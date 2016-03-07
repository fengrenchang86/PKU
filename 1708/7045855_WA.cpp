#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1000000000
struct ac
{
	int v;
	int col;
	ac *next;
}*pTable[120];
struct wa
{
	int step;
	int p1, p2;
};
queue<wa>que;
int color[120];
bool visit[120];
int dist[120][120];
int n, K, L, Q;
void Init()
{
	int i, j;
	for (i = 0; i <= n; i++)
	{
		pTable[i] = NULL;
		for (j = 0; j <= n; j++)
		{
			dist[i][j] = INF;
		}
		dist[i][i] = 0;
	}
}
void Insert(int x, int y, int z)
{
	ac *p = new ac;
	p->v = y;
	p->col = z;
	p->next = pTable[x];
	pTable[x] = p;
}
void Input()
{
	int i, m, x, y, z;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &color[i]);
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		Insert(x, y, z);
		Insert(y, x, z);
	}
}
void Bfs()
{
	while (!que.empty())
	{
		que.pop();
	}
	ac *r;
	wa p, q;
	p.p1 = L;
	p.p2 = K;
	p.step = 0;
	que.push(p);
	dist[L][K] = 0;
	dist[K][L] = 0;
	while (!que.empty())
	{
		p = que.front();
		que.pop();
		if (p.step > dist[p.p1][p.p2])
		{
			continue;
		}
		if (p.p1 == Q || p.p2 == Q)
		{
			printf("YES\n%d\n", p.step);
			return;
		}
		r = pTable[p.p1];
		q.p2 = p.p2;
		q.step = p.step + 1;
		while (r != NULL)
		{
			if (r->col == color[p.p2] && dist[p.p2][r->v] > q.step)
			{
				dist[p.p2][r->v] = q.step;
				dist[r->v][p.p2] = q.step;
				q.p1 = r->v;
				que.push(q);
			}
			r = r->next;
		}
		r = pTable[p.p2];
		q.p1 = p.p1;
		while (r != NULL)
		{
			if (r->col == color[p.p1] && dist[p.p1][r->v] > p.step)
			{
				dist[p.p1][r->v] = q.step;
				dist[r->v][p.p1] = q.step;
				q.p2 = r->v;
				que.push(q);
			}
			r = r->next;
		}
	}
	printf("NO\n");
}
int main()
{
	while (scanf("%d %d %d %d", &n, &K, &L, &Q) != EOF)
	{
		Init();
		Input();
		Bfs();
	}
	return 0;
}