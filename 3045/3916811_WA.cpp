#include<iostream>
#include <stdlib.h>
using namespace  std;
struct ac
{
	int w, h;
}a[50100];
int sum[50100];
int n;
int cmp (const void*a, const void*b)
{
	struct ac* c = (ac*)a;
	struct ac* d = (ac*)b;
	return c->w + c->h - d->w + d->h;
}
void MissHH()
{
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i].w, &a[i].h);
	}
	qsort(a, n, sizeof(a[0]), cmp);
}
void LoveHH()
{
	int ans = -2000000000;
	if(n == 1)
		ans = -a[0].h;
	int i;
	sum[0] = a[0].w;
	for(i = 1; i < n; i++)
		sum[i] = sum[i-1] + a[i].w;
	for(i = 1; i < n; i++)
	{
		if(sum[i-1] - a[i].h > ans)
			ans = sum[i-1] - a[i].h;
	}
	printf("%d\n", ans);
}
int main ()
{
	scanf("%d", &n);
	MissHH();
	LoveHH();
	return 0;
}