#include <iostream>
#include <vector>
using namespace std;
#define MAXN 120000
struct ac
{
	int v;
	ac *next;
};
ac *pTable[MAXN], *pvTable[MAXN];
int v[MAXN];
int f[MAXN];
int g[MAXN];
bool visit[MAXN];
int nVisitCount, n, m;
int flag;
void Insert(int x, int y)
{
	ac *p = new ac;
	p->v = y;
	p->next = pTable[x];
	pTable[x] = p;

	p = new ac;
	p->v = x;
	p->next = pvTable[y];
	pvTable[y] = p;
}
void dfs_topo(int node)
{
	visit[node] = true;
	ac *p = pTable[node];
	while (p != NULL)
	{
		if (!visit[p->v])
		{
			dfs_topo(p->v);
		}
		p = p->next;
	}
	v[nVisitCount] = node;
	nVisitCount++;
}
void dfs(int node)
{
	g[node] = nVisitCount;
	f[node] = 1;
//	f[node/2*2+!(node%2)] = -1;
	visit[node] = 1;
//	visit[node/2*2+!(node%2)] = 1;
	ac *p = pvTable[node];
	while (p != NULL)
	{
		if (!visit[p->v])
		{
			dfs(p->v);
		}
		p = p->next;
	}
}
void Input()
{
	int i, j, x, y, a,b;
	char ch[10];
	for (i = 0; i < 2 * n; i++)
	{
		pTable[i] = pvTable[i] = 0;
	}
	Insert(1, 0);
	for (i = 0; i < m; i++)
	{
		scanf(" %s", &ch);
		a = b = x = y = 0;
		j = 0;
		while (ch[j] >= '0' && ch[j] <= '9')
		{
			x *= 10;
			x += (ch[j] - '0');
			j++;
		}
		x *= 2;
		if (ch[j] == 'h')
		{
			a++;
		}
		scanf(" %s", &ch);
		j = 0;
		while (ch[j] >= '0' && ch[j] <= '9')
		{
			y *= 10;
			y += (ch[j] - '0');
			j++;
		}
		y *= 2;
		if (ch[j] == 'h')
		{
			b++;
		}
		Insert(x + (a+1)%2, y + b);
		Insert(y + (b+1)%2, x + a);
	}
}
void Solve()
{
	memset(visit, 0, sizeof(visit));
	int i;
	flag = 0;
	nVisitCount = 0;
	for (i = 0; i < 2 * n; i++)
	{
		if (!visit[i])
		{
			dfs_topo(i);
		}
	}
	memset(visit, 0, sizeof(visit));
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
	i = nVisitCount - 1;
	nVisitCount = 0;
//	visit[0] = 1;
//	dfs(0);
	for (; i >= 0; i--)
	{
		if (visit[v[i]/2*2+!(v[i]%2)])
		{
			visit[v[i]] = 1;
		}
		else if (!visit[v[i]])
		{
			nVisitCount++;
			dfs(v[i]);
		}
	}
	for (i = 0; i < n; i++)
	{
		if (g[2*i] == g[2*i+1])
		{
			printf("bad luck\n");
			return;
		}
	}
	if (f[2] == 1)
	{
		printf("1h");
	}
	else
	{
		printf("1w");
	}
	for (i = 2; i < n; i++)
	{
		if (f[2*i] == 1)
		{
			printf(" %dh", i);
		}
		else
		{
			printf(" %dw", i);
		}
	}
	printf("\n");
}
int main()
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		if (n + m == 0)
		{
			break;
		}
		Input();
		Solve();
	}
	return 0;
}