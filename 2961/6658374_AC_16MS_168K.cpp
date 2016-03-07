#include <iostream>
using namespace std;
int GetResult(long long n, long long x, long long y)
{
	if (n == 1)
	{
		return 1;
	}
	n /= 2;
	if (x < n && y < n)
	{
		return GetResult(n, x, y);
	}
	else if (x < n && y >= n)
	{
		return GetResult(n, x, y-n);
	}
	else if (x >= n && y < n)
	{
		return GetResult(n, x-n, y);
	}
	else
	{
		return -1 * GetResult(n, x-n, y-n);
	}
}
int main()
{
	int tc;
	long long n, x, y;
	int w, h;
	int i, j;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%lld %lld %lld %d %d", &n, &x, &y, &w, &h);
		for (i = 0; i < h; i++)
		{
			for (j = 0; j < w; j++)
			{
				printf("%d ", GetResult(n, y+i, x+j));
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}