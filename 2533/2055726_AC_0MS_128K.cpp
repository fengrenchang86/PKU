#include <iostream>
using namespace std;
const int max = 10000;
int a[max];
int dp[max];
int main ()
{
	int i,j,n;
	while ( scanf("%d",&n)!=EOF )
	{
//	scanf("%d",&n);
	for ( i = 1; i <= n; i++ )
	{
		scanf("%d",&a[i]);
	}
	for ( i = 1; i <= n; i++ )
		dp[i] = 1;
	for ( i = 1 ; i <= n; i++ )
	{
		for ( j = 1; j < i; j++ )
		{
			if ( a[j] < a[i] && dp[j]+1 > dp[i] )
				dp[i] = dp[j]+1;
		}
	}
	j = 0;
	for ( i = 1; i <= n; i++ )
	{
		if ( dp[i] > j )
			j = dp[i];
	}
	cout<<j<<endl;
	}
	return 0;
}