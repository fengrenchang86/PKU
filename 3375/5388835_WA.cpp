#include <iostream>
#include <stdlib.h>
using namespace std;
int a[100009];
int b[2009];
int dp[2][100009];
int n, m;
#define INF 2100000000
int GetMin(int x, int y)
{
	return x < y ? x : y;
}
int cmp(const void*a, const void*b)
{
	return *(int*)a - *(int*)b;
}
int Find(int key)
{
	int nBegin, nEnd, nMid;
	nBegin = 0;
	nEnd = m-1;
	while(nBegin < nEnd)
	{
		nMid = (nBegin + nEnd)/2;
		if (a[nMid] > key)
		{
			nEnd = nMid;
		}
		else
		{
			nBegin = nMid + 1;
		}
	}
	return nBegin;
}
int Find2(int key)
{
	int nBegin, nEnd, nMid;
	nBegin = 0;
	nEnd = m-1;
	while(nBegin < nEnd)
	{
		nMid = (nBegin + nEnd)/2;
		if (a[nMid] >= key)
		{
			nEnd = nMid;
		}
		else
		{
			nBegin = nMid + 1;
		}
	}
	return nBegin;
}
void Input()
{
	int i;
	for (i = 0; i < m; i++)
	{
		scanf("%d", &a[i]);
//		a[i] = 1000000;
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
//		b[i] = 0;
	}
	qsort(a, m, sizeof(a[0]), cmp);
	qsort(b, n, sizeof(b[0]), cmp);
}
void Solve()
{
	int i, j;
	int x, y, k, t;
	int k1, k2;
	for (i = 0; i < m; i++)
	{
		dp[0][i] = dp[1][i] = INF;
	}
	k1 = Find(b[0]);
	k2 = Find2(b[0]);
	if(k1 < k2)
	{
		x = k1 - n - 1;
		y = k2 + n + 1;
	}
	else
	{
		x = k2 - n - 1;
		y = k1 + n + 1;
	}
	if (x < 0)
		x = 0;
	if (y > m)
		y = m;
	for (i = x; i < y; i++)
	{
		dp[0][i] = abs(a[i] - b[0]);
		if (i > 0 && dp[0][i] > dp[0][i-1])
		{
			dp[0][i] = dp[0][i-1];
		}
	}
	while(i < m)
	{
		dp[0][i] = dp[0][i-1];
		i++;
	}
	for (i = 1; i < n; i++)
	{
		k = i % 2;
		t = (i - 1)%2;
		for (j = 0; j < m; j++)
		{
			dp[k][j] = INF;
		}
		k1 = Find(b[i]);
		k2 = Find2(b[i]);
		if(k1 < k2)
		{
			x = k1 - i - 1;
			y = k2 + n - i + 1;
		}
		else
		{
			x = k2 - i - 1;
			y = k1 + n - i + 1;
	}
		if(x < i)
			x = i;
		if(y > m)
			y = m;
//		dp[i%2][j-1] = INF;
		for (j = x; j < y; j++)
		{
			dp[k][j] = GetMin(dp[t][j-1] + abs(b[i] - a[j]), dp[k][(j-1)]);
		}
		while(j < m)
		{
			dp[k][j] = dp[k][j-1];
			j++;
		}
		
	}
	printf("%d\n", dp[(n-1)%2][m-1]);
}
int main()
{
	while (scanf("%d %d", &m, &n) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}