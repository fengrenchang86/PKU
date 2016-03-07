
#include <iostream>
#include <stdlib.h>
using namespace std;

struct ac
{
	int nId;
	int nc[32];
}t[100100];
int sum[100100];
int a[100100];
int N, K, n;
int ans, mod;
int cmp(const void*a, const void*b)
{
	struct ac* c = (ac*)a;
	struct ac* d = (ac*)b;
	int i;
	for(i = 0; i < K; i++)
	{
		if(c->nc[i] != d->nc[i])
			return c->nc[i] - d->nc[i];
	}
	return c->nId - d->nId;
}
bool IsEquare(int x, int y)
{
	int i;
	for(i = 0; i < K; i++)
	{
		if(t[x].nc[i] != t[y].nc[i])
			return false;
	}
	return true;
}
void Input()
{
	int i, j, x;
	for(i = 0; i < K; i++)
	{
		t[0].nc[i] = 0;
	}
	t[0].nId = 0;
	for(i = 1; i <= N; i++)
	{
		scanf("%d", &x);
		for(j = 0; j < K; j++)
		{
			t[i].nc[j] = t[i-1].nc[j] + (x & 1);
			x = x >> 1;
		}
		t[i].nId = i;
	}
/*	for(i = 0; i <= N; i++)
	{
		for(j = 0; j < K; j++)
			printf("%2d", t[i].nc[j]);
		printf("\n");
	}
	printf("......\n");
*/	for(i = 1; i <= N; i++)
	{
		for(j = 1; j < K; j++)
		{
			t[i].nc[j] -= t[i].nc[0];
		}
		t[i].nc[0] = 0;
	}
	qsort(t, N+1, sizeof(t[0]), cmp);
/*	for(i = 0; i <= N; i++)
	{
		for(j = 0; j < K; j++)
			printf("%2d", t[i].nc[j]);
		printf(" id=%d\n", t[i].nId);
	}
*/	j = 0;
	ans = 0;
	for(i = 1; i <= N; i++)
	{
		if(IsEquare(i, i-1) == false)
		{
			if(t[i-1].nId - t[j].nId > ans)
				ans = t[i-1].nId - t[j].nId;
			j = i;
		}
	}
	if(IsEquare(i-1, j) == true)
	{
		if(t[i-1].nId - t[j].nId > ans)
			ans = t[i-1].nId - t[j].nId;
	}
	printf("%d\n", ans);
}
int main()
{
	while(scanf("%d %d", &N, &K) != EOF)
	{
		Input();
	}
	return 0;
}
