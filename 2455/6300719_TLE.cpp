#include <iostream>
//#include <time.h>
#include <queue>
#include <vector>
#include <stdlib.h>
using namespace std;
#define INF 1000000000
int dislen[50000];
struct EDGE
{
	int x, y;
	int cost;
}e[91000];
queue<int>que;
int N, M, m , L, CountLen;
bool bInQue[250];
int preE[50010];
int c[250][250];
int w[250];
int cmp(const void*a, const void*b)
{
	return *(int*)a - *(int*)b;
}
void Input()
{
	scanf("%d %d %d", &N, &M, &L);
	int i, x, y, len;
	m = 0;
	int j = 0;
	for (i = 0; i < M; i++)
	{
		scanf("%d %d %d", &x, &y, &len);
		e[m].x = x;
		e[m].y = y;
		e[m].cost = len;
		m++;
/*
		e[m].x = y;
		e[m].y = x;
		e[m].cost = len;
		e[m].preid = m - 1;
		pList[y].push_back(m);
		m++;*/

		dislen[j++] = len;
	}
	qsort(dislen, j, sizeof(dislen[0]), cmp);
	CountLen = 1;
	for (i = 1; i < j; i++)
	{
		if (dislen[i] != dislen[i-1])
		{
			dislen[CountLen++] = dislen[i];
		}
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
int GetMin(int x, int y)
{
	return x < y ? x : y;
}
int FindMax(int nMaxEdge)
{
	int i, nTop, id;
	for (i = 0; i <= N; i++)
	{
		bInQue[i] = false;
		preE[i] = -1;
		w[i] = 0;
	}
//	dfs(1);
	w[1] = L;
	int j, k, nMax, t;
	for (i = 0; i < N; i++)
	{
		nMax = -1;
		k = -1;
		for (j = 1; j <= N; j++)
		{
			if (bInQue[j] == false && w[j] > nMax)
			{
				nMax = w[j];
				k = j;
			}
		}
		if (k == -1 || nMax == -1)
		{
			break;
		}
		bInQue[k] = true;
		if (k == N)
		{
			break;
		}
		for (j = 1; j <= N; j++)
		{
			if (!bInQue[j] && c[k][j] > 0)
			{
				t = GetMin(w[k], c[k][j]);
				if (w[j] < t)
				{
					w[j] = t;
					preE[j] = k;
				}
			}
		}
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
	if (bInQue[nTop] == 0 || preE[nTop] == -1)
	{
		return 0;
	}
	k = INF;
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
			c[e[i].y][e[i].x]++;
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
	nBegin = 0;
	nEnd = CountLen-1;
	int j;
	while (nBegin < nEnd)
	{
		nMid = (nBegin + nEnd) / 2;
		j = FindMaxLoop(dislen[nMid]);
		if (j == 1)
		{
			nEnd = nMid;
		}
		else
		{
			nBegin = nMid + 1;
		}
	}
	printf("%d\n", dislen[nBegin]);
}
int main()
{
	Input();
	Solve();
	/*
	int x, y;
		x = clock();
		freopen("f:\\tmp\\secret.1.in", "r", stdin);
		Input();
		Solve();
		y = clock() - x;
		cout << "time:  " << y << endl;
		x = clock();
		freopen("f:\\tmp\\secret.2.in", "r", stdin);
		Input();
		Solve();
		y = clock() - x;
		cout << "time:  " << y << endl;
		x = clock();
		freopen("f:\\tmp\\secret.3.in", "r", stdin);
		Input();
		Solve();
		y = clock() - x;
		cout << "time:  " << y << endl;
		x = clock();
		freopen("f:\\tmp\\secret.4.in", "r", stdin);
		Input();
		Solve();
		y = clock() - x;
		cout << "time:  " << y << endl;
		x = clock();
		freopen("f:\\tmp\\secret.5.in", "r", stdin);
		Input();
		Solve();
		y = clock() - x;
		cout << "time:  " << y << endl;
		x = clock();
		freopen("f:\\tmp\\secret.6.in", "r", stdin);
		Input();
		Solve();
		y = clock() - x;
		cout << "time:  " << y << endl;
		x = clock();
		freopen("f:\\tmp\\secret.7.in", "r", stdin);
		Input();
		Solve();
		y = clock() - x;
		cout << "time:  " << y << endl;
		x = clock();
		freopen("f:\\tmp\\secret.8.in", "r", stdin);
		Input();
		Solve();
		y = clock() - x;
		cout << "time:  " << y << endl;
		x = clock();
		freopen("f:\\tmp\\secret.9.in", "r", stdin);
		Input();
		Solve();
		y = clock() - x;
		cout << "time:  " << y << endl;
		x = clock();
		freopen("f:\\tmp\\secret.10.in", "r", stdin);
		Input();
		Solve();
		y = clock() - x;
		cout << "time:  " << y << endl;*/
	
	return 0;
}