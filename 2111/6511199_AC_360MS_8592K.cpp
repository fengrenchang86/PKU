#include <iostream>
#include <queue>
using namespace std;
#define INF 1000000000
int dist[365*400];
int a[400][400];
int n, m;
int ans;
int pList[365*400][10];
int pSize[365*400];
int DIR[8][2] = {{-1,-2},{-1,2},{1,-2},{1,2},{-2,-1},{-2,1},{2,-1},{2,1}};
int Degree[365*400];
struct acm
{
	int x, y;
}t[365*400];
void Insert(int x, int y)
{
	pList[x][pSize[x]] = y;
	pSize[x]++;
}
void Input()
{
	scanf("%d", &n);
	m = n * n;
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
			t[a[i][j]].x = i;
			t[a[i][j]].y = j;
			dist[i*n+j] = 1;
		}
	}
}
void dfs(int v)
{
	Degree[v]--;
	int i;
	for (i = 0; i < pSize[v]; i++)
	{
		Degree[pList[v][i]]--;
		if (dist[pList[v][i]] < dist[v] + 1)
		{
			dist[pList[v][i]] = dist[v] + 1;
			if (dist[v] + 1 > ans)
			{
				ans = dist[v] + 1;
			}
		}
		if (Degree[pList[v][i]] == 0)
		{
			dfs(pList[v][i]);
		}
	}
}
bool flag;
int path[365*400];
void acdfs(int v, int step)
{
	int i;
	if (dist[v] != step || flag)
	{
		return;
	}
	else if (step == ans)
	{
		flag = true;
		printf("%d\n", ans);
		for (i = 1; i <= ans; i++)
		{
			printf("%d\n", a[path[i]/n][path[i]%n]);
		}
		return;
	}
	for (i = 0; i < pSize[v]; i++)
	{
		path[step + 1] = pList[v][i];
		acdfs(pList[v][i], step + 1);
	}
}
void Solve()
{
	flag = false;
	int i, j, k;
	int dx, dy;
	for (i = 0; i <= m; i++)
	{
		pSize[i] = 0;
		Degree[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < 8; k++)
			{
				dx = i + DIR[k][0];
				dy = j + DIR[k][1];
				if (dx >= 0 && dx < n && dy >= 0 && dy < n && a[i][j] < a[dx][dy])
				{
					Insert(i * n + j, dx * n + dy);
					Degree[dx * n + dy] ++;
				}
			}
		}
	}
	for (i = 0; i < m; i++)
	{
		if (Degree[i] == 0)
		{
			dfs(i);
		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < pSize[i]; j++)
		{
			for (k = j + 1; k < pSize[i]; k++)
			{
				if (a[pList[i][j]/n][pList[i][j]%n] > a[pList[i][k]/n][pList[i][k]%n])
				{
					dx = pList[i][j];
					pList[i][j] = pList[i][k];
					pList[i][k] = dx;
				}
			}
		}
	}
	for (i = 1; i <= m; i++)
	{
		path[1] = t[i].x * n + t[i].y;
		acdfs(t[i].x * n + t[i].y, 1);
	}
}
int main()
{
//	freopen("f:\\udata\\leap2.8.in", "r", stdin);
	Input();
	Solve();
	return 0;
}