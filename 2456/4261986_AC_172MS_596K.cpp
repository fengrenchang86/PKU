#include <iostream>
#include <stdlib.h>
using namespace std;

int a[100100];
int n, c;

int cmp(const void*a, const void*b)
{
	return *(int*)a - *(int*)b;
}
bool check(int mid)
{
	int i, j = 1, k = a[0];
	for(i = 1; i < n; i++)
	{
		if(a[i] - k >= mid)
		{
			k = a[i];
			j++;
		}
	}
	return j >= c;
}
void Solve()
{
	int i, start, end, mid;
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	qsort(a, n, sizeof(a[0]), cmp);
	start = 1;
	end = a[n-1] - a[0];
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
	scanf("%d %d", &n, &c);
	Solve();
	return 0;
}