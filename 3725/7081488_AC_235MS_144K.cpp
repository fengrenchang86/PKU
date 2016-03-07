#include <iostream>
using namespace std;
long long acPow[20];
int arrn[20];
int sn;
long long GetRank(long long n, int m)
{
	long long rt = 0;
	int i, k, l, j = m;
	long long x = 0;
	sn = 0;
	while (j)
	{
		arrn[sn++] = j % 10;
		j /= 10;
	}
	j = x = 0;
	for (i = sn - 1; i >= 0 && x < n; i--)
	{
		x = x * 10 + arrn[i];
		if (x > n)
		{
			x = n;
		}
		if (x < acPow[j])
		{
			break;
		}
		rt += (x - acPow[j++] + 1);
	}
	if (x < n)
	{
		x--;
	}
	while (x < n && x)
	{
		x = x * 10 + 9;
		if (x > n)
		{
			x = n;
		}
		if (x - acPow[j] + 1 <= 0)
		{
			break;
		}
		rt += (x - acPow[j++] + 1);
	}
	return rt;
}
void Solve(int m, int k)
{
	long long nBegin, nEnd, nMid;
	long long n = 0;
	long long x;
	nBegin = m > k ? m : k;
	nEnd = 1000000000000000000;
	while (nBegin < nEnd)
	{
		nMid = (nBegin + nEnd) / 2 ;
		x = GetRank(nMid, m);
		if (x > k)
		{
			nEnd = nMid;
		}
		else if (x < k)
		{
			nBegin = nMid + 1;
		}
		else
		{
			n = nMid;
			nEnd = nMid - 1;
		}
	}
	x = GetRank(nEnd, m);
	if (x == k)
	{
		n = nBegin;
	}
	x = GetRank(nBegin, m);
	if (x == k)
	{
		n = nBegin;
	}

	printf("%lld\n", n);
}
int main()
{
	int m, k;
	int i;
	acPow[0] = 1;
	for (i = 1; i <= 18; i++)
	{
		acPow[i] = acPow[i-1] * 10;
	}
	while (scanf("%d %d", &k, &m) != EOF)
	{
		Solve(m, k);
	}
	return 0;
}