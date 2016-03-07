#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 1000000000
struct ac
{
	int v, len;
};
struct wa
{
	int step;
	int v;
	bool operator()(wa &m1, wa &m2)
	{
		return m1.step > m2.step;
	}
};
priority_queue<wa ,vector<wa>, wa>que;
vector<ac>table[700];
int dist[700], cost[700];
int type[700];
int n;
void dij()
{
	int i, j, k;
	for (i = 0; i <= n; i++)
	{
		cost[i] = INF;
		dist[i] = INF;
	}
	wa p ,q;
	ac w;
	p.step = 0;
	p.v = 1;
	dist[1] = 0;
	que.push(p);
	while (!que.empty())
	{
		p = que.top();
		que.pop();
		if (p.step > dist[p.v])
		{
			continue;
		}
		for (i = 0; i < (int)table[p.v].size(); i++)
		{
			w = table[p.v][i];
			if (type[w.v] == 2)
			{
				continue;
			}
			if (dist[w.v] > p.step + w.len)
			{
				dist[w.v] = p.step + w.len;
				q.v = w.v;
				q.step = dist[w.v];
				que.push(q);
			}
		}
	}
	p.step = 0;
	p.v = 2;
	cost[2] = 0;
	que.push(p);
	while (!que.empty())
	{
		p = que.top();
		que.pop();
		if (p.step > cost[p.v])
		{
			continue;
		}
		for (i = 0; i < (int)table[p.v].size(); i++)
		{
			w = table[p.v][i];
			if (type[w.v] == 1)
			{
				continue;
			}
			if (cost[w.v] > p.step + w.len)
			{
				cost[w.v] = p.step + w.len;
				q.v = w.v;
				q.step = cost[w.v];
				que.push(q);
			}
		}
	}
	int ans = INF;
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < (int)table[i].size(); j++)
		{
			w = table[i][j];
			if (dist[i] != INF && cost[w.v] != INF && ans > dist[i] + cost[w.v] + w.len)
			{
				ans = dist[i] + cost[w.v] + w.len;
			}
		}
	}
	if (ans == INF)
	{
		ans = -1;
	}
	printf("%d\n", ans);
}
void Input()
{
	int i, m;
	scanf("%d", &m);
	int x, y, len;
	ac p;
	for (i = 0; i <= n; i++)
	{
		table[i].clear();
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &len);
		p.len = len;
		p.v = x;
		table[y].push_back(p);
		p.v = y;
		table[x].push_back(p);
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &type[i]);
	}
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			break;
		}
		Input();
		dij();
	}
	return 0;
}