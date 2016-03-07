#include <iostream>
using namespace std;
struct ac
{
	int v;
	ac *next;
}*pTable[12000];

int n, m;
int degree[12000];
int acStack[600000];
int nTop;
void Insert(int x, int y)
{
	ac *p = new ac;
	p->v = y;
	p->next = pTable[x];
	pTable[x] = p;
}
void Input()
{
	int i, x, y;
	for (i = 0; i <= n; i++)
	{
		pTable[i] = 0;
		degree[i] = 0;
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
void acDfs()
{
	nTop = 0;
	acStack[nTop++] = 1;
	ac *p;
	int node, v;
	while (nTop > 0)
	{
		nTop--;
		node = acStack[nTop];
		if (degree[node] == 0)
		{
			printf("%d\n", node);
			continue;
		}
		nTop++;
		p = pTable[node];
		if (p != NULL)
		{
			v = p->v;
			pTable[node] = pTable[node]->next;
			degree[node]--;
			degree[v]--;
			acStack[nTop++] = v;
		}
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
		int v;
		while (p != NULL)
		{
			v = p->v;
			pTable[node] = p->next;
			delete p;
			degree[node]--;
			degree[v]--;
			dfs(v);
			p = pTable[node];
		}
		printf("%d\n", node);
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	Input();
	//dfs(1);
	acDfs();
	return 0;
}