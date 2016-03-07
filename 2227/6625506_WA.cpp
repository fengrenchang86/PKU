#include <iostream>
#include <queue>
using namespace std;
#define INF 1000000000
struct ac
{
	__int64 nMax;
	int x, y;
	bool operator()(ac &m1, ac &m2)
	{
		return m1.nMax > m2.nMax;
	}
};
priority_queue<ac, vector<ac>, ac>que;
int a[310][310];
int b[310][310];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int n, m;
void Input()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
			b[i][j] = INF;
		}
	}
}
void Solve()
{
	int i, j;
	ac p, q;
	for (i = 0; i < n; i++)
	{
		p.x = i;
		p.y = 0;
		p.nMax = a[i][0];
		b[i][0] = a[i][0];
		que.push(p);
		p.y = m - 1;
		p.nMax = a[i][m-1];
		b[i][m-1] = a[i][m-1];
		que.push(p);
	}
	for (i = 1; i < m - 1; i++)
	{
		p.x = 0;
		p.y = i;
		p.nMax = a[0][i];
		b[0][i] = a[0][i];
		que.push(p);
		p.x = n - 1;
		p.nMax = a[n-1][i];
		b[n-1][i] = a[n-1][i];
		que.push(p);
	}
	while (!que.empty())
	{
		p = que.top();
		que.pop();
		if (p.nMax > b[p.x][p.y])
		{
			continue;
		}
		for (i = 0; i < 4; i++)
		{
			q.x = p.x + dir[i][0];
			q.y = p.y + dir[i][1];
			if (q.x >= 0 && q.x < n && q.y >= 0 && q.y < m)
			{
				if (b[q.x][q.y] > p.nMax)
				{
					if (p.nMax >= a[q.x][q.y])
					{
						q.nMax = p.nMax;
					}
					else
					{
						q.nMax = a[q.x][q.y];
					}
					b[q.x][q.y] = q.nMax;
					que.push(q);
				}
			}
		}
	}
/*
	printf("\nok!!!\n\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%3d", b[i][j]);
		}
		printf("\n");
	}
*/
}
int main()
{
	while (scanf("%d %d", &m, &n) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}