
#include<iostream>
using namespace std;
bool visit[1020];
bool v[1020];
int n, m, acmCount;
struct ac
{
	int v;
	ac *next;
}*list[1020], *flist[1020];
void init()
{
	int i;
	for(i = 0; i <= n; i++)
		list[i] = flist[i] = NULL;
}
void insert(int x, int y)
{
	ac *p = new ac;
	p -> v = y;
	p ->next = list[x];
	list[x] = p;
	p = new ac;
	p->v = x;
	p->next = flist[y];
	flist[y] = p;
}
void MissHH()
{
	scanf("%d %d", &n, &m);
	init();
	int i, x, y;
	for(i = 0; i < m; i++)
	{
		scanf("%d%d",&x, &y);
		insert(x,y);
	}
}
void dfs(int node)
{
	visit[node] = true;
	if(!v[node])
	{
		acmCount++;
		v[node] = true;
	}
	ac *p = list[node];
	while( p != NULL)
	{
		if(!visit[p->v] )
			dfs(p->v);
		p = p->next;
	}
}
void fdfs(int node)
{
	visit[node] = true;
	if(!v[node])
	{
		acmCount++;
		v[node] = true;
	}
	ac *p = flist[node];
	while( p != NULL)
	{
		if(!visit[p->v] )
			fdfs(p->v);
		p = p->next;
	}
}
void LoveHH()
{
	int i;
	for(i = 1; i <= n; i++)
	{
		memset(visit, false, sizeof(visit));
		memset(v, false, sizeof(v));
		acmCount = 0;
		dfs(i);
		memset(visit, false, sizeof(visit));
		fdfs(i);		
		if(acmCount < n)
			break;
	}
	if(i <= n)
		printf("No\n");
	else
		printf("Yes\n");
}
int main ()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		MissHH();
		LoveHH();
	}
	return 0;
}