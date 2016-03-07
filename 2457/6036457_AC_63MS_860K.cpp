#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 1000000000
struct ac
{
	int v;
	ac *next;
}*pList[51000];
int n, m;
struct wa
{
	int dist;
	int v;
	bool operator()(wa &m1, wa &m2)
	{
		return m1.dist > m2.dist;
	}
};
priority_queue<wa, vector<wa> , wa>que;
int path[51000];
bool visit[51000];
int w[51000];
void Init()
{
	int i;
	for (i = 0; i <= m; i++)
	{
		pList[i] = NULL;
	}
}
void Insert(int x, int y)
{
	ac *p = new ac;
	p->v = y;
	p->next = pList[x];
	pList[x] = p;
}
void Input()
{
	int i, x, y;
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		Insert(x, y);
	}
}
void PrintPath(int k)
{
	if (k == 1)
	{
		return;
	}
	else
	{
		PrintPath(path[k]);
		printf("%d\n", path[k]);
	}
}
void dij()
{
	int i;
	for (i = 0; i <= m; i++)
	{
		w[i] = INF;
		visit[i] = false;
	}
	while (!que.empty())
	{
		que.pop();
	}
	wa p, q;
	ac *t;
	p.dist = 0;
	p.v = 1;
	w[1] = 0;
	que.push(p);
	while (!que.empty())
	{
		q = que.top();
		que.pop();
		if (visit[q.v] || w[q.v] < q.dist)
		{
			continue;
		}
		visit[q.v] = true;
		t = pList[q.v];
		while (t != NULL)
		{
			if (w[t->v] > w[q.v] + 1)
			{
				w[t->v] = w[q.v] + 1;
				path[t->v] = q.v;
				p.v = t->v;
				p.dist = w[q.v] + 1;
				que.push(p);
			}
			t = t->next;
		}
	}
	if (w[m] == INF)
	{
		printf("-1\n");
		return;
	}
	printf("%d\n", w[m]+1);
	PrintPath(m);
	printf("%d\n", m);
}
int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		Init();
		Input();
		dij();
	}
	return 0;
}