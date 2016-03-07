#include <iostream>
#include <queue>
using namespace std;
#define inf 2000000000
int n, m, t;
int startX, startY, startZ;
char a[32][32][32];
int dis[32][32][32];
int dir[6][3] = {{0,0,1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};
struct ac
{
	int x, y, z, step;
	bool operator()(ac &m1, ac &m2)
	{
		return m1.step > m2.step;
	}
};
priority_queue<ac, vector<ac>, ac>que;
void Input()
{
	int i, j, k;
	for(i = 0; i < t; i++)
	{
		for(j = 0; j < n; j++)
			scanf(" %s", &a[i][j]);
	}
	for(i = 0; i < t; i++)
	{
		for(j = 0; j < n; j++)
		{
			for(k = 0; k < m; k++)
			{
				dis[i][j][k] = inf;
				if(a[i][j][k] == 'S')
				{
					startX = i;
					startY = j;
					startZ = k;
				}
			}
		}
	}
}
int Solve()
{
	ac p, q;
	int i;
	p.x = startX;
	p.y = startY;
	p.z = startZ;
	p.step = 0;
	dis[p.x][p.y][p.z] = 0;
	while(!que.empty())
		que.pop();
	que.push(p);
	while(!que.empty())
	{
		p = que.top();
		que.pop();
		if(dis[p.x][p.y][p.z] < p.step)
			continue;
		if(a[p.x][p.y][p.z] == 'E')
			return p.step;
		q.step = p.step + 1;
		for(i = 0; i < 6; i++)
		{
			q.x = p.x + dir[i][0];
			q.y = p.y + dir[i][1];
			q.z = p.z + dir[i][2];
			if(q.x >= 0 && q.x < t && q.y >= 0 && q.y < n && q.z >= 0 && q.z < m && a[q.x][q.y][q.z] != '#' && q.step < dis[q.x][q.y][q.z])
			{
				dis[q.x][q.y][q.z] = q.step;
				que.push(q);
			}
		}
	}
	return -1;
}
int main()
{
	int k;
	while(scanf("%d %d %d", &t, &n, &m) != EOF)
	{
		if(n == 0 && t == 0 && m == 0)
			break;
		Input();
		k = Solve();
		if(k == -1)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n", k);
	}
	return 0;
}