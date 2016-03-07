#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int pos;
	int nSound;
}a[21000];
int nPos, nSum;
int nCount, tmp;
int n;
struct tree
{
	int sum;
	int nCount;
}t[200000];
int cmp(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return c->nSound - d->nSound;
}
void Init()
{
	int i;
	for(i = 0; i < 200000; i++)
	{
		t[i].sum = 0;
	}
	nCount = 0;
	nSum = 0;
}
void Insert(int i, int nBegin, int nEnd, int key)
{
	t[i].nCount++;
	t[i].sum += key;
	int nMid = (nBegin + nEnd) / 2;
	if(nBegin == nEnd)
		return;
	if(key <= nMid)
		Insert(i * 2, nBegin, nMid, key);
	else
		Insert(i * 2 + 1, nMid + 1, nEnd, key);
}
int Search(int i, int nBegin, int nEnd)
{
	int nMid = (nBegin + nEnd) / 2;
	if(nMid == nPos)
	{
		tmp += t[i*2].nCount;
		return t[i*2].sum;
	}
	else if(nMid > nPos)
		return Search(i * 2, nBegin, nMid);
	else
	{
		tmp += t[i*2].nCount;
		return Search(i * 2 + 1, nMid + 1, nEnd) + t[i*2].sum;
	}
}
void Solve()
{
	int i, k;
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &(a[i].nSound), &(a[i].pos));
	}
	qsort(a, n, sizeof(a[0]), cmp);
	Init();
	int ans = 0;
	for(i = 0; i < n; i++)
	{
		nPos = a[i].pos;
		tmp = 0;
		k = Search(1, 1, 20000);
		ans += a[i].nSound * (tmp * nPos - k + nSum - k - (nCount-tmp)*nPos);
		Insert(1, 1, 20000, a[i].pos);
		nCount++;
		nSum += a[i].pos;
	}
	printf("%d\n", ans);
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		Solve();
	}
	return 0;
}