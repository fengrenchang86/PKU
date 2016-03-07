#include <iostream>
using namespace std;
__int64 n;
__int64 ans[33333];
int a[33333];
__int64 Calue(__int64 x, __int64 d)
{
	__int64 y = (x - d + 1) * x * d + (2 * d * d * d - 3 * d * d + d) / 6;
	return y;
}
__int64 Judge(int d)
{
	__int64 nBegin, nEnd, nMid, x, y;
	nBegin = 1;
	nEnd = 10000000;
	while (nBegin < nEnd)
	{
		nMid = (nBegin + nEnd) / 2;
		x = (nMid + d - 1);
		y = Calue(x, d);
		if (y == n)
		{
			return nMid;
		}
		else if (y > n)
		{
			nEnd = nMid;
		}
		else
			nBegin = nMid + 1;
	}
	x = (nBegin + d - 1);
	y = Calue(x, d);
	if (y == n)
	{
		return nBegin;
	}
	return -1;
}
void Solve()
{
	int i, j, l = 0;
	__int64 k;
	for (i = 32000; i >= 2; i--)
	{
		if ((__int64)i * (__int64)(2 * i + 1) * (__int64)(i + 1) / 6 > n)
		{
			continue;
		}
		k = Judge(i);
		if (k != -1)
		{
			a[l] = i;
			ans[l] = k;
			l++;
		}
	}
	printf("%d\n", l);
	for (i = 0; i < l; i++)
	{
		printf("%d", a[i]);
		for (j = 0; j < a[i]; j++)
		{
			printf(" %I64d", ans[i] + j);
		}
		printf("\n");
	}
}
int main()
{
	while(scanf("%I64d", &n)!=EOF)
	{
		Solve();
	}
	return 0;
}