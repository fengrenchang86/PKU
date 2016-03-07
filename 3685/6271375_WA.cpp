#include <iostream>
#include <math.h>
using namespace std;
__int64 MAX = 115292150460684;
int n;
__int64 m;
int Check(__int64 nVal)
{
	int i, j;
	__int64 k = 0, l = 0;
	double x, y;
	for (j = 1; j <= n; j++)
	{
		x = double(100000.0 + j) * double(100000.0 + j) - 4.0 * double(double(j) * (double)j - 100000.0 * (double)j - nVal);
		if (j == 46341)
		{
			j = 46341;
		}
		if (x < 0)
		{
			i = 0;
		}
		else
		{
			x = sqrt(x);
			y = (double)(x - 100000.0 - (double)j) / 2.0;
			i = (int)y;
			if (i > 0 && i <= n && l == 0 && double(i) * double(i) + (double)100000 * double(i) + double(j) * double(j) 
				- (double)100000 * double(j) + double(i) * double(j)
				== nVal)
			{
				l = 1;
				i--;
			}
			if (i < 0)
			{
				i = 0;
			}
			if (i > n)
			{
				i = n;
			}
			k += i;
		}
		if (k > m || k == m && l == 0)
		{
			return false;
		}
	}
	k += l;
	if (k == m && l == 1)
	{
		return 2;
	}
	else if (k >= m)
	{
		return false;
	}
	return true;
}
void Solve()
{
	__int64 nBegin, nEnd, nMid;
	nBegin = -MAX;
	nEnd =	  MAX;
	int k;
	while (nBegin < nEnd)
	{
		nMid = (nBegin + nEnd) / 2;
		k = Check(nMid);
		if (k == true)
		{
			if (nBegin == nMid + 1)
			{
				break;
			}
			nBegin = nMid + 1;
		}
		else if (k == 2)
		{
			nBegin = nMid;
			break;
		}
		else
		{
			if (nEnd == nMid)
			{
				break;
			}
			nEnd = nMid;
		}
	}
	printf("%I64d\n", nBegin);
}
int main()
{
	int j, i;
	__int64 k;
	k = -MAX;
	i = 50000;
	for (j = 1; j <= 50000; j++)
	{
		__int64 t = double(i) * double(i) + (double)100000 * double(i) + double(j) * double(j) - (double)100000 * double(j) + double(i) * double(j);
		if (t > k)
		{
			k = t;
		}
	}
	printf("%I64d\n", __int64(k));
	k = MAX;
	i = 1;
	for (j = 1; j <= 50000; j++)
	{
		__int64 t = double(i) * double(i) + (double)100000 * double(i) + double(j) * double(j) - (double)100000 * double(j) + double(i) * double(j);
		if (t < k)
		{
			k = t;
		}
	}
//	printf("%I64d\n", __int64(k));
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d %I64d", &n, &m);
		Solve();
	}
	return 0;
}