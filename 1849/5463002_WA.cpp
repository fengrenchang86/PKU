#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int v;
	int len;
	ac *next;
}*tree[100100];
int dp[100100][3];
int visit[100100];
int nCount;
int n, s;
int cmp(const void*a, const void*b)
{
	return *(int*)a - *(int*)b;
}
int GetMin(int x, int y)
{
	return x < y ? x : y;
}
int GetMin(int x, int y, int z)
{
	return GetMin(x, GetMin(y,z));
}
void Insert(int x, int y, int z)
{
	ac *p = new ac;
	p->v = y;
	p->len = z;
	p->next = tree[x];
	tree[x] = p;
}
void dfs(int node)
{
	visit[node] = nCount;
	ac *p = tree[node];
	dp[node][0] = 0;
	int i, m = 0;
	while(p != NULL)
	{
		if (!visit[p->v])
		{
			m++;
		}
		p = p->next;
	}
	if (m == 0)
	{
		dp[node][0] = dp[node][1] = dp[node][2] = 0;
		return;
	}
	int *v = new int[m];
	p = tree[node];
	i = 0;
	while (p != NULL)
	{
		if (!visit[p->v])
		{
			dfs(p->v);
			dp[node][0] += (dp[p->v][0] + p->len * 2);
			v[i++] = dp[p->v][1] - dp[p->v][0] - p->len;
		}
		p = p->next;
	}
	qsort(v, m, sizeof(v[0]), cmp);
	dp[node][1] = dp[node][0] + v[0];
	dp[node][2] = dp[node][0] + v[0] + v[1];
	p = tree[node];
	while(p != NULL)
	{
		if (visit[p->v] > visit[node])
		{
			if (dp[node][2] > dp[node][0] - dp[p->v][0] + dp[p->v][2])
			{
				dp[node][2] = dp[node][0] - dp[p->v][0] + dp[p->v][2];
			}
		}
		p = p->next;
	}
	delete []v;
}
void Input()
{
	int i,x,y,z;
	for (i = 0; i <= n; i++)
	{
		tree[i] = NULL;
	}
	nCount = 1;
	for (i = 0; i < n - 1; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		Insert(x, y, z);
		Insert(y, x, z);
	}
}
void Solve()
{
	memset(visit, 0, sizeof(visit));
	dfs(s);
	printf("%d\n", GetMin(dp[s][0], dp[s][1], dp[s][2]));
}

int main()
{
	while(scanf("%d %d", &n, &s) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}