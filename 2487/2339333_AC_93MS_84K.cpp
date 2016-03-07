#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp ( const void*a , const void *b )
{
	return *(short*)b - *(short*)a;
}
int main ()
{
	short tcase,it;
	int n,need,i;
	int sum;
	short a[1001];
	scanf("%d",&tcase);
	for ( it = 1; it <= tcase; it++ )
	{
		scanf("%d%d",&need,&n);
		for ( i = 0; i < n; i++ )
			scanf("%d",&a[i]);
		qsort(a,n,sizeof(a[0]),cmp);
		sum = 0;
		for ( i = 0; i < n; i++ )
		{
			sum += a[i];
			if ( sum >= need )
				break;
		}
		printf("Scenario #%d:\n",it);
		if ( i < n )
			printf("%d\n",i+1);
		else
			printf("impossible\n");
		printf("\n");
	}
	return 0;
}