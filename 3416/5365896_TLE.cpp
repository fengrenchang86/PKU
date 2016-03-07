#include <iostream>
#include <stdlib.h>
using namespace std;

struct ac
{
	int x, y;
}p[60000];
struct TREE
{
	int num;
	int min;
	int max;
}t[200000];
int a[60000];
int n, m, k;
int cmp(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	if(c->x != d->x)
		return c->x - d->x;
	else
		return d->y - c->y;
}
void Input()
{
	int i;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &p[i].x, &p[i].y);
	}
	qsort(p, n, sizeof(p[0]), cmp);
	a[0] = p[0].x;
	k = 1;
	for(i = 1; i < n; i++)
	{
		if(p[i].x != p[i-1].x)
		{
			a[k++] = p[i].x;
		}
	}
	for(i = 0; i < 200000; i++)
	{
		t[i].num = 0;
		t[i].max = -10000000;
		t[i].min = 10000000;
	}
}
void Insert(int i, int nBegin, int nEnd, ac v)
{
	t[i].num++;
	if(t[i].max < v.y)
		t[i].max = v.y;
	if(t[i].min > v.y)
		t[i].min = v.y;
	if(nBegin != nEnd)
	{
		int nMid = (nBegin + nEnd) / 2;
		if(a[nMid] >= v.x)
			Insert(i * 2, nBegin, nMid, v);
		else
			Insert(i * 2 + 1, nMid + 1, nEnd, v);
	}
}
int FindHigh(int i, int nBegin, int nEnd, int nleft, int nright, int high)
{
	if(t[i].max < high)
		return 0;
	else if(t[i].min > high && nBegin == nleft && nEnd == nright)
		return t[i].num;
	int nMid = (nBegin + nEnd) / 2;
	if(nright <= nMid)
		return FindHigh(i * 2, nBegin, nMid, nleft, nright, high);
	else if(nleft > nMid)
		return FindHigh(i * 2 + 1, nMid + 1, nEnd, nleft, nright, high);
	else
		return FindHigh(i * 2, nBegin, nMid, nleft, nMid, high) + FindHigh(i * 2 + 1, nMid + 1, nEnd, nMid + 1, nright, high);
}
int FindLow(int i, int nBegin, int nEnd,  int nleft, int nright, int low)
{
	if(t[i].max < low && nBegin == nleft && nEnd == nright)
		return t[i].num;
	else if(t[i].min > low)
		return 0;
	int nMid = (nBegin + nEnd) / 2;
	if(nright <= nMid)
		return FindLow(i * 2, nBegin, nMid, nleft, nright, low);
	else if(nleft > nMid)
		return FindLow(i * 2 + 1, nMid + 1, nEnd, nleft, nright, low);
	else 
		return FindLow(i * 2, nBegin, nMid, nleft, nMid, low) + FindLow(i * 2 + 1, nMid + 1, nEnd, nMid + 1, nright, low);
}
int GetID(int x)
{
	int nBegin, nEnd, nMid;
	nBegin = 1;
	nEnd = k - 1;
	while(nBegin < nEnd)
	{
		nMid = (nBegin + nEnd) / 2;
		if(p[nMid].x > x)
			nEnd = nMid;
		else
			nBegin = nMid + 1;
	}
	return nBegin - 1;
}
void Solve()
{
	int i;
	int x, y, j;
	int ans;
	for(i = 0; i < n; i++)
	{
		Insert(1, 0, k - 1, p[i]);
	}
	for(i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		ans = 0;
		if(x < a[0])
		{
			j = 0;
			ans = FindLow(1, 0, k - 1, j, k - 1, y);
		}
		else if(x > a[k-1])
		{
			j = k - 1;
			ans = FindHigh(1, 0, k - 1, 0, j, y);
		}
		else
		{
			j = GetID(x);
			ans = FindHigh(1, 0, k-1, 0, j, y);
			ans += FindLow(1, 0, k -1, j + 1, k - 1, y);
		}
		printf("%d\n", abs(2*ans-n));
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