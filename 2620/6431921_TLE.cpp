#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
using namespace std;
#define INF 2000000000
struct ac
{
	int x, y;
}t[111000];
struct acm
{
	int v;
	int dis;
	bool operator()(acm &m1, acm &m2)
	{
		if (m1.dis != m2.dis)
		{
			return m1.dis > m2.dis;
		}
		else
		{
			return t[m1.v].y < t[m2.v].y;
		}
	}
};
priority_queue<acm, vector<acm>, acm>que;
int m, n;
vector<int>pList[111000];
bool visit[111000];
int dist[111000];
int path[111000];
int cmp(const void *a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	if (c->x != d->x)
	{
		return c->x - d->x;
	}
	else
	{
		return c->y - d->y;
	}
}
void Input()
{
	n = 0;
	while (scanf("%d %d", &t[n].x, &t[n].y) != EOF)
	{
		if (t[n].x == 0 && t[n].y == 0)
		{
			break;
		}
		if (t[n].y < 0 || t[n].x > m)
		{
			continue;
		}
		pList[n].clear();
		n++;
	}
	qsort(t, n, sizeof(t[0]), cmp);
	int i, j = 0;
	for (i = 1; i < n; i++)
	{
		if (t[i].x == t[j].x && t[i].y > t[j].y)
		{
			t[j] = t[i];
		}
		else
		{
			j++;
			t[j] = t[i];
		}
	}
	n = j + 1;
}
int dij()
{
	while (!que.empty())
	{
		que.pop();
	}
	acm p, q;
	int i, j, k;
	p.dis = 1;
	for (i = 0; i < n; i++)
	{
		if (t[i].x * t[i].y <= 0)
		{
			dist[i] = 1;
			p.v = i;
			que.push(p);
		}
		else
		{
			dist[i] = INF;
		}
		visit[i] = false;
		path[i] = -1;
	}
	while (!que.empty())
	{
		p = que.top();
		que.pop();
		if (p.dis > dist[p.v] || visit[p.v])
		{
			continue;
		}
		visit[p.v] = true;
		for (i = 0; i < pList[p.v].size(); i++)
		{
			k = pList[p.v][i];
			if (!visit[k] && dist[k] > p.dis + 1)
			{
				dist[k] = p.dis + 1;
				q.dis = dist[k];
				path[k] = p.v;
				q.v = k;
				que.push(q);
			}
		}
	}
	k = INF;
	j = -1;
	for (i = 0; i < n; i++)
	{
		if (t[i].x <= m && m <= t[i].y)
		{
			if (dist[i] < k)
			{
				j = i;
				k = dist[i];
			}
		}
	}
	return j;
}
void ShowPath(int j)
{
	if (j != -1)
	{
		ShowPath(path[j]);
		printf("%d %d\n", t[j].x, t[j].y);
	}
}
void Solve()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (t[i].y >= t[j].x)
			{
				pList[i].push_back(j);
			}
		}
	}
	j = dij();
	if (j == -1)
	{
		printf("No solution\n");
		return;
	}
	printf("%d\n", dist[j]);
	ShowPath(j);
}
int main()
{
	scanf("%d", &m);
	Input();
	Solve();
	return 0;
}