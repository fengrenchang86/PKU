#include<iostream>
using namespace std;
int a[40000];
int dp[40000][4];
int acmin ( int x, int y )
{
	return x<y?x:y;
}
int acmin ( int x, int y, int z )
{
	return acmin(x,acmin(y,z));
}
int main ()
{
	int i,j,k,n;
	scanf("%d",&n);
	for ( i = 1; i <= n; i++)
		scanf("%d",&a[i]);
	k = 2000000000;
	dp[1][1] = dp[1][2] = dp[1][3] = 1;
	dp[1][a[1]] = 0;
	for ( i = 2; i <= n; i++ )
	{
		dp[i][1] = dp[i-1][1];
		if ( a[i] != 1 )
			dp[i][1]++;
		dp[i][2] = acmin(dp[i-1][1],dp[i-1][2]);
		if ( a[i] != 2 )
			dp[i][2]++;
		dp[i][3] = acmin(dp[i-1][1],dp[i-1][2],dp[i-1][3]);
		if ( a[i] != 3 )
			dp[i][3]++;
	}
	k = acmin(dp[n][1],dp[n][2],dp[n][3]);
	for ( i = 2; i <= n; i++ )
	{
		dp[i][1] = acmin(dp[i-1][1],dp[i-1][2],dp[i-1][3]);
		if ( a[i] != 1 )
			dp[i][1]++;
		dp[i][2] = acmin(dp[i-1][2],dp[i-1][3]);
		if ( a[i] != 2 )
			dp[i][2]++;
		dp[i][3] = dp[i-1][3];
		if ( a[i] != 3 )
			dp[i][3]++;
	}
	k = acmin(acmin(k,dp[n][1]),acmin(dp[n][2],dp[n][3]));
	printf("%d\n",k);
	return 0;
}