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
int d[50];
void Init()
{
	int i;
	for (i = 0; i < 50; i++)
	{
		plist[i] = NULL;
		visit[i] = 0;
		d[i] = 0;
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
	if (plist[x] == NULL)
	{
		p->next = NULL;
		plist[x] = p;
		return;
	}
	ac *q = plist[x];
	if (q->EdgeId > z)
	{
		p->next = plist[x];
		plist[x] = p;
		return;
	}
	while (q->next != NULL)
	{
		if (q->next->EdgeId > z)
		{
			break;
		}
		q = q->next;
	}
	p->next = q->next;
	q->next = p;
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
bool DFS(int x, int y)
{
	if (x == y)
	{
		return true;
	}
	ac *p = plist[x];
	bool f = false;
	while (p != NULL)
	{
		if (!edge[p->EdgeId] && !use[p->EdgeId])
		{
			edge[p->EdgeId] = true;
			f = f || DFS(y, p->v);
			if (f)
			{
				return true;
			}
		}
		p = p->next;
	}
	return f;
}
void Getdfs()
{
	int i = 1;
	bool v;
	int node = s;
	ac *p, *q;
	while(i <= m)
	{
		p = plist[node];
		q = NULL;
		while(p != NULL)
		{
			if (!use[p->EdgeId])
			{
				memset(edge, 0, sizeof(edge));
				use[p->EdgeId] = true;
				v = DFS(node, p->v);
				use[p->EdgeId] = false;
				if (!v && q == NULL)
				{
					q = p;
				}
				else if(v)
				{
					q = p;
					break;
				}
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
	if (q->v != s || i <= m)
	{
		printf("Round trip does not exist.\n");
			return;
	}
//	if (ans[1] == 1)
	{
		for (i = 1; i < m; i++)
		{
			printf("%d ", ans[i]);
		}
		printf("%d\n", ans[m]);
		return;
	}
/*	for (i = 1; i <= m; i++)
	{
		if (ans[i] == 1)
		{
			break;
		}
	}
	while(i <= m)
	{
		printf("%d ", ans[i]);
		i++;
	}
	i = 1;
	while(ans[i+1] != 1)
	{
		printf("%d ", ans[i]);
		i++;
	}
	printf("%d\n", ans[i]);*/
}
void func()
{
}
void Solve()
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (d[i] % 2 == 1)
		{
			printf("Round trip does not exist.\n");
			return;
		}
	}
	for (i = 1; i <= m; i++)
	{
		edge[i] = 0;
	}
	nCount = 1;
	dfs(s);
//	func();
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
			
			scanf("%d", &z);
			if (m == 0)
			{
				s = x < y ? x : y;
			}
			d[x]++;
			d[y]++;
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

