#include <iostream>
using namespace std;
int dp[12000];
int p[501], w[501];
int x, y, n;
void Input()
{
	int i;
	scanf("%d %d", &x, &y);
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d %d", &p[i], &w[i]);
}
void Solve()
{
	int i, j;
	for(i = 0; i <= 10000; i++)
		dp[i] = -1;
	dp[0] = 0;
	for(i = 0; i < n; i++)
		dp[w[i]] = p[i];
	y -= x;
	for(i = 1; i <= y; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(i >= w[j] && dp[i-w[j]] != -1)
			{
				if(dp[i] == -1 || dp[i] > dp[i-w[j]]+p[j])
					dp[i] = dp[i-w[j]]+p[j];
			}
		}
	}
	if(dp[y] == -1)
		printf("This is impossible.\n");
	else
		printf("The minimum amount of money in the piggy-bank is %d.\n", dp[y]);
}
int main ()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		Input();
		Solve();
	}
	return 0;
}