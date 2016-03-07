#include <iostream>
#include <stdlib.h>
using namespace std;

int cmp ( const void *a , const void *b ) 
{ 
     return *(int *)a - *(int *)b; 
} 

int a[20010];
_int64 dp[20010];
_int64 sum[20010];
int main ()
{
	int n,i;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(a[0]),cmp);
	sum[0] = a[0];
	for ( i = 1; i < n; i++ )
		sum[i] = sum[i-1] + a[i];
	dp[1] = sum[1];
	dp[2] = sum[2]+sum[1];
	for ( i = 3; i < n; i++ )
	{
		if ( a[i]+dp[i-2] > dp[i-1] )
			dp[i] = sum[i]+sum[i-1]+dp[i-1];
		else
			dp[i] = sum[i]*2+dp[i-2];
	}
	printf("%I64d\n",dp[n-1]);
	return 0;
}