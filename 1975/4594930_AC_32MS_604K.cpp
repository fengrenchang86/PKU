#include <iostream>
using namespace std;

struct NODE
{
	int v;
	NODE *next;
}*List[110], *vList[110];
int n, m;
int nLess[110], nMore[110];
bool visit[110];
int nCount;
void insert(int x, int y)
{
	NODE *p = new NODE;
	p->v = y;
	p->next = List[x];
	List[x] = p;

	p = new NODE;
	p->v = x;
	p->next = vList[y];
	vList[y] = p;
}
void Init()
{
	int i;
	for(i = 1; i <= n; i++)
		List[i] = vList[i] = NULL;
}
void Del(NODE *p)
{
	if(p->next != NULL)
		Del(p->next);
	delete p;
}
void Delete()
{
	int i;
	for(i = 1; i <= n; i++)
	{
		if(List[i] != NULL)
		{
			Del(List[i]);
			List[i] = NULL;
		}
		if(vList[i] != NULL)
		{
			Del(vList[i]);
			vList[i] = NULL;
		}
	}
}
void Input()
{
	int i, x, y;
	scanf("%d %d", &n, &m);	
	Init();
	for(i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		insert(x, y);
	}
}
void dfs(int node)
{
	visit[node] = true;
	NODE *p = List[node];
	while(p != NULL)
	{
		if(!visit[p->v])
			dfs(p->v);
		p = p->next;
	}
}
void vDfs(int node)
{
	visit[node] = true;
	NODE *p = vList[node];
	while(p != NULL)
	{
		if(!visit[p->v])
			vDfs(p->v);
		p = p->next;
	}
}
void Solve()
{
	int i, j, k = 0;
	memset(visit, false, sizeof(visit));
	for(i = 1; i <= n; i++)
	{
		dfs(i);
		nLess[i] = -1;
		for(j = 1; j <= n; j++)
		{
			if(visit[j])
			{
				visit[j] = 0;
				nLess[i]++;
			}
		}
		if(nLess[i] > n/2)
		{
			k++;
			continue;
		}
		vDfs(i);
		nMore[i] = -1;
		for(j = 1; j <= n; j++)
		{
			if(visit[j])
			{
				visit[j] = 0;
				nMore[i] ++;
			}
		}
		if(nMore[i] > n/2)
			k++;
	}
	printf("%d\n", k);
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		Input();
		Solve();
	}
	return 0;
}