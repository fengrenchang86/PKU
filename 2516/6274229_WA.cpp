#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1000000000
short ArrNeed[60][60];
short ArrStorage[60][60];
int ArrCost[60][60][60];
int N, M, K, m;
int dist[104];
bool visit[104];
int preE[104];
struct EDGE
{
	int x, y;
	int RevId;
	int Rongliang;
	int Cost;
}e[5300];
vector<int>pList[104];
void Input()
{
	int i, j, k;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= K; j++)
		{
			scanf("%d", &ArrNeed[i][j]);
		}
	}
	for (i = 1; i <= M; i++)
	{
		for (j = 1; j <= K; j++)
		{
			scanf("%d", &ArrStorage[i][j]);
		}
	}
	for (k = 1; k <= K; k++)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				scanf("%d", &ArrCost[k][i][j]);
			}
		}
	}
}
void Build(int nGood)
{
	int i, j ,k;
	for (i = 0; i <= 2 * M + N + 1; i++)
	{
		pList[i].clear();
	}
	m = 0;
	for (i = 1; i <= M; i++)
	{
		e[m].x = 0;
		e[m].y = i;
		e[m].Rongliang = ArrStorage[i][nGood];
		e[m].Cost = 0;
		e[m].RevId = m + 1;
		pList[0].push_back(m);
		m++;
		e[m].x = i;
		e[m].y = 0;
		e[m].Rongliang = 0;
		e[m].Cost = 0;
		e[m].RevId = m - 1;
		pList[i].push_back(m);
		m++;
	}
	for (i = 1; i <= N; i++)
	{
		e[m].x = M + i;
		e[m].y = N + M + 1;
		e[m].Rongliang = ArrNeed[i][nGood];
		e[m].Cost = 0;
		e[m].RevId = m + 1;
		pList[M + i].push_back(m);
		m++;
		e[m].x = N + M + 1;
		e[m].y = M + i;
		e[m].Rongliang = 0;
		e[m].Cost = 0;
		e[m].RevId = m - 1;
		pList[N + M + 1].push_back(m);
		m++;
	}
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			e[m].x = j;
			e[m].y = M + i;
			e[m].Rongliang = INF;
			e[m].Cost = ArrCost[nGood][i][j];
			e[m].RevId = m + 1;
			pList[j].push_back(m);
			m++;
			e[m].x = M + i;
			e[m].y = j;
			e[m].Rongliang = 0;
			e[m].Cost = -ArrCost[nGood][i][j];
			e[m].RevId = m - 1;
			pList[M + i].push_back(m);
			m++;
		}
	}
}
int FindPath(int nGood)
{
	int i, j, k, nMin;
	int id;
	for (i = 0; i <= 101; i++)
	{
		dist[i] = INF;
		visit[i] = false;
		preE[i] = -1;
	}
	dist[0] = 0;
	for (i = 0; i <= M + N + 1; i++)
	{
		nMin = INF;
		k = -1;
		for (j = 0; j <= N + M + 1; j++)
		{
			if (!visit[j] && dist[j] < nMin)
			{
				nMin = dist[j];
				k = j;
			}
		}
		if (k == -1 || visit[k])
		{
			break;
		}
		visit[k] = true;
		for (j = 0; j < pList[k].size(); j++)
		{
			id = pList[k][j];
			if (dist[e[id].y] > dist[k] + e[id].Cost && e[id].Rongliang > 0)
			{
				dist[e[id].y] = dist[k] + e[id].Cost;
				preE[e[id].y] = id;
			}
		}
	}
	if (visit[N + M + 1] == false)
	{
		return 0;
	}
	k = N + M + 1;
	while (k != 0)
	{
		id = preE[k];
		e[id].Rongliang--;
		e[e[id].RevId].Rongliang++;
//		printf("%d---->%d  cost = %d\n", e[id].x, e[id].y, e[id].Cost);
		k = e[id].x;
	}
	return dist[N + M + 1];
}
void Solve()
{
	int i, j, k, l, t;
	int ans = 0;
	for (i = 1; i <= K; i++)
	{
		Build(i);
		k = 0;
		for (j = 1; j <= N; j++)
		{
			k += ArrNeed[j][i];
		}
		for (j = 0; j < k; j++)
		{
			t = FindPath(i);
			if (t == 0)
			{
				printf("-1\n");
				return;
			}
			ans += t;
		}
	}
	printf("%d\n", ans);
}
int main()
{
	while (scanf("%d %d %d", &N, &M, &K) != EOF)
	{
		if (N == 0 && M == 0 && K == 0)
		{
			break;
		}
		Input();
		Solve();
	}
	{
	}
	return 0;
}