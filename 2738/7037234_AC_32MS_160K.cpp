#include <iostream>
using namespace std;
int dp[1020][3];
int a[1020];
int n, m;
void Input()
{
	int i;
	m = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		m += a[i];
	}
	for (i = 0; i < n-1; i++)
	{
		dp[i][1] = a[i] > a[i+1] ? a[i] : a[i+1];
	}
}
void Solve(int tc)
{
	int x = 3;
	int i, j;
	for (j = 3; j < n; j += 2)
	{
		for (i = 0; i + j < n; i++)
		{
			dp[i][j%x] = 0;
			if (a[i+1] >= a[i+j] && dp[i][j%x] < dp[i+2][(j-2)%x] + a[i])
			{
				dp[i][j%x] = dp[i+2][(j-2)%x] + a[i];
			}
			if (a[i+j-1] > a[i] && dp[i][j%x] < dp[i][(j-2)%x] + a[i+j])
			{
				dp[i][j%x] = dp[i][(j-2)%x] + a[i+j];
			}
			if (a[i+j] > a[i+1] && dp[i][j%x] < dp[i+1][(j-2)%x] + a[i])
			{
				dp[i][j%x] = dp[i+1][(j-2)%x] + a[i];
			}
			if (a[i] >= a[i+j-1] && dp[i][j%x] < dp[i+1][(j-2)%x] + a[i+j])
			{
				dp[i][j%x] = dp[i+1][(j-2)%x] + a[i+j];
			}
		}
	}
	printf("In game %d, the greedy strategy might lose by as many as %d points.\n", tc, 2*dp[0][(n-1)%x] - m);
}
int main()
{
	int i = 1;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			break;
		}
		Input();
		Solve(i++);
	}
	return 0;
}