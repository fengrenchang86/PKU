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
	int i, acCount = 0;
	bool tag = true;
	for(i = 0; i < n; i++)
		dist[i] = inf;
	dist[0] = 0;
	while(tag)
	{
		tag = false;
		for(i = 0; i < n; i++)
		{
			p = list[i];
			while(p != NULL)
			{
				if(dist[p->v] > dist[i] + p->len)
				{
					dist[p->v] = dist[i] + p->len;
					if(dist[p->v] < 0 && !visit[p->v])
					{
						acCount++;
						visit[p->v] = true;
					}
					tag = true;
				}
				p = p->next;
			}
		}
		if(acCount == n)
			break;
	}
	if(acCount == n)
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