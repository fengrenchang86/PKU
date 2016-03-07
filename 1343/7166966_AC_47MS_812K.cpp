#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
vector<int>pTable[200];
vector<int>ans[200];
bool visit[200];
int nChildCount[200];
int n, m, nHead;
vector<int>son[200];
int cmp(const void*a, const void*b)
{
	int x = *(int*)a;
	int y = *(int*)b;
	int i;
	for (i = 0; i < son[x].size() && i < son[y].size(); i++)
	{
		if (son[x][i] < son[y][i])
		{
			return -1;
		}
		else if (son[x][i] > son[y][i])
		{
			return 1;
		}
	}
	if (son[x].size() < son[y].size())
	{
		return -1;
	}
	return 1;
}
bool Comp(const int&a, const int &b)
{
	int i;
	for (i = 0; i < ans[a].size() && i < ans[b].size(); i++)
	{
		if (ans[a][i] < ans[b][i])
		{
			return false;
		}
		else if (ans[a][i] > ans[b][i])
		{
			return false;
		}
	}
	if (ans[a].size() == ans[b].size())
	{
		return true;
	}
	return false;
}
void Init()
{
	int i;
	for (i = 0; i <= n; i++)
	{
		pTable[i].clear();
		son[i].clear();
		visit[i] = 0;
		nChildCount[i] = 0;
	}
}
int dfs(int node)
{
	visit[node] = 1;
	int i, j, k = 1, l = 0;
	int *p = new int[pTable[node].size()];
	for (i = 0; i < pTable[node].size(); i++)
	{
		j = pTable[node][i];
		if (!visit[j])
		{
			p[l++] = j;
			k += dfs(j);
		}
	}
	nChildCount[node] = k;
	son[node].push_back(k);
	qsort(p, l, sizeof(p[0]), cmp);
	for (i = 0; i < l; i++)
	{
		j = p[i];
		for (k = 0; k < son[j].size(); k++)
		{
			son[node].push_back(son[j][k]);
		}
	}
	return nChildCount[node];
}
void Input(int k)
{
	int i, x, y;
	Init();
	for (i = 1; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		pTable[x].push_back(y);
		visit[y] = 1;
	}
	for (i = 1; i <= n; i++)
	{
		if (!visit[i])
		{
			nHead = i;
		}
	}
	memset(visit, 0, sizeof(visit));
	dfs(nHead);
	for (i = 0; i < son[nHead].size(); i++)
	{
		ans[k].push_back(son[nHead][i]);
	}
}
void Solve()
{
	int i, j, k;
	for (i = 0; i < m; i++)
	{
		ans[i].clear();
		Input(i);
	}
	memset(visit, 0, sizeof(visit));
	for (i = 0; i < m; i++)
	{
		if (visit[i])
		{
			continue;
		}
		printf("%d ", i+1);
		for (j = i + 1; j < m; j++)
		{
			if (visit[j])
			{
				continue;
			}
			if (Comp(i, j))
			{
				visit[j] = 1;
				printf("= %d ", j+1);
			}
		}
		printf(";\n");
	}
}
int main()
{
	while (scanf("%d %d", &m, &n) != EOF)
	{
		Solve();
	}
	return 0;
}