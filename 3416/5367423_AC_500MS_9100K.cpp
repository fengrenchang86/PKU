#include <iostream>
#include <stdlib.h>
using namespace std;

struct ac
{
	int x, y;
	int ntype;
}p[600010];
int t[2000040];
int n, m, k;
int acmax;
struct wf
{
	int small, big;
}q[500010];
int cmp(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	if(c->x != d->x)
		return c->x - d->x;
	else
		return c->y - d->y;
}
int cmp2(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	if(c->x != d->x)
		return d->x - c->x;
	else
		return d->y - c->y;
}
void Input()
{
	int i;
	scanf("%d %d", &n, &m);
	acmax = 0;
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &p[i].x, &p[i].y);
		p[i].ntype = -1;
	}
	for(i = 0; i < m; i++)
	{
		scanf("%d %d", &p[i+n].x, &p[i+n].y);
		p[i+n].ntype = i;
	}
	k = n + m;
	for(i = 0; i < k; i++)
	{
		if(p[i].y > acmax)
			acmax = p[i].y;
	}
}
void Insert(int data)
{
	int nBegin, nEnd, nMid;
	nBegin = 0;
	nEnd = acmax;
	int i = 1;
	while(nBegin < nEnd)
	{
		nMid = (nBegin + nEnd) / 2;
		t[i]++;
		if(data <= nMid)
		{
			nEnd = nMid;
			i = i * 2;
		}
		else
		{
			nBegin = nMid + 1;
			i = i * 2 + 1;
		}
	}
	t[i]++;
}
int FindData(int i, int nBegin, int nEnd, int left, int right)
{
	if(nBegin == left && nEnd == right)
		return t[i];
	int nMid = (nBegin + nEnd) / 2;
	if(right <= nMid)
		return FindData(i * 2, nBegin, nMid, left, right);
	else if(left > nMid)
		return FindData(i * 2 + 1, nMid + 1, nEnd, left, right);
	else
		return FindData(i * 2, nBegin, nMid, left, nMid) + FindData(i * 2 + 1, nMid + 1, nEnd, nMid + 1, right);
}
void Solve()
{
	int i, j, v;
	qsort(p, n + m, sizeof(p[0]), cmp);
	for(i = 0; i < 2000040; i++)
	{
		t[i] = 0;
	}
	for(i = 0; i < k; i++)
	{
		if(p[i].ntype == -1)
		{
			Insert(p[i].y);
		}
		else
		{
			j = FindData(1, 0, acmax, 0, p[i].y);
			q[p[i].ntype].small = j;
		}
	}
	qsort(p, n + m, sizeof(p[0]), cmp2);
	for(i = 0; i < 2000040; i++)
	{
		t[i] = 0;
	}
	v = 0;
	for(i = 0; i < k; i++)
	{
		if(p[i].ntype == -1)
		{
			Insert(p[i].y);
			v++;
		}
		else
		{
			j = FindData(1, 0, acmax, p[i].y, acmax);
			q[p[i].ntype].big = j;
		}
	}
	for(i = 0; i < m; i++)
	{
		j = q[i].big + q[i].small;
		j = abs(2*j-n);
		printf("%d\n", j);
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
		if(tc)
			printf("\n");
	}
	return 0;
}