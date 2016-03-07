#include <iostream>
using namespace std;
#define INF 2000000000
int h[100100];
int dp[2][110];
int n, c;
int a[2][110], b[2][110];
int Getmin(int x, int y)
{
	return x < y ? x : y;
}
int Getmin(int x, int y, int z)
{
	return Getmin(x, y < z ? y : z);
}
int main()
{
	int i, j, k;
	scanf("%d %d", &n, &c);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &h[i]);
	}
	for (j = 0; j <= 101; j++)
	{
		a[0][j] = a[1][j] = INF;
		b[0][j] = b[1][j] = INF;
		dp[0][j] = dp[1][j] = INF;
	}
	for (j = h[0]; j <= 100; j++)
	{
		dp[0][j] = (j-h[0])*(j-h[0]);
		a[0][j] = Getmin(dp[0][j] - c * j, a[0][j-1]);
	}
	for (j = 100; j >= 1; j--)
	{
		b[0][j] = Getmin(dp[0][j] + c * j, b[0][j+1]);
	}
	for (i = 1; i < n; i++)
	{
		a[i%2][h[i]-1] = INF;
		b[i%2][101] = INF;
		for (j = 0; j <= 100; j++)
		{
			dp[i%2][j] = INF;
			a[i%2][j] = b[i%2][j] = INF;
		}
		for (j = h[i]; j <= 100; j++)
		{
			dp[i%2][j] = Getmin(a[(i-1)%2][j] + c * j, b[(i-1)%2][j] - c * j) + (j-h[i])*(j-h[i]);
			a[i%2][j] = Getmin(dp[i%2][j] - c * j, a[i%2][j-1]);
		}
		for (j = 100; j >= 1; j--)
		{
			b[i%2][j] = Getmin(dp[i%2][j] + c * j, b[i%2][j+1]);
		}
	}
	k = INF;
	for (j = h[i]; j <= 100; j++)
	{
		k = Getmin(k, dp[(n-1)%2][j]);
	}
	printf("%d\n", k);
	return 0;
}
