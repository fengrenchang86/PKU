#include <iostream>
using namespace std;
const int max = 1100;
int a[max];
int dp[max];
int main ()
{
	int i,j,k,n;
	scanf("%d",&n);
	for ( i = 1; i <= n; i++ )
		scanf("%d",&a[i]);
	for ( i = 1 ; i <= n; i++ )
	{
		for ( j = i-1; j >= 1; j-- )
		{
			if ( a[j] < a[i] )
				break;
		}
		if ( j > 0 )
			dp[i] = dp[j]+1;
		else
			dp[i] = 1;
	}
	j = 0;
	for ( i = 1; i <= n; i++ )
	{
		if ( dp[i] > j )
			j = dp[i];
	}
	cout<<j<<endl;
	return 0;
}