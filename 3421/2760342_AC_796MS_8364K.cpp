#include <iostream>
using namespace std;
struct ac
{
	int len,c;
	ac(){len=1;c=0;}
}dp[1050000];
int n;
void DP (int x, int y)
{
	int i,j;
	for ( i = x; i <= y; i++ )
		for ( j = 2; j*i <= 1048576; j++ )
		{if ( dp[j*i].len < dp[i].len + 1 )
		{
		dp[j*i].len = dp[i].len + 1;
		dp[j*i].c = dp[i].c;
		}
		else if ( dp[j*i].len == dp[i].len+1 )
		dp[j*i].c += dp[i].c;
	}
}
int main ()
{
	dp[1].len = 0;
	dp[1].c = 1;
	int x = 1;
	while ( scanf("%d",&n)!=EOF )
	{
		if ( n > x ){
			DP(x,n);
			x = n+1;
		}
		printf("%d %d\n",dp[n].len,dp[n].c);
	}
	return 0;
}
