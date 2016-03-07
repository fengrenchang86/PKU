#include <iostream>
#include <queue>
using namespace std;
#define INF 1000000
int n;
int a[120][120];
int w[120][120];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
struct ac
{
	int x, y, z;
};
queue<ac>que;
int bfs(int nMaxVal)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			w[i][j] = INF;
		}
	}
	ac q, p;
	p.x = 0;
	p.y = 0;
	p.z = a[i][j];
	w[0][0] = p.z;
	que.push(p);
	while (!que.empty())
	{
		p = que.front();
		que.pop();
		if (p.z > w[p.x][p.y])
		{
			continue;
		}
		for (i = 0; i < 4; i++)
		{
			q.x = p.x + dir[i][0];
			q.y = p.y + dir[i][1];
			if (q.x < 0 || q.x >= n || q.y < 0 || q.y >= n || a[q.x][q.y] < nMaxVal)
			{
				continue;
			}
			if (p.z > a[q.x][q.y])
			{
				j = p.z;
			}
			else
			{
				j = a[q.x][q.y];
			}
			if (j < w[q.x][q.y])
			{
				w[q.x][q.y] = j;
				q.z = j;
				que.push(q);
			}
		}
	}
	return w[n-1][n-1] - nMaxVal;
}
void Solve()
{
	int i;
	int ans = INF;
	for (i = 0; i <= 110; i++)
	{
		int j = bfs(i);
		if (j > 0 && j < ans)
		{
			ans = j;
		}
	}
	printf("%d\n", ans);
}
int main()
{
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	Solve();
	return 0;
}