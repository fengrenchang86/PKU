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
int nCount, n, m;
void Init()
{
	int i;
	for(i = 0; i < N; i++)
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
		else if(visit[p->v] < visit[node])
		{
			if(lay > 1 && Record[lay-2] == p->v && flag == false)
			{
				flag = true;
			}
			else
			{
				k = GetFather(p->v);
				for(i = lay - 1; i >= 0; i--)
				{
					if(Record[i] == p->v)
						break;
					father[GetFather(Record[i])] = k;
				}
			}
		}
		p = p->next;
	}
}
void Input()
{
	scanf("%d %d", &n, &m);
	Init();
	int i;
	acm cc;
	for(i = 0; i < m; i++)
	{
		scanf("%d %d", &cc.x, &cc.y);
		Insert(cc.x, cc.y);
		Insert(cc.y, cc.x);
		vec.push_back(cc);
	}
}
void Solve()
{
	Record[0] = 1;
	dfs(1, 1);
	acm cc;
	int i, x, y;
	for(i = 0; i <= n; i++)
		visit[i] = 0;
	for(i = 0; i < vec.size(); i++)
	{
		cc = vec[i];
		x = GetFather(cc.x);
		y = GetFather(cc.y);
		if(x != y)
		{
			visit[x]++;
			visit[y]++;
		}
	}
	x = 0;
	for(i = 1; i <= n; i++)
	{
		if(visit[i] == 1)
			x++;
	}
	printf("%d\n", (x+1) / 2);
}
int main()
{
	Input();
	Solve();
	return 0;
}