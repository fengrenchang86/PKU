#include <iostream>
#include <queue>
using namespace std;
#define N 10100
#define INF 2000000000
struct ac
{
	int v;
	ac *next;
}*plist[N];
int usetime[N];
int degree[N];
int dis[N];
bool visit[N];
int n;
void insert(int x, int y)
{
	ac *p = new ac;
	p->v = y;
	p->next = plist[x];
	plist[x] = p;
}
void Init()
{
	int i;
	for(i = 1; i <= n; i++)
	{
		dis[i] = 0;
		visit[i] = false;
	}
	
}
void Input()
{
	int i, j, k, x;
	for(i = 1; i <= n; i++)
	{
		scanf(" %d", &usetime[i]);
		scanf("%d", &k);
		degree[i] = k;
		for(j = 0; j < k; j++)
		{
			scanf("%d", &x);
			insert(x, i);
		}
	}
}
void dfs(int node)
{
	visit[node] = true;
	ac *p = plist[node];
	while(p != NULL)
	{
		degree[p->v]--;
		if(dis[p->v] < dis[node] + usetime[p->v])
				dis[p->v] = dis[node] + usetime[p->v];
		if(!visit[p->v] && degree[p->v] == 0)
		{
			dfs(p->v);
		}
		p = p->next;
	}
}
int main()
{
	int i, j = 1;
	scanf("%d", &n);
	Init();
	Input();
	for(i = 1; i <= n; i++)
	{
		if(!visit[i] && degree[i] == 0)
		{
			dis[i] = usetime[i];
			dfs(i);
		}
	}
	j = 1;
	for(i = 1; i <= n; i++)
	{
		if(dis[i] > dis[j])
			j = i;
	}
	printf("%d\n", dis[j]);
	return 0;
}