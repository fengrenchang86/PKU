#include <iostream>
using namespace std;
int dp[1010][12100];
int a[1001];
int n;
int GetMin(int x, int y)
{
	return x < y ? x : y;
}
int GetMax(int x, int y)
{
	return x > y ? x : y;
}
void Input()
{
	int i ,x ,y;
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		a[i] = x - y + 6000;
	}
}

void Solve()
{
	int nAdd = 6000;
	int i, j, k = 0;
	for(i = 0; i < n; i++)
		k += (a[i] - 6000);
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= 12000; j++)
			dp[i][j] = n;
	}
	for(i = 0; i < n; i++)
	{
		dp[i][a[i]] = 1;
		dp[i][6000] = 0;
	}
	for(i = 1; i < n; i++)
	{
		for(j = 0; j <= 12000; j++)
		{
			if(j >= a[i]-6000)
				dp[i][j] = GetMin(dp[i-1][j], dp[i-1][j-a[i]+6000]+1);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	if(k % 2 == 0)
	{
		printf("%d\n", dp[n-1][k/2 + 6000]);
	}
	else
	{
		if(k > 0)
			printf("%d\n", GetMax(dp[n-1][k/2+6000], dp[n-1][k/2+6001]));
		else
			printf("%d\n", GetMax(dp[i-1][k/2+6000], dp[i-1][k/2+5999]));
	}
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}