#include <iostream>
#include <math.h>
using namespace std;
__int64 MAX = 1152921504606846976;
int n, m;
int Check(__int64 nVal)
{
	int i, j, k = 0, l = 0;
	double x, y;
	for (j = 1; j <= n; j++)
	{
		x = double(100000.0 + j) * double(100000.0 + j) - 4.0 * double(j * j - 100000.0 * j - nVal);
		if (x < 0)
		{
			i = 0;
			k += i;
		}
		else
		{
			x = sqrt(x);
			y = (double)(x - 100000.0 - j) / 2.0;
			i = (int)y;
			if (__int64(i) * __int64(i) + 100000 * __int64(i) + __int64(j) * __int64(j) - 100000 * __int64(j) + __int64(i) * __int64(j)
				== nVal)
			{
				if (l == 0)
				{
					l = 1;
					i--;
				}
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
			if (nBegin == nMid)
			{
				break;
			}
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
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d %d", &n, &m);
		Solve();
	}
	return 0;
}