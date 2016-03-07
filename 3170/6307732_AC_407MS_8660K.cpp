#include <iostream>
#include <queue>
#include <time.h>
using namespace std;
#define INF 10000000
short a[1010][1010];
int n, m;
bool visit[1010][1010];
int dist1[1010][1010], dist2[1010][1010];
int startx, starty, endx, endy;
int dir[4][2] = {{0,1},{0,-1}, {-1, 0}, {1, 0}};
struct ac
{
	int x, y, dis;
};
queue<ac>que;
int t;
void Input()
{
	int i, j;
	t = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			if (a[i][j] == 2)
			{
				startx = i;
				starty = j;
			}
			else if (a[i][j] == 3)
			{
				endx = i;
				endy = j;
			}
		}
	}
	for (i = 0; i <= n + 1; i++)
	{
		a[i][0] = 1;
		a[i][m+1] = 1;
	}
	for (j = 0; j <= m+1; j++)
	{
		a[0][j] = 1;
		a[n+1][j] = 1;
	}
}
void BFS(int x, int y)
{
	while (!que.empty())
	{
		que.pop();
	}
	memset(visit, 0, sizeof(visit));
	ac p, q;
	int i, dx, dy;
	p.x = x;
	p.y = y;
	p.dis = 0;
	que.push(p);
	while (!que.empty())
	{
		p = que.front();
		que.pop();
		if (dist1[p.x][p.y] < p.dis || visit[p.x][p.y])
		{
			continue;
		}
		visit[p.x][p.y] = true;
		q.dis = p.dis + 1;
		for (i = 0; i < 4; i++)
		{
			dx = p.x + dir[i][0];
			dy = p.y + dir[i][1];
			if (a[dx][dy] != 1 && dist1[dx][dy] > p.dis + 1 && !visit[dx][dy])
			{
				dist1[dx][dy] = p.dis + 1;
				q.x = dx;
				q.y = dy;
				que.push(q);
			}
		}
	}
}
void BFS2(int x, int y)
{
	while (!que.empty())
	{
		que.pop();
	}
	memset(visit, 0, sizeof(visit));
	ac p, q;
	int i, dx, dy;
	p.x = x;
	p.y = y;
	p.dis = 0;
	que.push(p);
	while (!que.empty())
	{
		p = que.front();
		que.pop();
		if (dist2[p.x][p.y] < p.dis || visit[p.x][p.y])
		{
			continue;
		}
		visit[p.x][p.y] = true;
		q.dis = p.dis + 1;
		for (i = 0; i < 4; i++)
		{
			dx = p.x + dir[i][0];
			dy = p.y + dir[i][1];
			if (a[dx][dy] != 1 && dist2[dx][dy] > p.dis + 1 && !visit[dx][dy])
			{
				dist2[dx][dy] = p.dis + 1;
				q.x = dx;
				q.y = dy;
				que.push(q);
			}
		}
	}
}
void Solve()
{
	int i, j;
	for (i = 0; i <= n+1; i++)
	{
		for (j = 0; j <= m+1; j++)
		{
			dist1[i][j] = INF;
			dist2[i][j] = INF;
		}
	}
	a[endx][endy] = 1;
	BFS(startx, starty);
	a[endx][endy] = 3;
	BFS2(endx, endy);
	int ans = INF;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (a[i][j] == 4)
			{
				if (dist1[i][j] + dist2[i][j] < ans)
				{
					ans = dist1[i][j] + dist2[i][j];
				}
			}
		}
	}
	printf("%d\n", ans);
}
int main()
{
//	int y, x = clock();
//	freopen("f:\\tmp\\ni.9.in", "r", stdin);
	scanf("%d %d", &m, &n);
	Input();
	Solve();
//	y = clock() - x;
//	cout << "time :   " << y << endl;
	return 0;
}