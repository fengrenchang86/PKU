#include<iostream>
using namespace std;
#define  N 1010
#define  inf 2000000000
int cost[N][N];
int dp[N];
int PCcost, n;
void MissHH()
{
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		for(j = i; j < n; j++)
			scanf("%d", &cost[i][j]);
	}
}
void LoveHH()
{
	int i, j;
	dp[0] = PCcost;
	for(i = 1; i < n; i++)
	{
		dp[i] = inf;
		for(j = 0; j < i; j++)
		{
			if(PCcost + dp[j] + cost[j][i-1] < dp[i])
				dp[i] = PCcost + dp[j] + cost[j][i-1];
		}
	}
	j = inf;
	for(i = 0; i < n; i++)
	{
		if(dp[i] + cost[i][n-1] < j)
			j = dp[i] + cost[i][n-1];
	}
	printf("%d\n", j);
}
int main ()
{
	while(scanf("%d", &PCcost)!=EOF)
	{
		MissHH();
		LoveHH();
	}
	return 0;
}