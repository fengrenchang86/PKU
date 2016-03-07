#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1000000000
struct MACHINE
{
	int Rongliang;
	int In[15], Out[15];
}t[60];
struct EDGE
{
	int x, y;
	int rId;
	int Rongliang;
	int MaxRongliang;
	bool yes;
}e[20000];
int preE[200];
int c[200];
vector<int>pList[200];
int n, P, m;
int dist[200];
bool visit[200];
int GetMin(int x, int y)
{
	return x < y ? x : y;
}
bool IsConnect(int x, int y)
{
	int i;
	for (i = 0; i < P; i++)
	{
		if (t[x].Out[i] + t[y].In[i] == 1)
		{
			return false;
		}
	}
	return true;
}
void Input()
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &t[i].Rongliang);
		for (j = 0; j < P; j++)
		{
			scanf("%d", &t[i].In[j]);
		}
		for (j = 0; j < P; j++)
		{
			scanf("%d", &t[i].Out[j]);
		}
	}
}
int FindPath()
{
	int i, j, k, nMin, id;
	for (i = 0; i <= 2*n + 1; i++)
	{
		preE[i] = -1;
		dist[i] = INF;
		c[i] = 0;
		visit[i] = 0;
	}
	c[0] = INF;
	dist[0] = 0;
	for (i = 0; i <= 2 * n; i++)
	{
		nMin = INF;
		k = -1;
		for (j = 0; j <= 2 * n + 1; j++)
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
			if (dist[e[id].y] > dist[e[id].x] + 1 && e[id].Rongliang > 0)
			{
				dist[e[id].y] = dist[e[id].x] + 1;
				c[e[id].y] = GetMin(c[e[id].x], e[id].Rongliang);
				preE[e[id].y] = id;
			}
		}
	}
	if (dist[1] == INF)
	{
		return 0;
	}
	k = 1;
	while (k != 0)
	{
		id = preE[k];
		e[id].Rongliang -= c[1];
		e[e[id].rId].Rongliang += c[1];
		k = e[id].x;
	}
	return c[1];
}
void Solve()
{
	int i, j;
	m = 0;
	for (i = 0; i < 200; i++)
	{
		pList[i].clear();
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				e[m].x = 2 * i;
				e[m].y = 2 * i + 1;
				e[m].Rongliang = t[i].Rongliang;
				e[m].MaxRongliang = e[m].Rongliang;
				e[m].yes = false;
				e[m].rId = m + 1;
				pList[2 * i].push_back(m);
				m++;
 				e[m].x = 2 * i + 1;
				e[m].y = 2 * i;
				e[m].Rongliang = 0;
				e[m].MaxRongliang = e[m].Rongliang;
				e[m].yes = false;
				pList[2 * i + 1].push_back(m);
				e[m].rId = m - 1;
				m++;
				continue;
			}
			if (IsConnect(i, j))
			{
				e[m].x = 2 * i + 1;
				e[m].y = 2 * j;
				e[m].Rongliang = INF;
				e[m].rId = m + 1;
				e[m].MaxRongliang = e[m].Rongliang;
				e[m].yes = true;
				pList[2 * i + 1].push_back(m);
				m++;
				e[m].x = 2 * j;
				e[m].y = 2 * i + 1;
				e[m].Rongliang = 0;
				e[m].rId = m - 1;
				e[m].MaxRongliang = e[m].Rongliang;
				e[m].yes = false;
				pList[2 * j].push_back(m);
				m++;
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < P; j++)
		{
			if (t[i].In[j] == 1)
			{
				break;
			}
		}
		if (j == P)
		{
			e[m].x = 0;
			e[m].y = 2 * i;
			e[m].Rongliang = INF;
			e[m].yes = false;
			e[m].MaxRongliang = e[m].Rongliang;
			e[m].rId = m + 1;
			pList[0].push_back(m);
			m++;
			e[m].x = 2 * i;
			e[m].y = 0;
			e[m].Rongliang = 0;
			e[m].MaxRongliang = e[m].Rongliang;
			e[m].yes = false;
			e[m].rId = m - 1;
			pList[2 * i].push_back(m);
			m++;
		}
		for (j = 0; j < P; j++)
		{
			if (t[i].Out[j] != 1)
			{
				break;
			}
		}
		if (j == P)
		{
			e[m].x = 2 * i + 1;
			e[m].y = 1;
			e[m].Rongliang = INF;
			e[m].MaxRongliang = e[m].Rongliang;
			e[m].yes = false;
			e[m].rId = m + 1;
			pList[2 * i + 1].push_back(m);
			m++;
			e[m].x = 1;
			e[m].y = 2 * i + 1;
			e[m].Rongliang = 0;
			e[m].MaxRongliang = e[m].Rongliang;
			e[m].yes = false;
			e[m].rId = m - 1;
			pList[1].push_back(m);
			m++;
		}
	}
	i = 0;
	j = 1;
	while (j)
	{
		j = FindPath();
		i += j;
	}
	printf("%d", i);
	int id;
	j = 0;
	for (i = 0; i < m; i++)
	{
		if (e[i].yes == false)
		{
			continue;
		}
		if (e[i].Rongliang < e[i].MaxRongliang)
		{
			j++;
		}
	}
	printf(" %d\n", j);
	for (i = 0; i < m; i++)
	{
		if (e[i].yes == false)
		{
			continue;
		}
		if (e[i].Rongliang < e[i].MaxRongliang)
		{
			printf("%d %d %d\n", e[i].x/2, e[i].y/2, e[i].MaxRongliang - e[i].Rongliang);
		}
	}
}
int main()
{
	while (scanf("%d %d", &P, &n) != EOF)
	{
		if (P == 0 && m == 0)
		{
			break;
		}
		Input();
		Solve();
	}
	return 0;
}