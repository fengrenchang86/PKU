#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp ( const void*a, const void*b )
{
	return *(int*)b-*(int*)a;
}
int a[21000];
int main ()
{
	int n,b,i,j=0;
	scanf("%d%d",&n,&b);
	for ( i = 0; i < n; i++ )
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(a[0]),cmp);
	for ( i = 0; i < n; i++ )
	{
		j += a[i];
		if ( j >= b )
			break;
	}
	printf("%d\n",i+1);
	return 0;
}