#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp ( const void *a , const void *b ) 
{ 
     return *(int *)a - *(int *)b; 
} 
int main ()
{
	int a[1002];
	int i,n,sum;
	int tcase;
	scanf("%d",&tcase);
	while ( tcase )
	{
		scanf("%d",&n);
		for ( i = 1; i <= n; i++ )
			scanf("%d",&a[i]);
		a[0] = 0;
		if ( n == 1 )
		{
			printf("%d\n",a[1] );
			tcase--;
			continue;
		}
		qsort ( a, n+1, sizeof(a[0]),cmp);
		sum = 0;
		if ( n % 2 == 0 )
		{
			for ( i = 4; i <= n; i+=2 )
				sum += a[i];
			sum += ( (n/2-1)*(a[1]+2*a[2]) + a[2] );
		}
		else
		{
			for ( i = 5; i <= n; i+=2 )
				sum += a[i];
			sum += ( (n/2-1)*(a[1]+2*a[2]) + a[1] + a[2] + a[3] );
		}
		printf("%d\n",sum);
		tcase--;
	}
	return 0;
}