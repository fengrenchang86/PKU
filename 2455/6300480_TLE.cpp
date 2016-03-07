#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 1000000000
struct EDGE
{
	int preid;
	int x, y;
	int cost;
}e[91000];
vector<int>pList[250];
queue<int>que;
int N, M, m , L;
bool bInQue[250];
int preE[50010];
int c[250][250];
void Input()
{
	scanf("%d %d %d", &N, &M, &L);
	int i, x, y, len;
	m = 0;
	for (i = 0; i < M; i++)
	{
		scanf("%d %d %d", &x, &y, &len);
		e[m].x = x;
		e[m].y = y;
		e[m].cost = len;
		e[m].preid = m + 1;
		pList[x].push_back(m);
		m++;
		e[m].x = y;
		e[m].y = x;
		e[m].cost = len;
		e[m].preid = m - 1;
		pList[y].push_back(m);
		m++;
	}
}
void dfs(int node)
{
	int i;
	bInQue[node] = true;
	for (i = 1; i <= N; i++)
	{
		if (c[node][i] > 0 && !bInQue[i])
		{
			preE[i] = node;
			dfs(i);
		}
	}
}
int FindMax(int nMaxEdge)
{
	int i, nTop, id;
	for (i = 0; i <= N; i++)
	{
		bInQue[i] = false;
		preE[i] = -1;
	}
	dfs(1);
	if (!bInQue[N])
	{
		return 0;
	}
	/*
	while (!que.empty())
		{
			que.pop();
		}
		dist[1] = 0;
		que.push(1);
		bInQue[0] = true;
		while (!que.empty())
		{
			nTop = que.front();
			que.pop();
			if (queCount[nTop] == N)
			{
				return 0;
			}
			bInQue[nTop] = false;
			for (i = 0; i < pList[nTop].size(); i++)
			{
				id = pList[nTop][i];
				if (e[id].rongliang > 0 && e[id].cost <= nMaxEdge && dist[e[id].y] > dist[nTop] + 1)
				{
					dist[e[id].y] = dist[nTop] + 1;
					preE[e[id].y] = id;
					if (bInQue[e[id].y] == false)
					{
						queCount[e[id].y]++;
						que.push(e[id].y);
						bInQue[e[id].y] = true;
					}
				}
			}
		}
	
	nTop = N;
	if (dist[N] == INF)
	{
		return 0;
	}*/
	nTop = N;
	if (bInQue[nTop] == 0)
	{
		return 0;
	}
	int k = INF;
	while (nTop != 1)
	{
		id = preE[nTop];
		if (k > c[id][nTop])
		{
			k = c[id][nTop];
		}
		nTop = id;
	}
	nTop = N;
	while (nTop != 1)
	{
		id = preE[nTop];
		c[id][nTop] -= k;
		c[nTop][id] += k;
		nTop = id;
	}
	return k;
}
int FindMaxLoop(int nMaxEdge)
{
	int i, j, k = 0;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			c[i][j] = 0;
		}
	}
	for (i = 0; i < m; i++)
	{
		if (e[i].cost <= nMaxEdge)
		{
			c[e[i].x][e[i].y]++;
		}
	}
	for (i = 0; k < L && i < L; i++)
	{
		j = FindMax(nMaxEdge);
		if (j == 0)
		{
			return 0;
		}
		k += j;
	}
	if (k >= L)
	{
		return 1;
	}
	return 0;
}
void Solve()
{
	int nBegin, nEnd, nMid;
	nBegin = 1;
	nEnd = 1000000;
	int j;
	while (nBegin < nEnd)
	{
		nMid = (nBegin + nEnd) / 2;
		j = FindMaxLoop(nMid);
		if (j == 1)
		{
			nEnd = nMid;
		}
		else
		{
			nBegin = nMid + 1;
		}
	}
	printf("%d\n", nBegin);
}
int main()
{
	Input();
	Solve();
	return 0;
}