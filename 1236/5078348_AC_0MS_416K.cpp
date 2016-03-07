#include <iostream>
#include <vector>
using namespace std;
struct ac
{

	int v;
	ac *next;
}*pList[102], *vList[102];
struct acm
{
	int x, y;
};
vector<acm>vec;
int f[120];
int block[120];
bool visit[120];
int a[120], b[120];
int n, m, nCount;
void Insert(int x, int y)
{
	ac *p = new ac;
	p->v = y;
	p->next = pList[x];
	pList[x] = p;

	p = new ac;
	p->v = x;
	p->next = vList[y];
	vList[y] = p;
}
void Init()
{
	int i;
	for(i = 0; i <= n; i++)
	{
		pList[i] = NULL;
		vList[i] = NULL;
	}
}
void Input()
{
	int i, x, y;
	acm kac;
	for(i = 1; i <= n; i++)
	{
		x = i;
		while(scanf("%d", &y) != EOF)
		{
			if(y == 0)
				break;
			kac.x = x;
			kac.y = y;
			vec.push_back(kac);
			Insert(x, y);
		}
	}
}
void Dfs1(int node)
{
	visit[node] = true;
	ac *p = pList[node];
	while(p != NULL)
	{
		if(!visit[p->v])
		{
			Dfs1(p->v);
		}
		p = p->next;
	}
	f[node] = nCount++;
}
void DFS(int node, int nBlock)
{
	block[node] = nBlock;
	visit[node] = true;
	ac *p = vList[node];
	while(p != NULL)
	{
		if(!visit[p->v])
		{
			DFS(p->v, nBlock);
		}
		p = p->next;
	}
}
void Solve()
{
	int i, j, k;
	int x, y;
	acm kac;
	memset(visit, false, sizeof(visit));
	nCount = 1;
	for(i = 1; i <= n; i++)
	{
		if(!visit[i])
			Dfs1(i);
	}
	memset(visit, false, sizeof(visit));
	j = 0;
	for(i = 1; i <= n; i++)
	{
		x = 0;
		for(k = 1; k <= n; k++)
		{
			if(!visit[k])
			{
				if(x == 0 || f[k] > f[x])
					x = k;
			}
		}
		if(x >= 1)
		{
			j++;
			DFS(x, j);
		}
	}
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	if(j == 1)
	{
		printf("1\n0\n");
		return;
	}
	for(i = 0; i < vec.size(); i++)
	{
		kac = vec[i];
		if(block[kac.x] != block[kac.y])
		{
			a[block[kac.x]]++;
			b[block[kac.y]]++;
		}
	}
	x = y = 0;
	for(i = 1; i <= j; i++)
	{
		if(a[i] == 0)
			x++;
		if(b[i] == 0)
			y++;
	}
	printf("%d\n%d\n", y, x > y ? x : y);
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
			break;
		Input();
		Solve();
	}
	return 0;
}