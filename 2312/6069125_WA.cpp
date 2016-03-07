#include <iostream>
#include <queue>
using namespace std;
#define INF 2000000000
struct ac
{
	int x, y;
	int dis;
	bool operator()(ac &m1, ac &m2)
	{
		return m1.dis > m2.dis;
	}
};
priority_queue<ac, vector<ac>, ac>que;
char a[340][340];
int w[340][340];
int n, m;
void Input()
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%s", &a[i]);
	}
}
void Solve()
{
	int i, j;
	int bx, by, ex, ey;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			w[i][j] = INF;
			if (a[i][j] == 'Y')
			{
				bx = i;
				by = j;
			}
			else if (a[i][j] == 'T')
			{
				ex = i;
				ey = j;
			}
		}
	}
	ac p, q;
	p.x = bx;
	p.y = by;
	p.dis = 0;
	while (!que.empty())
	{
		que.pop();
	}
	que.push(p);
	while (!que.empty())
	{
		p = que.top();
		que.pop();
		if (w[p.x][p.y] < p.dis)
		{
			continue;
		}
		if (p.x - 1 >= 0)
		{
			if (a[p.x-1][p.y] == 'B' && p.dis + 2 < w[p.x-1][p.y])
			{
				q.x = p.x - 1;
				q.y = p.y;
				q.dis = p.dis + 2;
				que.push(q);
				w[q.x][q.y] = q.dis;
			}
			else if ((a[p.x-1][p.y] == 'E'  || a[p.x-1][p.y] == 'B') && p.dis + 1 < w[p.x-1][p.y])
			{
				q.x = p.x - 1;
				q.y = p.y;
				q.dis = p.dis + 1;
				que.push(q);
				w[q.x][q.y] = q.dis;
			}
		}
		if (p.x + 1 < n)
		{
			if (a[p.x+1][p.y] == 'B' && p.dis + 2 < w[p.x+1][p.y])
			{
				q.x = p.x + 1;
				q.y = p.y;
				q.dis = p.dis + 2;
				que.push(q);
				w[q.x][q.y] = q.dis;
			}
			else if ((a[p.x+1][p.y] == 'E' || a[p.x+1][p.y] == 'T') && p.dis + 1 < w[p.x+1][p.y])
			{
				q.x = p.x + 1;
				q.y = p.y;
				q.dis = p.dis + 1;
				que.push(q);
				w[q.x][q.y] = q.dis;
			}
		}
		if (p.y - 1 >= 0)
		{
			if (a[p.x][p.y-1] == 'B' && p.dis + 2 < w[p.x][p.y-1])
			{
				q.x = p.x;
				q.y = p.y-1;
				q.dis = p.dis + 2;
				que.push(q);
				w[q.x][q.y] = q.dis;
			}
			else if ((a[p.x][p.y-1] == 'E' || a[p.x][p.y-1] == 'T') && p.dis + 1 < w[p.x][p.y-1])
			{
				q.x = p.x;
				q.y = p.y-1;
				q.dis = p.dis + 1;
				que.push(q);
				w[q.x][q.y] = q.dis;
			}
		}
		if (p.y + 1 < m)
		{
			if (a[p.x][p.y+1] == 'B' && p.dis + 2 < w[p.x][p.y+1])
			{
				q.x = p.x ;
				q.y = p.y+1;
				q.dis = p.dis + 2;
				que.push(q);
				w[q.x][q.y] = q.dis;
			}
			else if ((a[p.x][p.y+1] == 'E' || a[p.x][p.y+1] == 'T') && p.dis + 1 < w[p.x][p.y+1])
			{
				q.x = p.x;
				q.y = p.y+1;
				q.dis = p.dis + 1;
				que.push(q);
				w[q.x][q.y] = q.dis;
			}
		}
	}
	if (w[ex][ey] != INF)
	{
		printf("%d\n", w[ex][ey]);
	}
	else
	{
		printf("-1\n");
	}
}
int main()
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		Input();
		Solve();
	}
	return 0;
}