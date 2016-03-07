#include <iostream>
#include <vector>
using namespace std;
struct ac
{
	int status;
	ac *next;
}*pList[11000];
int a[16];
bool v[16];
int wa[20];
int n;
int w[65538];
int ans;
void DFS(int choose, int val, int status)
{
	if (choose == 5)
	{
		if (val > n)
		{
			n = val;
		}
		ac *p = new ac;
		p->status = status;
		p->next = pList[val];
		pList[val] = p;
		return;
	}
	int i;
	for (i = 0; i < 16; i++)
	{
		if (!v[i])
		{
			v[i] = 1;
			DFS(choose + 1, val + choose * a[i], status | wa[i]);
			v[i] = 0;
		}
	}
}
void dfs(int lay, int choose, int status)
{
	if (choose == 8)
	{
		ans += w[status] * w[(status) ^ 0xffff];
		return;
	}
	if (8 < lay-choose)
	{
		return;
	}
	v[lay] = 1;
	dfs(lay + 1, choose + 1, status | wa[lay]);
	v[lay] = 0;
	dfs(lay + 1, choose, status);
}
void Init()
{
	int i;
	wa[0] = 1;
	for (i = 1; i <= 16; i++)
	{
		wa[i] = wa[i-1] * 2;
	}
	for (i = 0; i <= 10230; i++)
	{
		pList[i] = 0;
	}
}
void Solve(int tc)
{
	int i, j, k;
	for (i = 1; i < 16; i++)
	{
		scanf("%d", &a[i]);
	}
	Init();
	n = 0;
	memset(v, 0, sizeof(v));
	memset(w, 0, sizeof(w));
	DFS(1, 0, 0);
	ac *p, *q;
	for (i = 1; i <= n; i++)
	{
		p = pList[i];
		while (p != NULL)
		{
			q = p->next;
			while (q != NULL)
			{
				if ((p->status & q->status) == 0)
				{
					w[p->status | q->status] ++;
				}
				q = q->next;
			}
			p = p->next;
		}
	}
	ans = 0;
	memset(v, 0, sizeof(v));
	for (i = 0; i <= 65536; i++)
	{
		ans += w[i] * w[(~i) & 0xffff];
	}
	printf("Case %d: %d\n", tc, ans/2);
}
int main()
{
	int tc = 1;
	while (scanf("%d", &a[0]) != EOF)
	{
		if (a[0] == 0)
		{
			break;
		}
		Solve(tc);
		tc++;
	}
	return 0;
}