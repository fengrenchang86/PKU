
#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp  (const void *a, const void *b )
{
	return *(int*)a-*(int*)b;
}
int a[21000];
int b[21000];
int main ()
{
	int n,m,i,j,k;
	while ( scanf("%d%d",&n,&m) != EOF )
	{
		if ( n == 0 && m == 0 )
			break;
		for ( i = 0; i < n; i++ )
			scanf("%d",&a[i]);
		for ( i = 0; i < m; i++ )
			scanf("%d",&b[i]);
		qsort(a,n,sizeof(a[0]),cmp);
		qsort(b,m,sizeof(b[0]),cmp);
		k = i = j = 0;
		while ( i < n && j < m )
		{
			if ( b[j] >= a[i] )
			{
				k += b[j];
				j++;
				i++;
			}
			else
				j++;
		}
		if ( i == n )
			printf("%d\n",k);
		else
			printf("Loowater is doomed!\n");
	}
	return 0;
}