#include <iostream>
using namespace std;
int main ()
{
	int dp[120][120];
	int c[120][120];
	int i,j,k,n,m,max;
	scanf("%d%d",&n,&m);
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < m; j++ )
		{
			scanf("%d",&c[i][j]);
			dp[i][j] = -2000000000;
		}
		dp[i][i] = c[i][i];
	}
	for ( i = 0; i < m; i++ )
		dp[0][i] = c[0][i];
	for ( i = 1; i < n; i++ )
	{
		dp[i][i] = dp[i-1][i-1]+c[i][i];
		for ( j = i+1; j < m; j++ )
		{
			max = -2000000000;
			for ( k = i; k < j; k++ )
			{
				if ( max < dp[i-1][k] )
					max = dp[i-1][k];
			}
			dp[i][j] = max+c[i][j];
		}
	}
	k = -2000000000;
	for ( i = n-1; i < m; i++ )
		if ( dp[n-1][i] > k )
			k = dp[n-1][i];
		cout<<k<<endl;
	return 0;
}