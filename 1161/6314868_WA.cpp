#include <iostream>
using namespace std;
#define INF 10000000
struct ac
{
	int num;
	int node[300];
}t[300];
bool c[260][260];
bool visit[260];
int n, m, l;
int a[100];
int dist[300], FinalDist[300];
bool CheckConnect(int x, int y)
{
	int i, j;
	for (i = 0; i < t[x].num; i++)
	{
		for (j = 0; j < t[y].num; j++)
		{
			if (t[x].node[i] == t[y].node[j] && t[x].node[(i+1)%t[x].num] == t[y].node[(j+1)%t[y].num])
			{
				return true;
			}
			else if (t[x].node[i] == t[y].node[(j+1)%t[y].num] && t[x].node[(i+1)%t[x].num] == t[y].node[j])
			{
				return true;
			}
		}
	}
	return false;
}
void dij(int v)
{
	int i, j, k, nMin;
	for (i = 0; i < m; i++)
	{
		visit[i] = 0;
		dist[i] = INF;
		for (j = 0; j < t[i].num; j++)
		{
			if (v == t[i].node[j])
			{
				dist[i] = 0;
				break;
			}
		}
	}
	for (i = 0; i < m; i++)
	{
		nMin = INF;
		k = -1;
		for (j = 0; j < m; j++)
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
		for (j = 0; j < m; j++)
		{
			if (!visit[j] && dist[j] > dist[k] + 1)
			{
				dist[j] = dist[k] + 1;
			}
		}
	}
	for (i = 0; i < m; i++)
	{
		FinalDist[i] += dist[i];
	}
}
int main()
{
	int i, j, k;
	memset(c, 0, sizeof(c));
	memset(visit, 0, sizeof(visit));
	memset(FinalDist, 0, sizeof(FinalDist));
	scanf("%d %d %d", &m, &n, &l);
	for (i = 0; i < l; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d", &t[i].num);
		for (j = 0; j < t[i].num; j++)
		{
			scanf("%d", &t[i].node[j]);
		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = i + 1; j < m; j++)
		{
			if (CheckConnect(i, j))
			{
				c[i][j] = c[j][i] = 1;
			}
		}
	}
	for (i = 0; i < l; i++)
	{
		dij(a[i]);
	}
	k = INF;
	for (i = 0; i < m; i++)
	{
		if (FinalDist[i] < k)
		{
			k = FinalDist[i];
		}
	}
	printf("%d\n", k);
	return 0;
}