#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp ( const void*a ,const void*b )
{
	return abs(*(int*)a)-abs(*(int*)b);
}
int a[60000];
int main ()
{
	int n,m,i;
	int cur;
	scanf("%d%d",&n,&m);
	for ( i = 0; i < m; i++ )
		scanf("%d",&a[i]);
	qsort(a,m,sizeof(a[0]),cmp);
	cur = 0;
	for ( i = 0; i < m; i++ )
	{
		if ( n-abs(cur-a[i]) >= 0 )
		{
			n -= abs(cur-a[i]);
			cur = a[i];
		}
		else
			break;
	}
	printf("%d\n",i);
	return 0;
}