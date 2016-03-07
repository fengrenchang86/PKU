#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp( const void*a, const void*b)
{
	return *(int*)a-*(int*)b;
}
int main ()
{
	int i,j,n,sum=0;;
	int a[101];
	int *c[110];
	scanf("%d",&n);
	for ( i = 1; i <= n; i++ )
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
	for ( i = 0; i < 110; i++ )
		c[i] = new int[sum+1];
	a[0] = -1;
	qsort(a,n+1,sizeof(a[0]),cmp);
	for ( j = 0; j <= sum; j++ )
		c[0][j] = 0;
	for ( i = 0; i <= n; i++ )
		c[i][0] = 0;
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= sum; j++ )
		{
			if ( j >= a[i] )
				c[i][j] = c[(i-1)][j-a[i]]+a[i];
			else
				c[i][j] = c[(i-1)][j];
		}
	}
	i = sum;
	for ( j = 1; j <= sum; j++ )
	{
		if ( abs(sum - 2*c[n][j]) < i )
		{
			i = abs(sum-2*c[n][j]);
			a[0] = c[n][j];
		}
	}
	if ( sum - a[0] > a[0] )
	{
		i = a[0];
		j = sum-a[0];
	}
	else
	{
		j = a[0];
		i = sum-a[0];
	}
	printf("%d %d\n",i,j);
	return 0;
}
