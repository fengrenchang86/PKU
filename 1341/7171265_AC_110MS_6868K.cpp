#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>
using namespace std;
int n, m, mod;
int a1, a2, a3, s1, s2, s3, e1, e2, e3;
int s[100020], e[100020], r[100020], a[100020];
int dp[100020][30];
int acm(int x, int y)
{
	return x < y ? x : y;
}
void Init()
{
	int i, j;
	mod = n / 2;
	for (i = 0; i < n; i++)
	{
		a[i] = ((a1% 9973 * i % 9973) % 9973 * i % 9973 + a2 % 9973 * i%9973 + a3) % 9973;
		dp[i][0] = a[i];
	}
	for (i = 0; i < m; i++)
	{
		s[i] = ((s1 % mod * i% mod) % mod * i % mod + s2 % mod * i% mod + s3) % mod;
		e[i] = ((e1 % mod* i% mod) % mod * i % mod+ e2% mod * i% mod + e3) % mod + s[i];
		if (s[i] >= n)
		{
			s[i] = n-1;
		}
		if (e[i] >= n)
		{
			e[i] = n-1;
		}
	}
}
void Solve()
{
	int i, j, k, l = 2;
	
	for (j = 1; l <= n; j++, l*=2)
	{
		for (i = 0; i + (1<<j) - 1 < n; i++)
		{
			dp[i][j] = acm(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
		}
	}
	l = 0;
	k = -1;
	for (i = 0; i < m; i++)
	{
		j = (int)(log((double)(e[i] - s[i] + 1)) / log(2.0));
		r[i] = acm(dp[s[i]][j], dp[e[i]-(1<<j)+1][j]);
		if (r[i] > r[l])
		{
			l = i;
		}
	}
	printf("%d\n", l);
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d %d %d %d %d %d %d %d %d %d %d", &n, &a1, &a2, &a3, &m, &s1, &s2, &s3, &e1, &e2, &e3);
		Init();
		Solve();
	}
	return 0;
}