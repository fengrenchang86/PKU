
#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;
int a[1200];
int n, m, t;
struct MINU
{
	int x, y, val;
}minu[1200000], sum[1200000];
int ans;

int cmp(const void*a, const void*b)
{
	return *(int*)a - *(int*)b;
}
int comp(const void*a, const void*b)
{
	struct MINU*c = (MINU*)a;
	struct MINU*d = (MINU*)b;
	return c->val - d->val;
}
void Input()
{
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
//		a[i] = rand()*rand() % 536870911;
//		if(rand() % 2)
//			a[i] *= -1;
	}
	qsort(a, n, sizeof(a[0]), cmp);
}
void Init()
{
	int i, j, k = 0;
	m = t = 0;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(i == j)
				continue;
			minu[m].x = i;
			minu[m].y = j;
			minu[m].val = a[j] - a[i];
			m++;
		}
	}
	qsort(minu, m, sizeof(minu[0]), comp);
	for(i = 0; i < n; i++)
	{
		for(j = i+1; j < n; j++)
		{
			sum[t].x = i;
			sum[t].y = j;
			sum[t].val = a[i] + a[j];
			if(sum[t].val >= minu[0].val && sum[t].val <= minu[m-1].val)
				t++;
		}
	}
	qsort(sum, t, sizeof(sum[0]), comp);
	ans = -2000000000;
}
int Find(int data)
{
	int start = 0, end = t-1;
	int mid = (start + end) / 2;
	while(start < end)
	{
		mid = (start + end) / 2;
		if(sum[mid].val == data)
			mid;
		if(sum[mid].val < data)
			start = mid+1;
		else
			end = mid;
	}
	if(sum[mid].val == data)
		return mid;
	else if(sum[start].val == data)
		return start;
	else if(sum[end].val == data)
		return end;
	else
		return -1;
}
int acMax(int x, int y)
{
	return x > y ? x : y;
}
void Solve()
{
	Input();
	if(n < 4)
	{
		printf("no solution\n");
		return;
	}
	Init();
	int i, j, k, x;
	i = j = 0;
	while(i < m && j < t)
	{
		if(minu[i].val < sum[j].val)
			i++;
		else if(minu[i].val > sum[j].val)
			j++;
		else
		{
			k = j;
			do 
			{
				j = k;
				while(sum[j].val == minu[i].val && j < t)
				{
					if(!(minu[i].x == sum[k].x || minu[i].x == sum[k].y 
						|| minu[i].y == sum[k].x || minu[i].y == sum[k].y))
					{
						x = acMax(acMax(a[minu[i].x], a[minu[i].y]), acMax(a[sum[k].x], a[sum[k].y]));
						if(ans < x)
							ans = x;
					}
					j++;
				}
				i++;
			}while(minu[i].val == minu[i-1].val && i < m);
			j = k+1;
		}
	}
/*	for(i = 0; i < m; i++)
	{
		k = Find(minu[i].val);
		if(k == -1)
			continue;
		if(minu[i].x == minu[i].y || sum[k].x == sum[k].y || minu[i].x == sum[k].x
			|| minu[i].x == sum[k].y || minu[i].y == sum[k].x || minu[i].y == sum[k].y)
			continue;
		k = acMax(acMax(a[minu[i].x], a[minu[i].y]), acMax(a[sum[k].x], a[sum[k].y]));
		if(ans < k)
			ans = k;
	}
	*/
	if(ans == -2000000000)
		printf("no solution\n");
	else
		printf("%d\n", ans);
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
			break;
		Solve();
	}
	return 0;
}