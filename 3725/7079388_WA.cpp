#include<iostream>
using namespace std;
int m, k;
int acPow[20];
int ans[20];
int ansPos;
int a[20],b[20], c[20];
int sa, sb;
int GetCount(int nPos)
{
	if (sb < nPos)
	{
		return 0;
	}
	int i, j = -1, rt = 0;
	for (i = 0; i <= nPos && i < sb; i++)
	{
		if (c[i] > b[i])
		{
			j = nPos + 1;
			break;
		}
		else if (c[i] < b[i])
		{
			j = nPos;
			break;
		}
	}
	if (j == -1)
	{
		i = sb - nPos - 2;
		while (i >= 0)
		{
			rt += acPow[i];
			i--;
		}
		j = 0;
		for (i = nPos + 1; i < sb; i++)
		{
			j *= 10;
			j += b[i];
		}
		j++;
		rt += j;
		return rt;
	}
	i = sb - j - 1;
	while (i >= 0)
	{
		rt += acPow[i];
		i--;
	}
	return rt;
}
int Compare(int pos)
{
	if (pos - 1 > sb)
	{
		return 0;
	}
	else if (pos-1 < sb)
	{
		return 1;
	}
	int i;
	for (i = 0; i <= pos; i++)
	{
		if (a[i] > b[i])
		{
			return 0;
		}
		else if (a[i] < b[i])
		{
			return 1;
		}
	}
	return 1;
}
int CalueRank(int k, int n)
{
	int i, j;
	sa = sb = 0;
	j = k;
	while (j)
	{
		c[sa++] = j % 10;
		j /= 10;
	}
	for (i = 0; i < sa; i++)
	{
		a[i] = c[sa-i-1];
	}
	j = n;
	while (j)
	{
		c[sb++] = j % 10;
		j /= 10;
	}
	for (i = 0; i < sb; i++)
	{
		b[i] = c[sb-i-1];
	}
	int nRank = 0;
	for (i = 0; i < sa; i++)
	{
		for (j = 0; j < a[i]; j++)
		{
			if (i+j==0)
			{
				continue;
			}
			c[i] = j;
			nRank += GetCount(i);
		}
		c[i] = a[i];
		if (i < sa - 1)
		{
			nRank += Compare(i);
		}
	}
	return nRank + 1;
}
void Solve()
{
	int n;
	int nBegin, nEnd, nMid;
	nBegin = k;
	nEnd = 1000000001;
	int x;
	while (nBegin < nEnd)
	{
		nMid = (nBegin + nEnd) / 2;
		x = CalueRank(k, nMid);
		if (x < m)
		{
			nBegin = nMid + 1;
		}
		else if (x >= m)
		{
			nEnd = nMid;
		}
	}
	if (nBegin > 0 && nBegin < 1000000001)
	{
		printf("%d\n", nBegin);
		return ;
	}
	printf("0\n");
}
int main()
{
	int i;
	acPow[0] = 1;
	for (i = 1; i <= 9; i++)
	{
		acPow[i] = 10 * acPow[i-1];
	}
	while (scanf("%d %d", &m, &k) != EOF)
	{
		Solve();
	}
	return 0;
}