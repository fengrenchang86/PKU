#include <iostream>
using namespace std;
#define N 1020
struct ac
{
	int v;
	ac *next;
}*pList[N];
int Low[N];
int num[N];
int father[N];
bool visit[N];
bool link[N][N];
bool use[N];
int CutPoint[N];
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
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
			link[i][j] = false;
	}
	memset(visit, false, sizeof(visit));
	memset(use, false, sizeof(use));
	for(i = 0; i < N; i++)
	{
		Low[i] = -1;
		num[i] = -1;
		father[i] = -1;
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
		if(link[x][y] == false)
		{
			Insert(x, y);
			Insert(y, x);
			use[x] = use[y] = true;
			link[x][y] = link[y][x] = true;
		}
	}
	if(n == -1)
		return false;
	return true;
}
void dfs(int node)
{
	num[node] = nCount++;
	ac *p = pList[node];
	while(p != NULL)
	{
		if(num[p->v] == -1)
		{
			father[p->v] = node;
			dfs(p->v);
		}
		p = p->next;
	}
}
void FindLow(int node)
{
	Low[node] = num[node];
	ac *p = pList[node];
	while(p != NULL)
	{
		if(father[node] != p->v && num[p->v] < num[node] && num[p->v] < Low[node])
			Low[node] = num[p->v];
		if(num[p->v] > num[node])
		{
			if(Low[p->v] == -1)
				FindLow(p->v);
			if(Low[p->v] < Low[node])
				Low[node] = Low[p->v];
		}
		p = p->next;
	}
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
void GetNode()
{
	int i;
	m = 0;
	if(GetCut(root) > 1)
	{
		CutPoint[m++] = 1;
	}
	
	ac *p;
	for(i = root+1; i <= n; i++)
	{
		if(!use[i])
			continue;
		p = pList[i];
		while(p != NULL)
		{
			if(num[i] <= Low[p->v])
				break;
			p = p->next;
		}
		if(p != NULL)
			CutPoint[m++] = i;
	}
}
void Solve(int tc)
{
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
	return;
	for(i = 1; i <= n; i++)
	{
		if(use[i])
			break;
	}
	root = i;
	for(i = 1; i <= n; i++)
	{
		if(!use[i])
			continue;
		if(num[i] == -1)
			dfs(i);
	}
	for(i = 1; i <= n; i++)
	{
		if(!use[i])
			continue;
		if(Low[i] == -1)
			FindLow(i);
	}
	GetNode();
	printf("Network #%d\n", tc);
	if(m == 0)
	{
		printf("  No SPF nodes\n");
	}
	for(i = 0; i < m; i++)
	{
		j = GetCut(CutPoint[i]);
		printf("  SPF node %d leaves %d subnets\n", CutPoint[i], j);
	}
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