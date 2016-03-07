#include <iostream>
#include <stdlib.h>
int cmp ( const void *a , const void *b ) 
{ 
     return *(int *)a - *(int *)b; 
} 
using namespace std;
int main ()
{
	_int64 sum = 0;
	int n;
	int i;
	cin>>n;
	int *a = new int[n+1];
	a[0] = -1;
	for ( i = 1; i <= n; i++ )
		scanf("%d",&a[i]);
	qsort(a,n+1,sizeof(a[0]),cmp);
	for ( i = 1; i <= n; i++ )
		sum += (_int64)(n-2*i+1)*a[n-i+1];
	sum *= 2;
	printf("%I64d\n",sum);
	return 0;
}