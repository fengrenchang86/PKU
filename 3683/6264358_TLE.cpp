#include <iostream>
using namespace std;
struct DATA
{
	int x, y;
}a[1100][2];
struct NODE
{
	int v;
	NODE *next;
}*pList[2100], *pReverseList[2100];
int n, nCount;
int t[2100], vt[2100];
int visit[2100];
bool flag;
void Input()
{
	int i;
	int h1, h2, m1, m2, d;
	int x1, x2;
	for (i = 0; i < n; i++)
	{
		scanf("%02d:%02d %02d:%02d %d", &h1, &m1, &h2, &m2, &d);
		x1 = h1 * 60 + m1;
		x2 = h2 * 60 + m2;
		a[i][0].x = x1;
		a[i][0].y = x1 + d;
		a[i][1].x = x2 - d;
		a[i][1].y = x2;
		if (x2 - x1 < d)
		{
			flag = false;
		}
	}
	for (i = 0; i < 2 * n; i++)
	{
		pList[i] = NULL;
		pReverseList[i] = NULL;
	}
}
void Insert(int x, int y)
{
	NODE *p = new NODE;
	p->v = y;
	p->next = pList[x];
	pList[x] = p;
}
void InsertReverse(int x, int y)
{
	NODE *p = new NODE;
	p->v = y;
	p->next = pReverseList[x];
	pReverseList[x] = p;
}
void InitList()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[j][0].x >= a[i][0].x && a[j][0].x < a[i][0].y ||
				a[i][0].x >= a[j][0].x && a[i][0].x < a[j][0].y)
			{
				Insert(2 * i, 2 * j + 1);
				InsertReverse(2 * j + 1, 2 * i);

				Insert(2 * j, 2 * i + 1);
				InsertReverse(2 * i + 1, 2 * j);
			}
			if (a[j][0].x >= a[i][1].x && a[j][0].x < a[i][1].y ||
				a[i][1].x >= a[j][0].x && a[i][1].x < a[j][0].y)
			{
				Insert(2 * i + 1, 2 * j + 1);
				InsertReverse(2 * j + 1, 2 * i + 1);

				Insert(2 * j, 2 * i);
				InsertReverse(2 * i, 2 * j);
			}
			if (a[j][1].x >= a[i][1].x && a[j][1].x < a[i][1].y ||
				a[i][1].x >= a[j][1].x && a[i][1].x < a[j][1].y)
			{
				Insert(2 * i + 1, 2 * j);
				InsertReverse(2 * j, 2 * i + 1);

				Insert(2 * j + 1, 2 * i);
				InsertReverse(2 * i, 2 * j + 1);
			}
			if (a[j][1].x >= a[i][0].x && a[j][1].x < a[i][0].y ||
				a[i][0].x >= a[j][1].x && a[i][0].x < a[j][1].y)
			{
				Insert(2 * i, 2 * j);
				InsertReverse(2 * j, 2 * i);

				Insert(2 * j + 1, 2 * i + 1);
				InsertReverse(2 * i + 1, 2 * j + 1);
			}
		}
	}
}
void dfs_topo(int node)
{
	visit[node] = 1;
	NODE *p = pList[node];
	while (p != NULL)
	{
		if (!visit[p->v])
		{
			dfs_topo(p->v);
		}
		p = p->next;
	}
	nCount++;
	t[node] = nCount;
	vt[nCount] = node;
}
void Topo()
{
	int i;
	nCount = 0;
	memset(visit, 0, sizeof(visit));
	for (i = 0; i < 2 * n; i++)
	{
		if (!visit[i])
		{
			dfs_topo(i);
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
void Solve()
{
	int i, k;
	memset(visit, 0, sizeof(visit));
	for (i = 0; flag && i < 2 * n; i++)
	{
		k = vt[i];
		if (visit[k] == 0)
		{
			dfs_Choose(k);
			if (k % 2 == 0)
			{
				dfs_Delete(k + 1);
			}
			else
			{
				dfs_Delete(k - 1);
			}
		}
	}
	int x, y;
	if (!flag)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
		for (i = 0; i < 2 * n; i++)
		{
			if (visit[i] != 1)
			{
				continue;
			}
			x = a[i / 2][i % 2].x / 60;
			y = a[i / 2][i % 2].x % 60;
			printf("%02d:%02d", x, y);
			x = a[i / 2][i % 2].y / 60;
			y = a[i / 2][i % 2].y % 60;
			printf(" %02d:%02d\n", x, y);
		}
	}
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		flag = true;
		Input();
		InitList();
		Topo();
		Solve();
	}
	return 0;
}