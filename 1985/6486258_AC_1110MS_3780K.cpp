#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define INF -1000000000
struct ac
{
	int v;
	int len;
}path[40100];
vector<ac>pList[40100];
stack<ac>g_stack;
int dist[40100][3];
int f[40100];
bool visit[40100];
int n, m;
void Input()
{
	int i, x, y, len;
	char ch;
	ac p;
	scanf("%d %d", &n, &m);
	for (i = 0; i <= n; i++)
	{
		pList[i].clear();
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d %c", &x, &y, &len, &ch);
		p.v = y;
		p.len = len;
		pList[x].push_back(p);
		p.v = x;
		p.len = len;
		pList[y].push_back(p);
	}
}
int dfs(int node, int len)
{
	visit[node] = true;
	dist[node][0] = len;
	int i, j, k = 0;
	ac p;
	for (i = 0; i < pList[node].size(); i++)
	{
		p = pList[node][i];
		if (!visit[p.v])
		{
			j = dfs(p.v, len + p.len) + p.len;
			if (dist[node][0] > dist[node][1])
			{
				if (j > dist[node][1])
				{
					dist[node][1] = j;
				}
			}
			else
			{
				if (j > dist[node][0])
				{
					dist[node][0] = j;
				}
			}
			if (j > k)
			{
				k = j;
			}
		}
	}
	return k;
}
void Solve()
{
	int i, j, k;
	ac p, q;
	for (i = 0; i <= n; i++)
	{
		dist[i][0] = dist[i][1] = 0;
		visit[i] = 0;
	}
	while (!g_stack.empty())
	{
		g_stack.pop();
	}
	p.len = 0;
	p.v = 1;
	visit[1] = 1;
	g_stack.push(p);
	j = 0;
	while (!g_stack.empty())
	{
		p = g_stack.top();
		g_stack.pop();
		dist[p.v][0] = p.len;
		f[j++] = p.v;
		k = p.v;
		for (i = 0; i < pList[k].size(); i++)
		{
			if (!visit[pList[k][i].v])
			{
				visit[pList[k][i].v] = 1;
				q.v = pList[k][i].v;
				q.len = pList[k][i].len + p.len;
				g_stack.push(q);
				path[q.v].v = p.v;
				path[q.v].len = pList[k][i].len;
			}
		}
	}
	int x1(0), x2(0);
	for (i = j - 1; i >= 0; i--)
	{
		p = path[f[i]];
		x1 = dist[f[i]][2] + p.len;
		if (dist[p.v][2] < x1)
		{
			dist[p.v][2] = x1;
		}
		if (dist[p.v][0] < dist[p.v][1])
		{
			if (dist[p.v][0] < x1)
			{
				dist[p.v][0] = x1;
			}
		}
		else
		{
			if (dist[p.v][1] < x1)
			{
				dist[p.v][1] = x1;
			}
		}
	}
}
int main()
{
//	freopen("f:\\udata\\marathon.10.in", "r", stdin);
	Input();
	Solve();
	int i, ans;
	ans = 0;
	for (i = 1; i <= n; i++)
	{
		if (ans < dist[i][0] + dist[i][1])
		{
			ans = dist[i][0] + dist[i][1];
		}
	}
	printf("%d\n", ans);
	return 0;
}