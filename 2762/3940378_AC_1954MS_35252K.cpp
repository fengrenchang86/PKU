
#include<iostream>
using namespace std;
#define N 1020
bool visit[N];
bool v[N];
int finish[N];
int rank[N];
int block[N];
bool c[N][N];
int n, m, acmCount;
int HHtime;
struct ac
{
	int v;
	ac *next;
}*list[N], *flist[N];
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
void IniDfs(int node)
{
	visit[node] = true;
	ac *p = list[node];
	while(p != NULL)
	{
		if(!visit[p->v])
			IniDfs(p->v);
		p = p->next;
	}
	finish[node] = HHtime;
	rank[HHtime] = node;
	HHtime++;
}
void dfs(int node)
{
	visit[node] = true;
	block[node] = HHtime;
	ac *p = flist[node];
	while(p != NULL)
	{
		if(!visit[p->v])
			dfs(p->v);
		p = p->next;
	}
}
void LoveHH()
{
	memset(visit, false, sizeof(visit));
	HHtime = 1;
	int i, j, k, x, y;
	ac *p;
	for(i = 1; i <= n; i++)
	{
		if(!visit[i])
			IniDfs(i);
	}
	memset(visit, false, sizeof(visit));
	HHtime = 0;
	for(i = n; i >= 1; i--)
	{
		if(!visit[rank[i]])
		{
			HHtime++;
			dfs(rank[i]);
		}
	}
	for(i = 1; i <= HHtime; i++)
	{
		for(j = 1; j <= HHtime; j++)
			c[i][j] = false;
	}
	for(i = 1; i <= n; i++)
	{
		p = list[i];
		j = block[i];
		while(p != NULL)
		{
			c[j][block[p->v]] = true;
			p = p->next;
		}
	}
	x = y = 0;
	for(i = 1; i <= HHtime; i++)
	{
		k = 0;
		for(j = 1; j <= HHtime; j++)
		{
			if(i != j && c[i][j])
				k++;
		}
		if(k == 0)
			x++;
		else if(k > 1)
			break;
		k = 0;
		for(j = 1; j <= HHtime; j++)
		{
			if(i != j && c[j][i])
				k++;
		}
		if(k == 0)
			y++;
		else if(k > 1)
			break;
	}
	if(i <= HHtime || x > 1 || y > 1)
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