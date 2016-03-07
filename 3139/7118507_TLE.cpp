#include <iostream>
#include <queue>
using namespace std;
struct ac
{
	int status;
	ac *next;
}*pList[11000];
int a[16];
int b[4];
bool v[16];
int acm[20];
int n = 10230;
int w[70000];
int s[11000];
int ans;
void DFS(int choose, int val, int status)
{
	if (choose == 5)
	{
		if (val > n)
		{
			n = val;
		}
		s[val]++;
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
			b[choose-1] = i;
			v[i] = 1;
			DFS(choose + 1, val + choose * a[i], status | acm[i]);
			v[i] = 0;
		}
	}
}
void dfs(int lay, int choose, int status)
{
	if (choose == 8)
	{
		ans += w[status] * w[(~status) & 0xffff];
		return;
	}
	if (lay == 16)
	{
		return;
	}
	if (16 - lay < 8-choose)
	{
//		return;
	}
	v[lay] = 1;
	dfs(lay + 1, choose + 1, status | acm[lay]);
	v[lay] = 0;
	dfs(lay + 1, choose, status);
}
void Init()
{
	int i;
	acm[0] = 1;
	for (i = 1; i <= 16; i++)
	{
		acm[i] = acm[i-1] * 2;
	}
	for (i = 0; i < 10230; i++)
	{
		pList[i] = 0;
	}
}
void Solve(int tc)
{
	int i;
	for (i = 1; i < 16; i++)
	{
		scanf("%d", &a[i]);
	}
	Init();
	n = 0;
	memset(v, 0, sizeof(v));
	memset(s, 0, sizeof(s));
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
	dfs(0, 0, 0);
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