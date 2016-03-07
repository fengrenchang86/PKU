#include <iostream>
using namespace std;
struct ac
{
	int v;
	int EdgeId;
	ac *next;
}*plist[50];
int visit[50];
int arrid[50];
bool edge[2000];
int low[50];
int n, m, s;
int nCount;
bool use[2000];
int ans[2000];
void Init()
{
	int i;
	for (i = 0; i < 50; i++)
	{
		plist[i] = NULL;
	}
	for (i = 0; i < 2000; i++)
	{
		use[i] = false;
	}
}
void Insert(int x, int y, int z)
{
	ac *p = new ac;
	p->v = y;
	p->EdgeId = z;
	p->next = plist[x];
	plist[x] = p;
}
void dfs(int node)
{
	visit[node] = nCount;
	low[node] = nCount;
	arrid[nCount] = node;
	nCount++;
	ac *p = plist[node];
	while (p != NULL)
	{
		if (visit[p->v] == 0 && edge[p->EdgeId] == false)
		{
			edge[p->EdgeId] = true;
			dfs(p->v);
		}
		p = p->next;
	}
}
void Getdfs()
{
	int i = 1;
	int node = s;
	ac *p, *q;
	while(i <= m)
	{
		p = plist[node];
		q = NULL;
		while(p != NULL)
		{
			if (edge[p->EdgeId] && low[p->v] > visit[node] && !use[p->EdgeId])
			{
				if (q == NULL)
				{
					q = p;
				}
			}
			else if (!use[p->EdgeId])
			{
				q = p;
				break;
			}
			p = p->next;
		}
		if (q == NULL)
		{
			printf("Round trip does not exist.\n");
			return;
		}
		use[q->EdgeId] = true;
		ans[i] = q->EdgeId;
		node = q->v;
		i++;
	}
	for (i = 1; i < m; i++)
	{
		printf("%d ", ans[i]);
	}
	printf("%d\n", ans[i]);
}
void func()
{
	int i, j;
	ac *p;
	for (i = n; i >= 1; i--)
	{
		j = arrid[i];
		p = plist[j];
		while (p != NULL)
		{
			if (edge[p->EdgeId] && visit[j] < visit[p->v])
			{
				if (low[j] > low[p->v])
				{
					low[j] = low[p->v];
				}
			}
			else if (!edge[p->EdgeId] && visit[p->v] < visit[j])
			{
				if (low[j] > visit[p->v])
				{
					low[j] = visit[p->v];
				}
			}
			p = p->next;
		}
	}
}
void Solve()
{
	int i;
	for (i = 1; i <= m; i++)
	{
		edge[i] = 0;
	}
	nCount = 1;
	dfs(s);
	func();
	Getdfs();
}
void Input()
{
	int x, y, z;
	m = 0;
	n = 0;
	Init();
	while(scanf("%d %d", &x, &y) != EOF)
	{
		if (x == 0 && y == 0)
		{
			if (m == 0)
				break;
			Solve();
			Init();
			m = 0;
			n = 0;
		}
		else
		{
			if (m == 0)
			{
				s = x < y ? x : y;
			}
			scanf("%d", &z);
			Insert(x, y, z);
			Insert(y, x, z);
			if (x > n)
			{
				n = x;
			}
			if (y > n)
			{
				n = y;
			}
			m++;
		}
	}
}
int main()
{
	Input();
	return 0;
}