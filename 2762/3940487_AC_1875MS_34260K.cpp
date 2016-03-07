
#include<iostream>
using namespace std;
#define N 1020
bool visit[N];
bool v[N];
int finish[N];
int rank[N];
int block[N];
int next[N];
int pre[N];
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
	int i, j, k;
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
	for(i = 1; i <= n; i++)
	{
		next[i] = pre[i] = -1;
	}
	for(i = 1; i <= n; i++)
	{
		p = list[i];
		j = block[i];
		while(p != NULL)
		{
			if(j != block[p->v])
			{
				next[j] = block[p->v];
				pre[block[p->v]] = j;
			}
			p = p->next;
		}
	}
	k = 1;
	i = 1;
	while(k != -1)
	{
		i++;
		k = next[k];
	}
	i--;
	k = 1;
	while(k != -1)
	{
		i++;
		k = pre[k];
	}
	i--;
	if(i < HHtime)
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