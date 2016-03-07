#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;
#define MAXN 40010
#define MAXM 40010
#define MAXQUERY 10100

struct NODE
{
	int v;
	NODE *next;
}*plist[MAXN];
struct ac
{
	int x, y;
	bool effect;
}t[MAXN];
struct QUERY
{
	int x, y;
	int queryId;
	int time;
	int ans;
}q[MAXQUERY];
struct EDGE
{
	int x, y;
	char dir;
	int dx, dy;
}a[MAXM];
int n, m, Q;
int father[MAXN];
bool visit[MAXN];
int cmp1(const void*a, const void*b)
{
	struct QUERY*c = (QUERY*)a;
	struct QUERY*d = (QUERY*)b;
	return c->time - d->time;
}
int cmp2(const void*a, const void*b)
{
	struct QUERY*c = (QUERY*)a;
	struct QUERY*d = (QUERY*)b;
	return c->queryId - d->queryId;
}
void Init()
{
	int i;
	for (i = 0; i <= n; i++)
	{
		t[i].effect = 0;
		plist[i] = NULL;
		father[i] = -1;
	}
}
void Insert(int x, int y)
{
	NODE *p = new NODE;
	p->v = y;
	p->next = plist[x];
	plist[x] = p;
}
int GetFather(int x)
{
	if (father[x] != -1)
	{
		father[x] = GetFather(father[x]);
		return father[x];
	}
	else
	{
		return x;
	}
}
void Input()
{
	scanf("%d %d", &n, &m);
	Init();
	int i, len;
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d %c", &a[i].x, &a[i].y, &len, &a[i].dir);
		if (a[i].dir == 'N')
		{
			a[i].dx = 0;
			a[i].dy = len;
		}
		else if (a[i].dir == 'S')
		{
			a[i].dx = 0;
			a[i].dy = -len;
		}
		else if (a[i].dir == 'E')
		{
			a[i].dx = len;
			a[i].dy = 0;
		}
		else
		{
			a[i].dx = -len;
			a[i].dy = 0;
		}
	}
	scanf("%d", &Q);
	for (i = 0; i < Q; i++)
	{
		scanf("%d %d %d", &q[i].x, &q[i].y, &q[i].time);
		q[i].queryId = i;
	}
	qsort(q, Q, sizeof(q[0]), cmp1);
}
stack<int>g_stack;
void dfs(int node, int dx, int dy)
{
	NODE *p;
	while (!g_stack.empty())
	{
		g_stack.pop();
	}
	g_stack.push(node);
	visit[node] = true;
	while (!g_stack.empty())
	{
		node = g_stack.top();
		g_stack.pop();
		t[node].x += dx;
		t[node].y += dy;
		p = plist[node];
		while (p != NULL)
		{
			if (!visit[p->v])
			{
				visit[p->v] = true;
				g_stack.push(p->v);
			}
			p = p->next;
		}
	}
}
void Solve()
{
	int i = 1, j = 0;
	int fx, fy;
	while (j < Q)
	{
		if (i <= q[j].time)
		{
			fx = GetFather(a[i].x);
			fy = GetFather(a[i].y);
			if (!t[fx].effect && !t[fy].effect)
			{
				t[fx].x = 0;
				t[fx].y = 0;
				t[fy].x = a[i].dx;
				t[fy].y = a[i].dy;
				t[fx].effect = 1;
				t[fy].effect = 1;
				father[fx] = fy;
				Insert(fx, fy);
				Insert(fy, fx);
			}
			else if (!t[fx].effect)
			{
				t[fx].x = t[a[i].y].x - a[i].dx;
				t[fx].y = t[a[i].y].y - a[i].dy;
				t[fx].effect = 1;
				father[fx] = fy;
				Insert(fx, fy);
				Insert(fy, fx);
			}
			else if (!t[fy].effect)
			{
				t[fy].x = t[a[i].x].x + a[i].dx;
				t[fy].y = t[a[i].x].y + a[i].dy;
				t[fy].effect = 1;
				father[fy] = fx;
				Insert(fx, fy);
				Insert(fy, fx);
			}
			else
			{
				memset(visit, 0, sizeof(visit));
				dfs(fx, -t[a[i].x].x + t[a[i].y].x - a[i].dx, -t[a[i].x].y + t[a[i].y].y - a[i].dy);
				father[fx] = fy;
				Insert(fx, fy);
				Insert(fy, fx);
			}
			i++;
		}
		else
		{
			fx = GetFather(q[j].x);
			fy = GetFather(q[j].y);
			if (fx != fy)
			{
				q[j].ans = -1;
			}
			else
			{
				q[j].ans = abs(t[q[j].x].x - t[q[j].y].x) + abs(t[q[j].x].y - t[q[j].y].y);
			}
			j++;
		}
	}
	qsort(q, Q, sizeof(q[0]), cmp2);
	for (i = 0; i < Q; i++)
	{
		printf("%d\n", q[i].ans);
	}
}
int main()
{
//	freopen("f:\\udata\\navigate.9.in", "r", stdin);
	Input();
	Solve();
	return 0;
}