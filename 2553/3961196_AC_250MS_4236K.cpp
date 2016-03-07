#include<iostream>
using namespace std;
struct ac
{
	int v;
	ac *next;
}*list[5010], *flist[5010];
int rank[5010];
int finish[5010];
int area[5010];
bool visit[5010];
int n, m;
int acTime;
void init()
{
	int i;
	for(i = 0; i <= n; i++)
		list[i] = flist[i] = NULL;
	acTime = 0;
}
void insert(int x, int y)
{
	ac *p = new ac;
	p->v = y;
	p->next = list[x];
	list[x] = p;

	p = new ac;
	p->v = x;
	p->next = flist[y];
	flist[y] = p;
}
void dfs(int node)
{
	visit[node] = true;
	ac *p = list[node];
	while(p != NULL)
	{
		if(!visit[p->v])
			dfs(p->v);
		p = p->next;
	}
	acTime++;
	finish[node] = acTime;
	rank[acTime] = node;
}
void fdfs(int node)
{
	visit[node] = true;
	area[node] = acTime;
	ac *p = flist[node];
	while(p != NULL)
	{
		if(visit[p->v] == false)
			fdfs(p->v);
		p = p->next;
	}
}
void MissHH()
{
	int i,x,y;
	init();
	for(i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		insert(x, y);
	}
}
void LoveHH()
{
	int i;
	memset(visit, false, sizeof(visit));
	for(i = 1; i <= n; i++)
	{
		if(!visit[i])
			dfs(i);
	}
	memset(visit, false, sizeof(visit));
	acTime = 0;
	for(i = n; i >= 1; i--)
	{
		acTime++;
		if(!visit[rank[i]])
			fdfs(rank[i]);
	}
	memset(finish, 0, sizeof(finish));
	ac *p;
	for(i = 1; i <= n; i++)
	{
		p = list[i];
		while(p != NULL)
		{
			if(area[i] != area[p->v])
				finish[area[i]] = 1;
			p = p->next;
		}
	}
	for(i = 1; i <= n; i++)
	{
		if(finish[area[i]] == 0)
			printf("%d ", i);
	}
	printf("\n");
}
int main ()
{
	while(scanf("%d", &n)!=EOF)
	{
		if(n == 0)
			break;
		scanf("%d", &m);
		MissHH();
		LoveHH();
	}
	return 0;
}