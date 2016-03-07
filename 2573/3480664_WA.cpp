#include <iostream>
#include <stdlib.h>
using namespace std;
int a[1010];
int dp[1010];
int path[1010];
int n;
int cmp ( const void*a, const void*b )
{
	return *(int*)a - *(int*)b;
}
void print ( int k )
{
	if ( k == 2 )
	{
		printf("%d %d\n",a[1],a[2]);
	}
	else if ( k == 3 )
	{
		printf("%d %d\n",a[1],a[2]);
		printf("%d\n",a[1]);
		printf("%d %d\n",a[1],a[3]);
	}
	else
	{
		if ( path[k] == 1 )
		{
			print(k-1);
			printf("%d\n",a[1]);
			printf("%d %d\n",a[1],a[k]);
		}
		else
		{
			print(k-2);
			printf("%d\n",a[1]);
			printf("%d %d\n",a[n-1],a[n]);
			printf("%d\n",a[2]);
			printf("%d %d\n",a[1],a[2]);
		}
	}
}
int main ()
{
	int i;
	while ( scanf("%d",&n) != EOF )
	{
		a[0] = 0;
		for ( i = 1; i <= n; i++ )
			scanf("%d",&a[i]);
		qsort(a,n+1,sizeof(a[0]),cmp);
		if ( n == 0 )
			printf("0\n");
		else if ( n == 1 )
		{
			printf("%d\n",a[1]);
			printf("%d\n",a[1]);
		}
		else if ( n == 2 )
		{
			printf("%d\n",a[2]);
			printf("%d %d\n",a[1],a[2]);
		}
		else if ( n == 3 )
		{
			printf("%d\n",a[1]+a[2]+a[3]);
			printf("%d %d\n",a[1],a[2]);
			printf("%d\n",a[1]);
			printf("%d %d\n",a[1],a[3]);
		}
		else
		{
			dp[0] = a[0];
			dp[1] = a[1];
			dp[2] = a[2];
			dp[3] = a[1]+a[2]+a[3];
			for ( i = 4; i <= n; i++ )
			{
				if ( dp[i-1]+a[1]+a[n] <= dp[i-2]+a[1]+a[n]+2*a[2] )
				{
					dp[i] = dp[i-1]+a[1]+a[n];
					path[i] = 1;
				}
				else
				{
					dp[i] = dp[i-2]+a[1]+a[n]+2*a[2];
					path[i] = 2;
				}
			}
			printf("%d\n",dp[n]);
			print(n);
		}
	}
	return 0;
}