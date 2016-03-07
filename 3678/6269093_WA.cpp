#include <iostream>
#include <vector>
using namespace std;
#define N 2010
int ArrChoose[N], ArrDelete[N];
int visit[N];
vector<int>pList[N], pReverseList[N];
int n, m, nCount;
int nCountChoose, nCountDelete;
int t[N];
bool flag;
void Insert(int x, int y)
{
	pList[x].push_back(y);
	pReverseList[y].push_back(x);
}
void Input()
{
	int i, x, y, z;
	char chOpe[10];
	nCountChoose = 0;
	nCountDelete = 0;
	for (i = 0; i < 2 * n; i++)
	{
		pList[i].clear();
		pReverseList[i].clear();
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d %s", &x, &y, &z, &chOpe);
		if (strcmp(chOpe, "XOR") == 0)
		{
			if (z == 0)
			{
				Insert(2 * x, 2 * y);
				Insert(2 * y, 2 * x);
				Insert(2 * x + 1, 2 * y + 1);
				Insert(2 * y + 1, 2 * x + 1);
			}
			else
			{
				Insert(2 * x, 2 * y + 1);
				Insert(2 * y, 2 * x + 1);
				Insert(2 * x + 1, 2 * y);
				Insert(2 * y + 1, 2 * x);
			}
		}
		else if (strcmp(chOpe, "AND") == 0)
		{
			if (z == 1)
			{
				ArrChoose[nCountChoose++] = 2 * x + 1;
				ArrChoose[nCountChoose++] = 2 * y + 1;
				ArrDelete[nCountDelete++] = 2 * x;
				ArrDelete[nCountDelete++] = 2 * y;
			}
			else
			{
				Insert(2 * x + 1, 2 * y);
				Insert(2 * y + 1, 2 * x);
			}
		}
		else
		{
			if (z == 0)
			{
				ArrDelete[nCountDelete++] = 2 * x + 1;
				ArrDelete[nCountDelete++] = 2 * y + 1;
				ArrChoose[nCountChoose++] = 2 * x;
				ArrChoose[nCountChoose++] = 2 * y;
			}
			else
			{
				Insert(2 * x, 2 * y + 1);
				Insert(2 * y, 2 * x + 1);
			}
		}
	}
}
void dfs_Topo(int node)
{
	visit[node] = true;
	int i;
	for (i = 0; i < pList[node].size(); i++)
	{
		if (!visit[pList[node][i]])
		{
			dfs_Topo(pList[node][i]);
		}
	}
	t[nCount] = node;
	nCount++;
}
void dfs_Choose(int node)
{
	if (visit[node] == -1 || !flag)
	{
		flag = false;
		return;
	}
	visit[node] = 1;
	int i;
	for (i = 0; flag && i < pList[node].size(); i++)
	{
		if (visit[pList[node][i]] == 0)
		{
			dfs_Choose(pList[node][i]);
		}
		else if (visit[pList[node][i]] == -1)
		{
			flag = false;
			return;
		}
	}
}
void dfs_Delete(int node)
{
	if (visit[node] == 1 || !flag)
	{
		flag = false;
		return;
	}
	visit[node] = -1;
	int i;
	for (i = 0; flag && i < pReverseList[node].size(); i++)
	{
		if (visit[pReverseList[node][i]] == 0)
		{
			dfs_Delete(pReverseList[node][i]);
		}
		else if (visit[pReverseList[node][i]] == 1)
		{
			flag = false;
			return;
		}
	}
}
void Solve()
{
	flag = true;
	nCount = 0;
	memset(visit, 0, sizeof(visit));
	int i, k;
	for (i = 0; i < 2 * n; i++)
	{
		if (!visit[i])
		{
			dfs_Topo(i);
		}
	}
	memset(visit, 0, sizeof(visit));
	for (i = 0; flag && i < nCountChoose; i++)
	{
		dfs_Choose(ArrChoose[i]);
	}
	for (i = 0; flag && i < nCountDelete; i++)
	{
		dfs_Delete(ArrDelete[i]);
	}
	for (i = 0; flag && i < 2 * n; i++)
	{
		k = t[i];
		if (visit[k] == 0)
		{
			dfs_Choose(k);
			if (k % 2 == 1)
			{
				dfs_Delete(k - 1);
			}
			else
			{
				dfs_Delete(k + 1);
			}
		}
	}
	if (flag)
	{
		printf("YES\n");
		for (i = 0; i < n; i++)
		{
			if (visit[2 * i] == 1 && visit[2 * i + 1] == -1)
			{
				printf("x(%d) = 0\n", i);
			}
			else if (visit[2 * i] == -1 && visit[2 * i + 1] == 1)
			{
				printf("x(%d) = 1\n", i);
			}
			else
				printf("x(%d) = ?\n", i);
		}
	}
	else
	{
		printf("NO\n");
	}
}
int main()
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}