#include <iostream>
using namespace std;
int main ()
{
	short dp[120][120];
	short c[120][120];
	short i,j,k,n,m;
	int max;
	scanf("%d%d",&n,&m);
	for ( i = 0; i < n; i++ )
		for ( j = 0; j < m; j++ )
			scanf("%d",&c[i][j]);
	for ( i = 0; i < m; i++ )
		dp[0][i] = c[0][i];
	for ( i = 1; i < n; i++ )
	{
		dp[i][i] = dp[i-1][i-1]+c[i][i];
		for ( j = i+1; j < m; j++ )
		{
			max = -60000;
			for ( k = i-1; k < j; k++ )
			{
				if ( max < dp[i-1][k] )
					max = dp[i-1][k];
			}
			dp[i][j] = max+c[i][j];
		}
	}
	max = -60000;
	for ( i = n-1; i < m; i++ )
		if ( dp[n-1][i] > max )
			max = dp[n-1][i];
		cout<<max<<endl;
	return 0;
}