#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>
using namespace std;
int n, m, mod;
int a1, a2, a3, s1, s2, s3, e1, e2, e3;
int s[50020], e[50020], r[50020], a[50020];
int dp[50020][20];
int acm(int x, int y)
{
	return x < y ? x : y;
}
void Init()
{
	int i;
	mod = n / 2;
	for (i = 0; i < n; i++)
	{
		a[i] = ((a1 * i) % 9973 * i + a2 * i + a3) % 9973;
		dp[i][0] = a[i];
	}
	for (i = 0; i < m; i++)
	{
		s[i] = ((s1 * i) % mod * i + s2 * i + s3) % mod;
		e[i] = ((e1 * i) % mod * i + e2 * i + e3) % mod + s[i];
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
		j = log((double)(e[i] - s[i] + 1)) / log(2.0);
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