#include <iostream>
#include <queue>
using namespace std;
#define inf 2000000000
int c[251001][3];
char a[501][501];
int StartI, StartJ, EndI, EndJ;
int n, m;
struct ac
{
	int i, j, step, val;
	bool operator()(ac &m1, ac &m2)
	{
		return m1.step > m2.step;
	}
};
priority_queue<ac, vector<ac>, ac>que;
void Input()
{
	int i, j;
	bool x = false, y = false;
	for(i = 0; i < n; i++)
		scanf(" %s", &a[i]);
	EndJ = 0;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			if(a[i][j] == 'O' && !x)
			{
				EndI = i * m + j;
				x = true;
			}
			else if(a[i][j] == 'X' && !y)
			{
				y = true;
				StartI = i * m + j;
				if(i+1 < n && a[i+1][j] == 'X')
					StartJ = 2;
				else if(j+1 < m && a[i][j+1] == 'X')
					StartJ = 1;
				else
					StartJ = 0;
			}
		}
	}
	j = n*m;
	for(i = 0; i < j; i++)
	{
		c[i][0] = c[i][1] = c[i][2] = inf;
	}
	while(!que.empty())
		que.pop();
}
void Solve()
{
	int endx, endy;
	endx = EndI/m;
	endy = EndI%m;
	int x, y;
	ac p, q;
	c[StartI][StartJ] = 0;
	p.i = StartI;
	p.j = StartJ;
	p.step = 0;
	p.val = 0;
	que.push(p);
	while(!que.empty())
	{
		p = que.top();
		que.pop();
		if(c[p.i][p.j] < p.step)
			continue;
		else if(p.i == EndI && p.j == EndJ)
			break;
		x = p.i / m;
		y = p.i % m;
		q.step = p.step+1;
		if(p.j == 0)
		{
			if(y > 1 && a[x][y-1] != '#' && a[x][y-2] != '#')
			{
				q.i = x*m + y-2;
				q.j = 1;
				q.val = abs(x-endx)+abs(y-2-endy);
				if(c[q.i][q.j] > q.step)
				{
					c[q.i][q.j] = q.step;
					que.push(q);
				}
			}
			if(y+2 < m && a[x][y+1] != '#' && a[x][y+2] != '#')
			{
				q.i = x*m+y+1;
				q.j = 1;
				q.val = abs(x-endx)+abs(y+1-endy);
				if(c[q.i][q.j] > q.step)
				{
					c[q.i][q.j] = q.step;
					que.push(q);
				}
			}
			if(x > 1 && a[x-1][y] != '#' && a[x-2][y] != '#')
			{
				q.i = m*(x-2) + y;
				q.j = 2;
				q.val = abs(x-2-endx) + abs(y-endy);
				if(c[q.i][q.j] > q.step)
				{
					c[q.i][q.j] = q.step;
					que.push(q);
				}
			}
			if(x+2 < n && a[x+1][y] != '#' && a[x+2][y] != '#')
			{
				q.i = m*(x+1) + y;
				q.j = 2;
				q.val = abs(x+1-endx) + abs(y- endy);
				if(c[q.i][q.j] > q.step)
				{
					c[q.i][q.j] = q.step;
					que.push(q);
				}
			}
		}
		else if(p.j == 1)
		{
			if(y > 1 && a[x][y-1] != '#' && a[x][y-1] != 'E')
			{
				q.i = m*x+y-1;
				q.j = 0;
				q.val = abs(x-endx) + abs(y-1-endy);
				if(c[q.i][q.j] > q.step)
				{
					c[q.i][q.j] = q.step;
					que.push(q);
				}
			}
			if(y+2 < m && a[x][y+2] != '#' && a[x][y+2] != 'E')
			{
				q.i = m*x+y+2;
				q.j = 0;
				q.val = abs(x-endx) + abs(y+2-endy);
				if(c[q.i][q.j] > q.step)
				{
					c[q.i][q.j] = q.step;
					que.push(q);
				}
			}
			if(x > 1 && a[x-1][y] != '#' && a[x-1][y+1] != '#')
			{
				q.i = m*(x-1) + y;
				q.j = 1;
				q.val = abs(x-1-endx) + abs(y-endy);
				if(c[q.i][q.j] > q.step)
				{
					c[q.i][q.j] = q.step;
					que.push(q);
				}
			}
			if(x+1 < n && a[x+1][y] != '#' && a[x+1][y+1] != '#')
			{
				q.i = m*(x+1) + y;
				q.j = 1;
				q.val = abs(x+1-endx) + abs(y-endy);
				if(c[q.i][q.j] > q.step)
				{
					c[q.i][q.j] = q.step;
					que.push(q);
				}
			}
		}
		else
		{
			if(y > 0 && a[x][y-1] != '#' && a[x+1][y-1] != '#')
			{
				q.i = m*x + y-1;
				q.j = 2;
				q.val = abs(x-endx) + abs(y-1-endy);
				if(c[q.i][q.j] > q.step)
				{
					c[q.i][q.j] = q.step;
					que.push(q);
				}
			}
			if(y+1 < m && a[x][y+1] != '#' && a[x+1][y+1] != '#')
			{
				q.i = m*x+y+1;
				q.j = 2;
				q.val = abs(x-endx) + abs(y+1-endy);
				if(c[q.i][q.j] > q.step)
				{
					c[q.i][q.j] = q.step;
					que.push(q);
				}
			}
			if(x > 0 && a[x-1][y] != '#' && a[x-1][y] != 'E')
			{
				q.i = m*(x-1) + y;
				q.j = 0;
				q.val = abs(x-1-endx) + abs(y-endy);
				if(c[q.i][q.j] > q.step)
				{
					c[q.i][q.j] = q.step;
					que.push(q);
				}
			}
			if(x+2 < n && a[x+2][y] != '#' && a[x+2][y] != 'E')
			{
				q.i = m*(x+2)+y;
				q.j = 0;
				q.val = abs(x+2-endx) + abs(y-endy);
				if(c[q.i][q.j] > q.step)
				{
					c[q.i][q.j] = q.step;
					que.push(q);
				}
			}
		}
	}
	if(c[EndI][EndJ] == inf)
		printf("Impossible\n");
	else
		printf("%d\n", c[EndI][EndJ]);
}
int main ()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		if(n == 0 && m == 0)
			break;
		Input();
		Solve();
	}
	return 0;
}