#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[1000100];
int cmp ( const void *a , const void *b ) 
{ 
     return *(int *)a - *(int *)b; 
} 
int main ()
{
	int n,i;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
		scanf("%d",&a[i]);
	if ( n <= 3 )
		printf("The set is rejected.\n");
	else
	{
//		sort(a,a+n);
		qsort(a,n,sizeof(a[0]),cmp);
		if ( a[0]+a[1] > a[n-1] )
			printf("The set is rejected.\n");
		else
		{
			for ( i = 2; i < n; i++ )
			{
				if ( a[i-2]+a[i-1]>a[i] )
					break;
			}
			if ( i == n )
				printf("The set is rejected.\n");
			else
				printf("The set is accepted.\n");
		}
	}
	return 0;
}