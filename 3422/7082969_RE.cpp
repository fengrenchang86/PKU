#include <iostream>
#include <queue>
using namespace std;
struct ac
{
	int v;
	ac *next;
}*pTable[120];;
int n, m;
int f[120][120];
int c[120][120];
int path[120];
int dist[120];
int inqueue[120];
queue<int>que;
void Init()
{
	int i, j;
	int k = 2 * n * n + 2;
	for (i = 0; i <= k; i++)
	{
		for (j = 0; j <= k; j++)
		{
			f[i][j] = 0;
			c[i][j] = 0;
		}
		pTable[i] = 0;
	}
}
void Insert(int x, int y)
{
	ac *p = new ac;
	p->v = y;
	p->next = pTable[x];
	pTable[x] = p;
}
void Input()
{
	int i, j, k;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d" ,&k);
			Insert(2*((i-1)*n+j)-1, 2*((i-1)*n+j));
			c[2*((i-1)*n+j)-1][2*((i-1)*n+j)] = -k;
			f[2*((i-1)*n+j)-1][2*((i-1)*n+j)] = 1;
			if (i + 1 <= n)
			{
				Insert(2*((i-1)*n+j), 2*(i*n+j)-1);
				f[2*((i-1)*n+j)][2*(i*n+j)-1] = 1000;
				Insert(2*((i-1)*n+j)-1, 2*(i*n+j)-1);
				f[2*((i-1)*n+j)-1][2*(i*n+j)-1] = 1000;
			}
			if (j + 1 <= n)
			{
				Insert(2*((i-1)*n+j), 2*((i-1)*n+j+1)-1);
				f[2*((i-1)*n+j)][2*((i-1)*n+j+1)-1] = 1000;
				Insert(2*((i-1)*n+j)-1, 2*((i-1)*n+j+1)-1);
				f[2*((i-1)*n+j)-1][2*((i-1)*n+j+1)-1] = 1000;
			}
//			Insert(0, 2*((i-1)*n+j)-1);
//			f[0][2*((i-1)*n+j)-1] = 1000;
		}
	}
	Insert(0, 1);
	Insert(2*n*n, 2*n*n+1);
	f[0][1] = m;
	f[2*n*n][2*n*n+1] = m;
	Insert(2*n*n-1, 2*n*n+1);
	f[2*n*n-1][2*n*n+1] = 1000;
}
bool SPFA()
{
	memset(inqueue, 0, sizeof(inqueue));
	int i, maxn = 2 * n * n + 1;
	for (i = 0; i <= maxn; i++)
	{
		path[i] = -1;
		dist[i] = 1000;
	}
	while (!que.empty())
	{
		que.pop();
	}
	dist[0] = 0;
	inqueue[0] = 1;
	que.push(0);
	int x, y;
	ac *p;
	while (!que.empty())
	{
		x = que.front();
		que.pop();
		inqueue[x] = 0;
		p = pTable[x];
		while (p)
		{
			if (f[x][p->v] && dist[p->v] > dist[x] + c[x][p->v])
			{
				dist[p->v] = dist[x] + c[x][p->v];
				if (!inqueue[p->v])
				{
					inqueue[p->v] = 1;
					que.push(p->v);
					path[p->v] = x;
				}
			}
			p = p->next;
		}
	}
	if (path[maxn] == -1)
	{
		return false;
	}
	return true;
}
void Solve()
{
	int ans = 0;
	int x, y;
	while (SPFA())
	{
		x = 2 * n * n + 1;
		while (x)
		{
			y = path[x];
			ans -= c[y][x];
			f[y][x]--;
			f[x][y]++;
			x = y;
		}
	}
	printf("%d\n", ans);
}
int main()
{
	scanf("%d %d", &n, &m);
	Input();
	Solve();
	return 0;
}