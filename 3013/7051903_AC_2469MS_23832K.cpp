
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 100000000000
struct ac
{
	int v, len;
	ac *next;
}*pList[51000];
int n, m;
struct wa
{
	__int64 dist;
	int v;
	bool operator()(wa &m1, wa &m2)
	{
		return m1.dist > m2.dist;
	}
};
priority_queue<wa, vector<wa> , wa>que;
bool visit[51000];
__int64 w[51000];
int v[51000];
void Init()
{
	int i;
	for (i = 0; i <= m; i++)
	{
		pList[i] = NULL;
	}
}
void Insert(int x, int y, int z)
{
	ac *p = new ac;
	p->v = y;
	p->next = pList[x];
	p->len = z;
	pList[x] = p;
}
void Input()
{
	int i, x, y, z;
	for (i = 1; i <= m; i++)
	{
		scanf("%d", &v[i]);
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		Insert(x, y, z);
		Insert(y, x, z);
	}
}

void dij()
{
	__int64 ans = 0;
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
		ans += __int64(q.dist) * (__int64)v[q.v];
		t = pList[q.v];
		while (t != NULL)
		{
			if (w[t->v] > w[q.v] + t->len)
			{
				w[t->v] = w[q.v] + t->len;
				p.v = t->v;
				p.dist = w[q.v] + t->len;
				que.push(p);
			}
			t = t->next;
		}
	}
	for (i = 1; i <= m; i++)
	{
		if (visit[i] == false)
		{
			break;
		}
	}
	if (i <= m)
	{
		printf("No Answer\n");
	}
	else
	{
		printf("%I64d\n", ans);
	}
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d %d", &m, &n);
		Init();
		Input();
		dij();
	}
	return 0;
}
