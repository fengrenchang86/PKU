#include <iostream>
#include <vector>
using namespace std;
#define INF 1000000000
struct EDGE
{
	int x, y;
	int Rongliang;
	int RevId;
}e[50000];
struct data
{
	int day[10];
	int w, d;
}t[30];
vector<int>pList[500];
int nMaxWeek;
int n, m;
int FINAL, nFlow;
int dist[500];
int preE[500];
bool visit[500];
void Input()
{
	int i, j;
	nMaxWeek = 0;
	nFlow = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < 7; j++)
		{
			scanf("%d", &t[i].day[j]);
		}
		scanf("%d %d", &t[i].d, &t[i].w);
		if (t[i].w > nMaxWeek)
		{
			nMaxWeek = t[i].w;
		}
		nFlow += t[i].d;
	}
	FINAL = n + 7 * nMaxWeek + 1;
}
void Build()
{
	int i, j, k;
	m = 0;
	for (i = 0; i <= FINAL; i++)
	{
		pList[i].clear();
	}
	for (i = 1; i <= n; i++)
	{
		e[m].x = 0;
		e[m].y = i;
		e[m].Rongliang = t[i].d;
		e[m].RevId = m + 1;
		pList[0].push_back(m);
		m++;
		e[m].x = i;
		e[m].y = 0;
		e[m].Rongliang = 0;
		e[m].RevId = m - 1;
		pList[i].push_back(m);
		m++;
	}
	for (i = 1; i <= n; i++)
	{
		for (k = 0; k < 7; k++)
		{
			if (t[i].day[k] == 0)
			{
				continue;
			}
			for (j = 0; j < t[i].w; j++)
			{
				e[m].x = i;
				e[m].y = n + (7 * j + k) + 1;
				e[m].Rongliang = 1;
				e[m].RevId = m + 1;
				pList[i].push_back(m);
				m++;
				e[m].x = n + (7 * j + k + 1);
				e[m].y = i;
				e[m].Rongliang = 0;
				e[m].RevId = m - 1;
				pList[n + 7 * j + k + 1].push_back(m);
				m++;
			}
		}
	}
	for (j = 0; j < nMaxWeek; j++)
	{
		for (k = 0; k < 7; k++)
		{
			e[m].x = n + 7 * j + k + 1;
			e[m].y = FINAL;
			e[m].Rongliang = 1;
			e[m].RevId = m + 1;
			pList[n + 7 * j + k + 1].push_back(m);
			m++;
			e[m].x = FINAL;
			e[m].y = n + 7 * j + k + 1;
			e[m].Rongliang = 0;
			e[m].RevId = m - 1;
			pList[FINAL].push_back(m);
			m++;
		}
	}
}
int FindPath()
{
	int i, j, k, nMin;
	int id;
	for (i = 0; i <= FINAL; i++)
	{
		visit[i] = false;
		preE[i] = -1;
		dist[i] = INF;
	}
	dist[0] = 0;
	for (i = 0; i <= FINAL; i++)
	{
		nMin = INF;
		k = -1;
		for (j = 0; j <= FINAL; j++)
		{
			if (!visit[j] && dist[j] < nMin)
			{
				nMin = dist[j];
				k = j;
				if (nMin == 0)
				{
					break;
				}
			}
		}
		if (k == -1 || nMin == INF)
		{
			break;
		}
		visit[k] = true;
		for (j = 0; j < pList[k].size(); j++)
		{
			id = pList[k][j];
			if (dist[e[id].y] > dist[k] + 1 && e[id].Rongliang > 0)
			{
				dist[e[id].y] = dist[k] + 1;
				preE[e[id].y] = id;
			}
		}
	}
	if (visit[FINAL] == false)
	{
		return 0;
	}
	k = FINAL;
	while (k != 0)
	{
		id = preE[k];
		e[id].Rongliang--;
		e[e[id].RevId].Rongliang++;
//		printf("id = %d %d %d\n", id, e[id].x, e[id].y);
		k = e[id].x;
	}
//	printf("***************************\n");
	return 1;
}
void Solve()
{
	Build();
	int j, k = 0;
	while (k < nFlow)
	{
		j = FindPath();
		if (j == 0)
		{
			break;
		}
		k += j;
	}
	if (k == nFlow)
	{
		printf("Yes\n");
	}
	else
	{
//		printf("Flow = %d\n", k);
		printf("No\n");
	}
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		Input();
		Solve();
	}
	return 0;
}