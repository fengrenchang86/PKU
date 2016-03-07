
#include<iostream>
#include<stdlib.h>
using namespace std;
struct ac
{
	int x, y;
}a[1020000];
int N, M, K;
int tree[1200];
int tmax;
int cmp(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	if(c->x != d->x)
		return c->x - d->x;
	else
		return c->y - d->y;
}
int lowbit(int t)
{
    return t & (t^(t-1)); 
}
void modify(int pos,int num)
{
    while (pos<=M) 
	{
        tree[pos]+=num;
        pos+=lowbit(pos);
    }
}
int query(int end)
{
    int sum=0;
    while (end>0) 
	{
        sum+=tree[end];
        end-=lowbit(end);
    }
    return sum;
}

void init()
{
	tmax = 0;
	memset(tree, 0, sizeof(tree));
}

void LoveHH(int k)
{
	scanf("%d %d %d", &N, &M, &K);
	int i;
	__int64 ans = 0;
	for(i = 0; i < K; i++)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	qsort(a, K, sizeof(a[0]), cmp);
	for(i = 0; i < K; i++)
	{
		ans += __int64(i-query(a[i].y));
		modify(a[i].y, 1);
	}
	printf("Test case %d: %I64d\n", k, ans);
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
/*
////////////////////////////////////////////////
////////////////线段树解法!!!///////////////////
////////////////////////////////////////////////
#include<iostream>
#include<stdlib.h>
using namespace std;
struct ac
{
	int x, y;
}a[1020000];
struct TREE
{
	int val, cover;
}tree[60000];
int N, M, K;
int tmax;
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
	tmax = 0;
}
void MissHH(int i, int begin, int end, int z)
{
	tree[i].val++;
	if(begin == end)
		return;
	int mid = (begin+end)/2;
	if(z <= mid)
		MissHH(i*2, begin, mid, z);
	else
		MissHH(i*2+1, mid+1, end, z);
}
__int64 SearchHH(int i, int begin, int end, int x, int y)
{
	if(begin == end)
		return tree[i].val;
	else if(begin == x && end == y)
		return tree[i].val;
	int mid = (begin+end)/2;
	if(y <= mid)
		return SearchHH(i*2, begin, mid, x, y);
	else if(x > mid)
		return SearchHH(i*2+1, mid+1, end, x, y);
	else
		return SearchHH(i*2, begin, mid, x, mid) + SearchHH(i*2+1, mid+1, end, mid+1, y);
}
void LoveHH(int k)
{
	int i;
	__int64 ans = 0;
	scanf("%d%d%d", &N, &M, &K);
	for(i = 0; i < K; i++)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		if(a[i].y > tmax)
			tmax = a[i].y;
	}
	qsort(a, K, sizeof(a[0]), cmp);
	for(i = 0; i < K; i++)
	{
		ans += SearchHH(1, 0, tmax+1, a[i].y+1, tmax+1);
		MissHH(1, 0, tmax+1, a[i].y);
	}
	printf("Test case %d: %I64d\n", k, ans);
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
}*/
