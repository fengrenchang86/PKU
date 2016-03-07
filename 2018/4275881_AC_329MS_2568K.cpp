#include <iostream>
#include <math.h>
using namespace std;
int n, m;
__int64 a[100100];
__int64 b[100100], c[100100];
bool check(__int64 x)
{
	int i, j = 0;
	double y = 0.0;
	for(i = 0; i < n; i++)
		b[i] = a[i] - x;
	for(i = 1; i < n; i++)
	{
		b[i] += b[i-1];
	}
	c[0] = b[0];
	for(i = 1; i < n; i++)
	{
		if(b[i] > c[i-1])
			c[i] = c[i-1];
		else
			c[i] = b[i];
	}
	if(b[m-1] >= 0)
		return true;
	for(i = m; i < n; i++)
	{
		if(b[i] >= c[i-m] || b[i] >= 0)
			return true;
	}
	return false;
}
void Solve()
{
	__int64 start, end, mid;
	start = 1;
	end = 200000000;
	while(start < end)
	{
		mid = (start + end) / 2;
		if(check(mid))
			start = mid + 1;
		else
			end = mid;
	}
	if(check(start) == false)
		start --;
	printf("%I64d\n", start);
}
int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%I64d", &a[i]);
		a[i] *= 1000;
	}
	Solve();
	return 0;
}