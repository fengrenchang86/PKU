#include <iostream>
using namespace std;
struct ac
{
	int v;
	ac *next;
}*pTable[30];
int col[30];
int v[30];
int n, m;
void Insert(int x, int y)
{
	ac *p = new ac;
	p->v = y;
	p->next = pTable[x];
	pTable[x] = p;
}
void Input()
{
	int i, j, x, y;
	char str[100];
	for (i = 0; i < n; i++)
	{
		pTable[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		scanf(" %s", &str);
		x = str[0] - 'A';
		for (j = 2; str[j] != 0; j++)
		{
			y = str[j] - 'A';
			Insert(x, y);
		}
	}
}
void dfs(int node)
{
	int i;
	if (node == m)
	{
		int j = 0;
		for (i = 0; i < n; i++)
		{
			if (v[i] > j)
			{
				j = v[i];
			}
		}
		if (j < m)
		{
			m = j;
		}
		return;
	}
	ac *p;
	for (i = 1; i <= m; i++)
	{
		p = pTable[node];
		while (p != NULL)
		{
			if (i == v[p->v])
			{
				break;
			}
			p = p->next;
		}
		if (p == NULL)
		{
			v[node] = i;
			dfs(node + 1);
		}
	}
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			break;
		}
		Input();
		m = n;
		memset(v, 0, sizeof(v));
		dfs(0);
		if (m == 1)
		{
			printf("1 channel needed.\n");
		}
		else
		{
			printf("%d channels needed.\n", m);
		}
	}
	return 0;
};