#include <iostream>
#include <stdlib.h>
using namespace std;
int n,len;
int a[110000];
int cmp ( const void*a, const void*b )
{
	return *(int*)a - *(int*)b;
}
int main ()
{
	int i,j,k;
	scanf("%d%d",&n,&len);
	for ( i = 0; i < n; i++ )
		scanf("%d",&a[i]);
	i = 0;
	j = n-1;
	k = 0;
	while ( i < j )
	{
		if ( a[i] + a[j] <= len )
		{
			i++;
			j--;
			k++;
		}
		else
		{
			j--;
			k++;
		}
	}
	if ( i == j )
		k++;
	printf("%d\n",k);
	return 0;
}