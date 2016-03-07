#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 1000000000
struct ac
{
	int v;
	int len;
};
struct acm
{
	int dis;
	int v;
	bool operator()(acm &m1, acm &m2)
	{
		return m1.dis < m2.dis;
	}
};
vector<ac>vec[1002];
priority_queue<acm, vector<acm>, acm>que;
bool visit[1002];
int dis[1002];
int ArrayNum[1002];
int n, m;
void Input()
{
	scanf("%d", &m);
	int i, x, y, len;
	ac kac;
	for(i = 0; i < 1002; i++)
		vec[i].clear();
	for(i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &len);
		kac.v = x;
		kac.len = len;
		vec[y].push_back(kac);
		kac.v = y;
		vec[x].push_back(kac);
	}
}
void Dij()
{
	while(!que.empty())
		que.pop();
	memset(visit, false, sizeof(visit));
	int i, j;
	for(i = 1; i <= n; i++)
	{
		dis[i] = INF;
	}
	dis[2] = 0;
	visit[2] = true;
	acm p, t;
	ac q;
	p.dis = 0;
	p.v = 2;
	que.push(p);
	for(i = 0; i < n; i++)
	{
		p = que.top();
		que.pop();
		if(dis[p.v] < p.dis)
			continue;
		visit[p.v] = true;
		for(j = 0; j < vec[p.v].size(); j++)
		{
			q = vec[p.v][j];
			if(visit[q.v])
				continue;
			if(dis[q.v] > dis[p.v] + q.len)
			{
				dis[q.v] = dis[p.v] + q.len;
				t.dis = dis[q.v];
				t.v = q.v;
				que.push(t);
			}
		}
	}
}
void dfs(int node)
{
	int i;
	ac p;
	ArrayNum[node] = 0;
	for(i = 0; i < vec[node].size(); i++)
	{
		p = vec[node][i];
		if(dis[p.v] < dis[node])
			continue;
		if(ArrayNum[p.v] == -1)
			dfs(p.v);
		ArrayNum[node] += ArrayNum[p.v];
	}
}
void Solve()
{
	memset(ArrayNum, -1, sizeof(ArrayNum));
	ArrayNum[1] = 1;
	dfs(2);
	printf("%d\n", ArrayNum[2]);
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
			break;
		Input();
		Dij();
		Solve();
	}
	return 0;
}