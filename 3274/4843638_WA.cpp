#pragma warning(disable: 4786)
#include <iostream>
#include <map>
using namespace std;

map<__int64, int>ma;
int sum[100100];
int a[100100];
int N, K, n;
int ans, mod;
int GetPow(int x, int y)
{
	int sum = 1;
	int i;
	for(i = 0; i < y; i++)
	{
		sum *= x;
	}
	return sum;
}
void Input()
{
	int i, x;
	ma.clear();
	ans = 0;
	sum[0] = 0;
	mod = GetPow(2, K) - 1;
	for(i = 1; i <= N; i++)
	{
		scanf("%d", &x);
		sum[i] = sum[i-1] + x;
		sum[i] %= mod;
		ma[sum[i]] = i;
	}
	for(i = 1; i <= N; i++)
	{
		x = ma[sum[i]];
		if(x - i > ans)
			ans = x - i;
	}
	printf("%d\n", ans);
}
int main()
{
	while(scanf("%d %d", &N, &K) != EOF)
	{
		Input();
	}
	return 0;
}