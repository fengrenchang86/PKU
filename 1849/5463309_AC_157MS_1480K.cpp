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
	visit[node] = nCount++;
	ac *p = tree[node];
	int i, m = 0;
	int j, j1 = 2000000000, j2 = 2000000000;
	int k;
	while(p != NULL)
	{
		if (!visit[p->v])
		{
			m++;
		}
		p = p->next;
	}
	dp[node][0] = 0;
	if (m == 0)
	{
		dp[node][0] = dp[node][1] = dp[node][2] = 0;
		return;
	}
	p = tree[node];
	k = 2000000000;
	while (p != NULL)
	{
		if (!visit[p->v])
		{
			dfs(p->v);
			dp[node][0] += (dp[p->v][0] + p->len * 2);
			j = dp[p->v][1] - dp[p->v][0] - p->len;
			if (j < j1 && j < j2)
			{
				if (j1 < j2)
				{
					j2 = j;
				}
				else
					j1 = j;
			}
			else if(j < j1)
				j1 = j;
			else if(j < j2)
				j2 = j;
			if (dp[p->v][2] - dp[p->v][0] < k)
			{
				k = dp[p->v][2] - dp[p->v][0];
			}
		}
		p = p->next;
	}
	if (j1 > j2)
	{
		j = j1;
		j1 = j2;
		j2 = j;
	}
	dp[node][1] = dp[node][0] + j1;
	if (m >= 2)
	{
		dp[node][2] = GetMin(dp[node][0] + j1 + j2, dp[node][0] + k);
	}
	else
	{
		dp[node][2] = GetMin(dp[node][1], dp[node][0] + k);
	}
}
void Input()
{
	int i,x,y,z;
	for (i = 1; i <= n; i++)
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