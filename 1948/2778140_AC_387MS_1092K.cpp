#include <iostream>
#include <math.h>
using namespace std;
bool dp[2][1000][1000] = {0};
int max = -1;
int s ( int a, int b, int c )
{
	double p = (a+b+c)/2.0;
	 return int(100*sqrt(p*(p-a)*(p-b)*(p-c)));
}
int main ()
{
	int a[50],sum[50];
	int i,j,k,n,z;
	sum[0] = 0;
	cin>>n;
	for ( i = 1; i <= n; i++ )
	{
		cin>>a[i];
		sum[i] = sum[i-1] + a[i];
	}
	dp[1][a[1]][0] = 1;
	dp[1][0][0] = 1;
	dp[1][0][a[1]] = 1;
	for ( i = 2; i <= n; i++ )
	{
		for ( j = 1; j < sum[i] && j < sum[n]/2; j++ )
		{
			for ( k = 1; k <= j && j+k <= sum[i]; k++ )
			{
				if ( dp[(i-1)%2][j][k] == true)
					dp[i%2][j][k] = true;
				else if ( j >= a[i] && dp[(i-1)%2][j-a[i]][k] == true )
					dp[i%2][j][k] = true;
				else if (dp[(i-1)%2][j][k-a[i]] == true && k >= a[i] )
					dp[i%2][j][k] = true;
				if ( dp[i%2][j][k] == true )
				{
					z = sum[n]-k-j;
					if ( z != 0 && k+j>z&& k+z>j )
					{
						z = s(j,k,z);
						if ( z > max )
							max = z;
					}
				}
			}
		}
	}
	cout<<max<<endl;
	return 0;
}