#include<iostream>
using namespace std;
int a[40000];
int dp[40000];
int main ()
{
	int n,i,j=0,k;
	scanf(" %d",&n);
	dp[0] = 0;
	for (i=1; i<= n; i++ )
	{
		scanf("%d",&a[i]);
		if ( a[i] == 2 )
			dp[i] = dp[i-1]+1;
		else
			dp[i] = dp[i-1];
	}
	k = 2000000000;
	for ( i = 0; i <= n; i++ )
	{
		if ( n-i-dp[n]+dp[i]+dp[i] < k )
			k = n-i-dp[n]+dp[i]+dp[i];
	}
	printf("%d\n",k);
	return 0;
}