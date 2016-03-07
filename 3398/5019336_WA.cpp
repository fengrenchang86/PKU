#include <iostream>
using namespace std;
#define INF 20000
struct ac
{
	ac *next;
	int v;
}*pList[10101];
int dp[10101][3];
int visit[10101];
int n, nCount;
int GetMin(int x, int y)
{
	return x < y ? x : y;
}
void Insert(int x, int y)
{
	ac *p = new ac;
	p->next = pList[x];
	p->v = y;
	pList[x] = p;
}
void Init()
{
	int i;
	for(i = 0; i < n; i++)
		pList[i] = NULL;
	memset(visit, 0, sizeof(visit));
	nCount = 1;
}
void Input()
{
	int i, x, y;
	Init();
	for(i = 0; i < n-1; i++)
	{
		scanf("%d %d", &x, &y);
		x--;
		y--;
		Insert(x, y);
		Insert(y, x);
	}
}
void Dfs(int node)
{
	ac *p = pList[node];
	visit[node] = nCount++;
	while(p != NULL)
	{
		if(!visit[p->v])
			break;
		p = p->next;
	}
	if(p == NULL)
	{
		dp[node][0] = 1;
		dp[node][1] = INF;
		dp[node][2] = 0;
		return;
	}
	p = pList[node];
	dp[node][0] = dp[node][2] = 0;
	dp[node][1] = INF;
	int k = 0;
	while(p != NULL)
	{
		if(visit[p->v] == 0)
		{
			Dfs(p->v);
			dp[node][0] += GetMin(dp[p->v][0], dp[p->v][2]);
			dp[node][2] += dp[p->v][1];
			k += dp[p->v][2];
		}
		p = p->next;
	}
	p = pList[node];
	while(p != NULL)
	{
		if(visit[p->v] > visit[node])
		{
			dp[node][1] = GetMin(dp[node][1], k - dp[p->v][2] + dp[p->v][0]);
		}
		p = p->next;
	}
	dp[node][0] ++;
}
void Solve()
{
	Dfs(0);
	printf("%d\n", GetMin(dp[0][0], dp[0][1]));
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		if(-1 == n)
			break;
		Input();
		Solve();
	}
	return 0;
}