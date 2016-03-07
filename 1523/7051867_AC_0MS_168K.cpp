#include <iostream>
using namespace std;
#define N 1020
struct ac
{
	int v;
	ac *next;
}*pList[N];
bool visit[N];
bool use[N];
int n, m, nCount, root;
void Insert(int x, int y)
{
	ac *p = new ac;
	p->v = y;
	p->next = pList[x];
	pList[x] = p;
}
void Init()
{
	int i, j;
	memset(visit, false, sizeof(visit));
	memset(use, false, sizeof(use));
	for(i = 0; i < N; i++)
	{
		pList[i] = NULL;
	}
	n = -1;
	nCount = 1;
}
bool Input()
{
	int x, y;
	Init();
	while(scanf("%d", &x) != EOF)
	{
		if(x == 0)
			break;
		scanf("%d", &y);
		if(x > n)
			n = x;
		if(y > n)
			n = y;
		Insert(x, y);
		Insert(y, x);
		use[x] = use[y] = true;
	}
	if(n == -1)
		return false;
	return true;
}
void DFS(int node)
{
	visit[node] = true;
	ac *p = pList[node];
	while(p != NULL)
	{
		if(!visit[p->v])
			DFS(p->v);
		p = p->next;
	}
}
int GetCut(int node)
{
	memset(visit, false, sizeof(visit));
	visit[node] = true;
	int k = 0;
	ac *p = pList[node];
	while(p != NULL)
	{
		if(!visit[p->v])
		{
			k++;
			DFS(p->v);
		}
		p = p->next;
	}
	return k;
}
void Solve(int tc)
{
	printf("Network #%d\n", tc);
	int i, j, k = 0;
	for(i = 1; i <= n; i++)
	{
		if(!use[i])
			continue;
		j = GetCut(i);
		if(j > 1)
		{
			printf("  SPF node %d leaves %d subnets\n", i, j);
			k = 1;
		}
	}
	if(k == 0)
		printf("  No SPF nodes\n");
	printf("\n");
}
int main()
{
	int tc = 1;
	while(Input())
	{
		Solve(tc);
		tc++;
	}
	return 0;
}