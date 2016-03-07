#include <iostream>
#include <stdlib.h>
using namespace std;
int n, m, L;
int a[50010];

int cmp(const void*a, const void*b)
{
	return *(int*)a - *(int*)b;
}
bool check(int mid)
{
	int i, j = 0, k;
	k = 0;
	for(i = 0; i <= n; i++)
	{
		if(a[i] - k >= mid)
			k = a[i];
		else
			j++;
		if(j > m)
			return false;
	}
	return j <= m;
}
void Solve()
{
	int i, start, end, mid;
	scanf("%d %d %d", &L, &n, &m);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	qsort(a, n, sizeof(a[0]), cmp);
	a[n] = L;
	start = 0;
	end = L+1;
	while(start < end)
	{
		mid = (start + end) / 2;
		if(check(mid))
			start = mid+1;
		else
			end = mid;
	}
	printf("%d\n", start - 1);
}
int main()
{
	Solve();
	return 0;
}