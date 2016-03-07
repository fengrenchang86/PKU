#include <iostream>
using namespace std;
struct ac
{
	int v;
	bool use;
	ac *next;
}*pTable[12000];
int n, m;
int degree[12000];
void Insert(int x, int y)
{
	ac *p = new ac;
	p->v = y;
	p->use = 0;
	p->next = pTable[x];
	pTable[x] = p;
}
void Input()
{
	int i, x, y;
	for (i = 0; i <= n; i++)
	{
		pTable[i] = 0;
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		Insert(x, y);
		Insert(y, x);
		degree[x] += 2;
		degree[y] += 2;
	}
}
void dfs(int node)
{
	if (degree[node] == 0)
	{
		printf("%d\n", node);
	}
	else
	{
		ac *p = pTable[node];
		while (p != NULL)
		{
			if (p->use == 0)
			{
				p->use = true;
				degree[node]--;
				degree[p->v]--;
				dfs(p->v);
			}
			p = p->next;
		}
		printf("%d\n", node);
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	Input();
	dfs(1);
	return 0;
}