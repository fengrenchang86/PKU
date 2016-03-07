#include <iostream>
#include <vector>
using namespace std;
#define INF 2000000000
int visit[10200];
int f[10200];
vector<int>pList[10200];
int nCount;
int w[10200];
int val[10200];
int n;
void dfs_Topo(int node)
{
	int i, k;
	visit[node] = 1;
	for (i = 0; i < pList[node].size(); i++)
	{
		if (!visit[pList[node][i]])
		{
			dfs_Topo(pList[node][i]);
		}
	}
	f[nCount] = node;
	nCount++;
}
void dfs(int node)
{
	int i, k = 0;
	visit[node] = 1;
	for (i = 0; i < pList[node].size(); i++)
	{
		if (!visit[pList[node][i]])
		{
			dfs(pList[node][i]);
		}
		if (w[pList[node][i]] > k)
		{
			k = w[pList[node][i]];
		}
	}
	w[node] = k + val[node];
}
void Input()
{
	scanf("%d", &n);
	int i, j, k, y;
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d", &val[i], &k);
		for (j = 0; j < k; j++)
		{
			scanf("%d", &y);
			pList[i].push_back(y);
		}
		visit[i] = 0;
	}
}
void Solve()
{
	int i, k = 0;
	nCount = 1;
	for (i = 1; i <= n; i++)
	{
		if (!visit[i])
		{
			dfs_Topo(i);
		}
	}
	memset(visit, 0, sizeof(visit));
	for (i = 1; i <= n; i++)
	{
		if (!visit[f[i]])
		{
			dfs(f[i]);
			if (w[f[i]] > k)
			{
				k = w[f[i]];
			}
		}
	}
	printf("%d\n", k);
}
int main()
{
	Input();
	Solve();
	return 0;
}