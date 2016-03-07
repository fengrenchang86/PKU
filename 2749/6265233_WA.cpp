#include <iostream>
using namespace std;
struct NODE
{
	int v;
	NODE *next;
}*pList[1100], *pReverseList[1100];
struct DATASTRUCT
{
	int s1, s2;
}a[520], arrGood[1100], arrBad[1100];
int t[1100];
int visit[1100];
int n, A, B, nCount, dis;
int sx1, sy1, sx2, sy2;
bool flag;
void Input()
{
	int i, x, y;
	scanf("%d %d %d %d", &sx1, &sy1, &sx2, &sy2);
	dis = abs(sx1 - sx2) + abs(sy1 - sy2);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		a[i].s1 = abs(x-sx1) + abs(y-sy1);
		a[i].s2 = abs(x-sx2) + abs(y-sy2);
	}
	for (i = 0; i < A; i++)
	{
		scanf("%d %d", &arrBad[i].s1, &arrBad[i].s2);
		arrBad[i].s1--;
		arrBad[i].s2--;
	}
	for (i = 0; i < B; i++)
	{
		scanf("%d %d", &arrGood[i].s1, &arrGood[i].s2);
		arrGood[i].s1--;
		arrGood[i].s2--;
	}
	
}
void ClearList()
{
	int i;
	NODE *p, *q;
	for (i = 0; i < 2 * n; i++)
	{
		if (pList[i] != NULL)
		{
			p = pList[i];
			q = p->next;
			while (q != NULL)
			{
				delete p;
				p = q;
				q = q->next;
			}
			delete p;
			pList[i] = NULL;
		}
		
		if (pReverseList[i] != NULL)
		{
			p = pReverseList[i];
			q = p->next;
			while (q != NULL)
			{
				delete p;
				p = q;
				q = q->next;
			}
			delete p;
			pReverseList[i] = NULL;
		}
		
	}
}
void Insert(int x, int y)
{
	NODE *p = new NODE;
	p->v = y;
	p->next = pList[x];
	pList[x] = p;

	p = new NODE;
	p->v = x;
	p->next = pReverseList[y];
	pReverseList[y] = p;
}
void dfs_Topo(int node)
{
	visit[node] = 1;
	NODE *p = pList[node];
	while (p != NULL)
	{
		if (!visit[p->v])
		{
			dfs_Topo(p->v);
		}
		p = p->next;
	}
	nCount++;
	t[nCount] = node;
}
void Topo()
{
	int i;
	memset(visit, 0, sizeof(visit));
	nCount = -1;
	for (i = 0; i < 2 * n; i++)
	{
		if (!visit[i])
		{
			dfs_Topo(i);
		}
	}
}
void dfs_Choose(int node)
{
	if (!flag)
	{
		return;
	}
	visit[node] = 1;
	NODE *p = pList[node];
	while (p != NULL)
	{
		if (visit[p->v] == 0)
		{
			dfs_Choose(p->v);
		}
		else if (visit[p->v] == -1)
		{
			flag = false;
			return;
		}
		p = p->next;
	}
}
void dfs_Delete(int node)
{
	if (!flag)
	{
		return;
	}
	else if (visit[node] == 1)
	{
		flag = false;
		return;
	}
	visit[node] = -1;
	NODE *p = pReverseList[node];
	while (p != NULL)
	{
		if (visit[p->v] == 0)
		{
			dfs_Delete(p->v);
		}
		else if (visit[p->v] == 1)
		{
			flag = false;
			return;
		}
		p = p->next;
	}
}
bool Solve(int s)
{
	flag = true;
	ClearList();
	int i, j, k;
	for (i = 0; i < B; i++)
	{
		j = arrGood[i].s1;
		k = arrGood[i].s2;
		Insert(2 * j, 2 * k);
		Insert(2 * j + 1, 2 * k + 1);
		Insert(2 * k, 2 * j);
		Insert(2 * k + 1, 2 * j + 1);
	}
	for (i = 0; i < A; i++)
	{
		j = arrBad[i].s1;
		k = arrBad[i].s2;
		Insert(2 * j, 2 * k + 1);
		Insert(2 * j + 1, 2 * k);
		Insert(2 * k + 1, 2 * j);
		Insert(2 * k, 2 * j + 1);
	}
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			k = 0;
			if (a[i].s1 + a[j].s1 > s)
			{
				k++;
				Insert(2 * i, 2 * j + 1);
				Insert(2 * j, 2 * i + 1);
			}
			if (a[i].s2 + a[j].s2 > s)
			{
				k++;
				Insert(2 * i + 1, 2 * j);
				Insert(2 * j + 1, 2 * i);
			}
			if (a[i].s1 + a[j].s2 + dis > s)
			{
				k++;
				Insert(2 * i, 2 * j);
				Insert(2 * j + 1, 2 * i + 1);
			}
			if (a[i].s2 + a[j].s1 + dis > s)
			{
				k++;
				Insert(2 * i + 1, 2 * j + 1);
				Insert(2 * j, 2 * i);
			}
			if (k == 4)
			{
				return false;
			}
		}
	}
	Topo();
	memset(visit, 0, sizeof(visit));
	for (i = 0; i < 2 * n; i++)
	{
		k = t[i];
		if (visit[k] == 0)
		{
			dfs_Choose(k);
			if (k % 2 == 1)
			{
				dfs_Delete(k - 1);
			}
			else
			{
				dfs_Delete(k + 1);
			}
		}
	}
	return flag;
}
void Solve()
{
	int nBegin, nEnd, nMid;
	nBegin = 0;
	nEnd = 15000000;
	int ans = -1;
	while (nBegin < nEnd)
	{
		nMid = (nBegin + nEnd) / 2;
		if (Solve(nMid) == false)
		{
			nBegin = nMid + 1;
		}
		else
		{
			ans = nMid;
			nEnd = nMid;
		}
	}
	if (Solve(nBegin))
	{
		ans = nBegin;
	}
	printf("%d\n", ans);
}
int main()
{
	int i;
	for (i = 0; i < 1100; i++)
	{
		pList[i] = pReverseList[i] = NULL;
	}
	while (scanf("%d %d %d", &n, &A, &B) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}