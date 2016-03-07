#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1000000000
struct ac
{
	int dis;
	int v;
	bool operator()(ac &m1, ac &m2)
	{
		return m1.dis > m2.dis;
	}
};
int w[110000];
bool visit[110000];
vector<int>vec[110000];
priority_queue<ac, vector<ac>, ac>que;
int n;
int Dij(int x, int y)
{
	ac p, q;
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		w[i] = INF;
	}
	p.dis = 0;
	p.v = x;
	w[x] = 0;
	que.push(p);
	while (!que.empty())
	{
		p = que.top();
		que.pop();
		if (p.dis > w[p.v])
		{
			continue;
		}
		for (i = 0; i < vec[p.v].size(); i++)
		{
			k = vec[p.v][i];
			if (w[k] > w[p.v] + 1)
			{
				w[k] = w[p.v] + 1;
				q.dis = w[k];
				q.v = k;
				que.push(q);
			}
		}
	}
	return w[y] - 1;
}
void Input()
{
	int i, k, j, nId, l;
	ac p;
	for (i = 0; i < n; i++)
	{
		vec[i].clear();
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &nId, &k);
		for (j = 0; j < k; j++)
		{
			scanf("%d", &l);
			vec[nId].push_back(l);
		}
	}
	scanf("%d %d", &j, &k);
	printf("%d %d ", j, k);
	k = Dij(j, k);
	printf("%d\n", k);
}
int main()
{
	scanf("%d", &n);
	Input();
	return 0;
}