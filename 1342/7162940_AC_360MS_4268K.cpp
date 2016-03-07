#include <iostream>
using namespace std;
int n, m;
int a[1026][1026];
int acPow[30];
int acNew[30];
long long ans;
int acm(int x, int y)
{
	return x < y ? x : y;
}
int acm(int x1, int x2, int x3, int x4)
{
	return acm(acm(x1, x2), acm(x3,x4));
}
void Input()
{
	scanf("%d", &m);
	int i, j;
	n = acPow[m];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
//			a[i][j] = rand();
		}
	}
}
void dfs(int lay)
{
	int i, j, t;
	int k = acPow[lay];
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < k; j++)
		{
			t = acm(a[i*2][j*2], a[i*2+1][j*2], a[i*2][j*2+1], a[i*2+1][j*2+1]);
			ans += (long long)(a[i*2][j*2] + a[i*2+1][j*2] + a[i*2][j*2+1] + a[i*2+1][j*2+1] - 4*t);
			a[i][j] = t;
		}
	}
	ans += (long long)(k*k);
	if (lay > 0)
	{
		dfs(lay-1);
	}
}
void Solve()
{
	ans = acPow[m] * acPow[m];
	dfs(m-1);
	ans += (long long)(a[0][0]);
	printf("%lld\n", ans);
}
int vv[1025][1025];
int main()
{
	int i;
	acPow[0] = 1;
	for (i = 1; i <= 15; i++)
	{
		acPow[i] = acPow[i-1] * 2;
	}
	scanf("%d", &i);
	while (i--)
	{
		Input();
		Solve();
	}
	return 0;
}