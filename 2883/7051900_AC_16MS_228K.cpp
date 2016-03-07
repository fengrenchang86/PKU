#include <iostream>
using namespace std;
struct ac
{
	int v;
	ac *next;
}*list1[520], *list2[520];
bool visit[520];
bool cur[520];
short father1[520];
short father2[520];
int n, m;
int flag;
void Init()
{
	int i;
	for (i = 0; i <= n; i++)
	{
		list1[i] = list2[i] = NULL;
		father1[i] = father2[i] = i;
	}
	memset(visit, false, sizeof(visit));
	memset(cur, false, sizeof(cur));
	flag = 1;
}
void Insert1(int x, int y)
{
	ac *p = new ac;
	p->v = y;
	p->next = list1[x];
	list1[x] = p;
}
void Insert2(int x, int y)
{
	ac *p = new ac;
	p->v = y;
	p->next = list2[x];
	list2[x] = p;
}
int GetFather1(int k)
{
	if (father1[k] != k)
	{
		int fk = GetFather1(father1[k]);
		father1[k] = fk;
		return fk;
	}
	else
		return k;
}
int GetFather2(int k)
{
	if (father2[k] != k)
	{
		int fk = GetFather2(father2[k]);
		father2[k] = fk;
		return fk;
	}
	else
		return k;
}
void Input()
{
	int i, x, y;
	int fx1, fy1, fx2, fy2;
	char ch[10];
	scanf("%d %d", &n, &m);
	Init();
	for (i = 0; i < m; i++)
	{
		scanf("%d %s %d", &x, &ch, &y);
		fx1 = GetFather1(x);
		fy1 = GetFather1(y);
		fx2 = GetFather2(x);
		fy2 = GetFather2(y);
		if (ch[0] == 'N')
		{
			Insert1(fx1, fy1);
			if (ch[1] == NULL)
				father2[fx2] = fy2;
			else if (ch[1] == 'W')
				Insert2(fx2, fy2);
			else
				Insert2(fy2, fx2);
		}
		else if (ch[0] == 'S')
		{
			Insert1(fy1, fx1);
			if (ch[1] == NULL)
				father2[fx2] = fy2;
			else if (ch[1] == 'W')
				Insert2(fx2, fy2);
			else
				Insert2(fy2, fx2);
		}
		else if (ch[0] == 'W')
		{
			father1[fx1] = fy1;
			Insert2(fx2, fy2);
		}
		else
		{
			father1[fx1] = fy1;
			Insert2(fy2, fx2);
		}
	}
}
void InitList1()
{
	int i, fi;
	ac *p;
	for (i = 1; i <= n; i++)
	{
		fi = GetFather1(i);
		if (fi == i)
			continue;
		p = list1[fi];
		if (p == NULL)
		{
			list1[fi] = list1[i];
		}
		else
		{
			while(p->next != NULL)
				p = p->next;
			p->next = list1[i];
		}
	}
}
void InitList2()
{
	int i, fi;
	ac *p;
	for (i = 1; i <= n; i++)
	{
		fi = GetFather2(i);
		if (fi == i)
			continue;
		p = list2[fi];
		if (p == NULL)
		{
			list2[fi] = list2[i];
		}
		else
		{
			while(p->next != NULL)
				p = p->next;
			p->next = list2[i];
		}
	}
}
void dfs1(int node)
{
	if (!flag)
	{
		return;
	}
	visit[node] = true;
	cur[node] = true;
	ac *p = list1[node];
	int f;
	while(p != NULL)
	{
		f = GetFather1(p->v);
		if (cur[f] == true)
		{
			flag = 0;
			return;
		}
		else if (!visit[f])
			dfs1(f);
		p = p->next;
	}
	cur[node] = false;
}
void dfs2(int node)
{
	if (!flag)
	{
		return;
	}
	visit[node] = true;
	cur[node] = true;
	ac *p = list2[node];
	int f;
	while(p != NULL)
	{
		f = GetFather2(p->v);
		if (cur[f] == true)
		{
			flag = 0;
			return;
		}
		else if (!visit[f])
			dfs2(f);
		p = p->next;
	}
	cur[node] = false;
}
void Solve()
{
	int i, fi;
	for (i = 1; i <= n; i++)
	{
		fi = GetFather1(i);
		if (!visit[fi])
		{
			dfs1(fi);
		}
	}
	if (flag == 0)
	{
		printf("IMPOSSIBLE\n");
		return;
	}
	memset(visit, false, sizeof(visit));
	memset(cur, false, sizeof(cur));
	for (i = 1; i <= n; i++)
	{
		fi = GetFather2(i);
		if (!visit[fi])
		{
			dfs2(fi);
		}
	}
	if (flag == 0)
	{
		printf("IMPOSSIBLE\n");
	}
	else
	{
		printf("POSSIBLE\n");
	}
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