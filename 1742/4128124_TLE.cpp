#include <iostream>
#include <queue>
using namespace std;
#define inf 2000000000
struct ac
{
	int val, num;
};
int a[110];
int c[110];
queue<ac>que;
int n, m;
int use[110000];

void Input()
{
	int i;
	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);
//		a[i] = (rand()*rand()) % 100000 + 1;
	for(i = 1; i <= n; i++)
//		c[i] = (rand()) % 1000 + 1;
		scanf("%d", &c[i]);
}
bool visit[110000];
void dfs(int lay, int data)
{
	visit[data] = true;
	if(lay == n + 1)
		return;
	int i, j;
	for(i = 1; i <= c[lay]; i++)
	{
		j = data + i * a[lay];
		if(j <= m && !visit[j])
			dfs(lay+1, j);
	}
	dfs(lay+1, data);
}
void Solve()
{
	memset(visit, false, sizeof(visit));
	dfs(1, 0);
	ac p, q;
	int i, k = 0;
	for(i = 1; i <= m; i++)
	{
		if(visit[i])
			k++;
	}
	printf("%d\n", k);
	return;
	for(i = 0; i <= m; i++)
		use[i] = inf;
	p.num = 0;
	p.val = 0;
	que.push(p);
	while(!que.empty())
	{
		p = que.front();
		que.pop();
		k = c[p.num+1];
		if(p.num >= n)
			continue;
		q.num = p.num + 1;
		for(i = 0; i <= k; i++)
		{
			q.val = p.val + i*a[q.num];
			if(use[q.val] > q.num && q.val <= m)
			{
				use[q.val] = q.num;
				use[q.val] = true;
				que.push(q);
			}
		}
	}
	k = 0;
	for(i = 1; i <= m; i++)
	{
		if(use[i] != inf)
			k++;
	}
	printf("%d\n", k);
}
int main()
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