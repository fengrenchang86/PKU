#include <iostream>
#include <queue>
using namespace std;
#define INF 1000000000
int dist[400][400];
int a[400][400];
int n, m;
struct ac
{
	int x, y, dist;
};
struct wf
{
	int x, y;
}t[365*400], path[400][400];
queue<ac>que;
int dir[8][2] = {{-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {-2, -1}, {-2, 1}, {2, -1}, {2, 1}};
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
			dist[i][j] = 1;
			path[i][j].x = -1;
			path[i][j].y = -1;
		}
	}
}
void bfs(int x, int y)
{
	if (dist[x][y] > 1)
	{
		return;
	}
	int i;
	ac p, q;
	while (!que.empty())
	{
		que.pop();
	}
	p.x = x;
	p.y = y;
	p.dist = 1;
	que.push(p);
	while (!que.empty())
	{
		p = que.front();
		que.pop();
		if (dist[p.x][p.y] > p.dist)
		{
			continue;
		}
		q.dist = p.dist + 1;
		for (i = 0; i < 8; i++)
		{
			q.x = p.x + dir[i][0];
			q.y = p.y + dir[i][1];
			if (q.x >= 0 && q.x < n && q.y >= 0 && q.y < n && a[q.x][q.y] > a[p.x][p.y] && dist[q.x][q.y] < q.dist)
			{
				dist[q.x][q.y] = q.dist;
				path[q.x][q.y].x = p.x;
				path[q.x][q.y].y = p.y;
				que.push(q);
			}
		}
	}
}
void ShowAns(int x, int y)
{
	if (x >= 0 && y >= 0)
	{
		ShowAns(path[x][y].x, path[x][y].y);
		printf("%d\n", a[x][y]);
	}
	
}
void Solve()
{
	int i, j, ans;
	ac p;
	p.x = 0;
	p.y = 0;
	for (i = 1; i <= m; i++)
	{
		bfs(t[i].x, t[i].y);
	}
	ans = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (dist[i][j] > ans)
			{
				ans = dist[i][j];
				p.x = i;
				p.y = j;
			}
		}
	}
	printf("%d\n", ans);
	ShowAns(p.x, p.y);
}
int main()
{
//	freopen("f:\\udata\\leap2.8.in", "r", stdin);
	Input();
	Solve();
	return 0;
}