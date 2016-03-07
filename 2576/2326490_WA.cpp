#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp( const void*a, const void*b)
{
	return *(int*)a-*(int*)b;
}
int main ()
{
	int i,j,n,sum=0;
	int a[101];
//	int *c[110];
	int c[2][45100];
	int num[2][45100];
	scanf("%d",&n);
	for ( i = 1; i <= n; i++ )
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
	if ( n == 1 )
	{
		printf("0 %d\n",a[1]);
		return 0;
	}
//	for ( i = 0; i < 110; i++ )
//		c[i] = new int[sum+1];
	a[0] = -1;
	qsort(a,n+1,sizeof(a[0]),cmp);
	for ( j = 0; j <= sum; j++ )
		num[0][j] = c[0][j] = 0;
//	for ( i = 0; i <= n; i++ )
//		c[i][0] = 0;	
	c[1][0] = 0;
	num[1][0] = 0;
	int x , y;
	x = sum;
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= sum; j++ )
		{
			if ( j >= a[i] && c[(i-1)%2][j-a[i]]+a[i] > c[(i+1)%2][j] )
			{
				c[i%2][j] = c[(i+1)%2][j-a[i]]+a[i];
				num[i%2][j] = num[(i+1)%2][j-a[i]]+1;
				if ( abs(n-2*num[i%2][j]) <= 1 )
				{
					if ( abs(sum-2*c[i%2][j]) < x )
					{
						x = abs(sum-2*c[i%2][j]);
						y = c[i%2][j];
					}
				}
			}
			else
			{
				c[i%2][j] = c[(i+1)%2][j];
				num[i%2][j] = num[(i+1)%2][j];
				if ( abs(n-2*num[i%2][j]) <= 1 )
				{
					if ( abs(sum-2*c[i%2][j]) < x )
					{
						x = abs(sum-2*c[i%2][j]);
						y = c[i%2][j];
					}
				}
			}
		}
	}
	i = sum;
	a[0] = y;
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
//	printf("c[n][sum] = c[%d][%d] = %d\n",n,sum,c[n][sum]);
	printf("%d %d\n",i,j);
	return 0;
}
