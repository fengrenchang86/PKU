#include <iostream>
using namespace std;
struct ac
{
	int len,c;
	ac(){len=1;c=0;}
}dp[1050000];
int maxlen,count;
int n;
int v[1050000];
void dfs ( int k, int lay )
{
	if ( v[k] <= lay )
		v[k] = lay;
	else
		return;
	if ( k == n )
	{
		if ( lay > maxlen )
		{
			maxlen = lay;
			count=1;
		}
		else if ( lay == maxlen )
			count++;
		return;
	}
	int i;
	for ( i = 2; i*k <= n; i++ )
	{
		if ( n % (i*k)==0 )
			dfs(i*k,lay+1);
	}
}
void DP ()
{
	dp[1].len = 0;
	dp[1].c = 1;
	int i,j;
	for ( i = 1; i <= 1048576; i++ )
	{
		for ( j = 2; j*i <= 1048576; j++ )
		{
			if ( dp[j*i].len < dp[i].len + 1 )
			{
				dp[j*i].len = dp[i].len + 1;
				dp[j*i].c = dp[i].c;
			}
			else if ( dp[j*i].len == dp[i].len+1 )
				dp[j*i].c += dp[i].c;
		}
	}
}
int main ()
{
int i = 0;
	while ( scanf("%d",&n)!=EOF )
	{
   if ( i == 0 )
   DP();
else
i++;
		cout<<dp[n].len<<" "<<dp[n].c<<endl;
	}
	return 0;
}
