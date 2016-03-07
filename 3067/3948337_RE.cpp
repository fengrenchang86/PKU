#include<iostream>
#include<stdlib.h>
using namespace std;
struct ac
{
	int x, y;
}a[1020];
struct TREE
{
	int val, cover;
}tree[60000];
int N, M, K;

int cmp(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	if(c->x != d->x)
		return c->x - d->x;
	else
		return c->y - d->y;
}
void init()
{
	int i;
	for(i = 0; i < 60000; i++)
		tree[i].val = tree[i].cover = 0;
}
void MissHH(int i, int begin, int end, int z)
{
	tree[i].val++;
	if(begin == end)
		return;
	int mid = (begin+end)/2;
	if(z <= mid)
		MissHH(i*2, begin, mid, z);
	else if(z > mid)
		MissHH(i*2+1, mid+1, end, z);
}
int SearchHH(int i, int begin, int end, int x, int y)
{
	if(begin == end)
		return tree[i].val;
	else if(begin == x && end == y)
		return tree[i].val;
	int mid = (begin+end)/2;
	int tx = 0, ty = 0;
	if(y <= mid)
		tx = SearchHH(i*2, begin, mid, x, y);
	else if(x > mid)
		ty = SearchHH(i*2+1, mid+1, end, x, y);
	else
	{
		tx = SearchHH(i*2, begin, mid, x, mid);
		ty = SearchHH(i*2+1, mid+1, end, mid+1, y);
	}
	return tx + ty;
}
void LoveHH(int k)
{
	int i;
	int ans = 0;
	scanf("%d%d%d", &N, &M, &K);
	for(i = 0; i < K; i++)
		scanf("%d%d", &a[i].x, &a[i].y);
	qsort(a, K, sizeof(a[0]), cmp);
	for(i = 0; i < K; i++)
	{
		ans += SearchHH(1, 0, K+1, a[i].y+1, K+1);
		MissHH(1, 0, K+1, a[i].y);
	}
	printf("Test case %d: %d\n", k, ans);
}
int main ()
{
	int tc, it;
	scanf("%d", &tc);
	for(it = 1; it <= tc; it++)
	{
		init();
		LoveHH(it);
	}
	return 0;
}