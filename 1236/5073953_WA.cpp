#include <iostream>
#include <vector>
using namespace std;
#define N 5020
struct ac
{
	int v;
	ac *next;
}*pList[N];
struct acm
{
	int x, y;
};
vector<acm>vec;
int father[N];
int Record[N];
int visit[N];
int a[N], b[N];
bool c[N][N];
int nCount, n, m;
void Init()
{
	int i, j;
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= n; j++)
			c[i][j] = false;
	}
	for(i = 0; i <= n; i++)
	{
		visit[i] = -1;
		father[i] = i;
		pList[i] = NULL;
	}
	nCount = 1;
	vec.clear();
}
void Insert(int x, int y)
{
	ac *p = new ac;
	p->v = y;
	p->next = pList[x];
	pList[x] = p;
}
int GetFather(int k)
{
	if(father[k] == k)
		return k;
	father[k] = GetFather(father[k]);
	return father[k];
}
void dfs(int lay, int node)
{
	visit[node] = nCount++;
	ac *p = pList[node];
	bool flag = false;
	int i, k;
	while(p != NULL)
	{
		if(visit[p->v] == -1)
		{
			Record[lay] = p->v;
			dfs(lay+1, p->v);
		}
		else if(visit[p->v] < visit[node] && c[p->v][node])
		{
			k = GetFather(p->v);
			for(i = lay - 1; i >= 0; i--)
			{
				if(Record[i] == p->v)
					break;
				father[GetFather(Record[i])] = k;
			}
		}
		p = p->next;
	}
}
void Input()
{
	scanf("%d", &n);
	Init();
	int i, j, k;
	acm cc;
	for(i = 1; i <= n; i++)
	{
		a[i] = 0;
		b[i] = 0;
	}
	for(i = 1; i <= n; i++)
	{
		cc.x = i;
		while(scanf("%d", &cc.y))
		{
			if(cc.y == 0)
				break;
			a[cc.y]++;
			Insert(cc.x, cc.y);
			c[cc.x][cc.y] = true;
			vec.push_back(cc);
		}
	}
	for(k = 1; k <= n; k++)
	{
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				if(c[i][k] && c[k][j])
					c[i][j] = true;
			}
		}
	}
}
void DFS(int node)
{
	visit[node] = true;
	int i;
	for(i = 1; i <= n; i++)
	{
		if(visit[i])
			continue;
		if(c[node][i] || c[i][node])
		{
			DFS(i);
		}
	}
}
void Solve()
{
	Record[0] = 1;
	dfs(1, 1);
	acm cc;
	int i, j = 0, k = 0, x, y;
	for(i = 1; i <= n; i++)
	{
		a[i] = b[i] = 0;
		father[i] = GetFather(i);
	}
	for(i = 0; i < vec.size(); i++)
	{
		cc = vec[i];
		x = father[cc.x];
		y = father[cc.y];
		if(x != y)
		{
			a[x]++;
			b[y]++;
			j = 1;
		}
	}
	x = y = 0;
	for(i = 1; i <= n; i++)
	{
		if(i == father[i])
		{
			if(a[i] == 0)
				x++;
			if(b[i] == 0)
				y++;
		}
	}
	
	memset(visit, false, sizeof(visit));
	k = 0;
	for(i = 1; i <= n; i++)
	{
		if(!visit[i])
		{
			k++;
			DFS(i);
		}
	}
	
	if(j == 0 && k == 1)
	{
		printf("1\n0\n");
		return;
	}
	else if(j == 0)
	{
		printf("%d\n%d\n", y, k);
		return;
	}
	if(k == 1)
		k = 0;
	printf("%d\n%d\n", y, (x > y ? x : y) + k);
}
int main()
{
	Input();
	Solve();
	return 0;
}