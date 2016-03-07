#include <iostream>
using namespace std;
#define N 520
#define inf 2000000000
struct ac
{
	int v;
	int len;
	ac *next;
}*list[N];
int dist[N];
bool visit[N];
int n;
void insert(int x, int y, int len)
{
	ac *p = new ac;
	p->len = len;
	p->v = y;
	p->next = list[x];
	list[x] = p;
}
void init()
{
	int i;
	for(i = 0; i < n; i++)
	{
		list[i] = NULL;
		visit[i] = false;
	}
}
void input()
{
	int m, w, i, x, y, z;
	scanf("%d %d %d", &n, &m, &w);
	init();
	for(i = 0; i < m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		x--;
		y--;
		insert(x, y, z);
		insert(y, x, z);
	}
	for(i = 0; i < w; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		x--;
		y--;
		insert(x, y, -z);
	}
}
void solve()
{
	ac *p = NULL;
	int i, j, k, acCount = 0;
	bool tag = true;
	for(i = 0; i < n; i++)
	{
		dist[i] = inf;
		visit[i] = false;
	}
	dist[0] = 0;
	for(j = 0; j < n; j++)
	{
		k = -1;
		for(i = 0; i < n; i++)
		{
			if(!visit[i] && (k == -1 || dist[i] < dist[k]))
				k = i;
		}
		visit[k] = true;
		p = list[k];
		while(p != NULL)
		{
			if(dist[k] + p->len < dist[p->v])
			{
				dist[p->v] = dist[k] + p->len;
			}
			p = p->next;
		}
	}
	tag = 1;
	for(j = 0; tag && j <= n; j++)
	{
		tag = 0;
		for(i = 0; i < n; i++)
		{
			p = list[i];
			while(p != NULL)
			{
				if(dist[i] + p->len < dist[p->v])
				{
					dist[p->v] = dist[i] + p->len;
					tag = 1;
				}
				p = p->next;
			}
		}
	}
	if(j > n)
		printf("YES\n");
	else
		printf("NO\n");
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		input();
		solve();
	}
	return 0;
}