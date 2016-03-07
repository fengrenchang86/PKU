#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int x,y;
}a[60000];
int cmp ( const void *a, const void*b )
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	if ( c->x != d->x )
		return c->x - d->x;
	else
		return c->y - d->y;
}
int main ()
{
	int n,i,j,k;
	while ( cin>>n && n )
	{
		for ( i = 0; i < n; i++ )
			scanf("%d%d",&a[i].x,&a[i].y);
		qsort(a,n,sizeof(a[0]),cmp);
		j = 0;
		k = -1;
		for ( i = n-1; i >= 0; i-- )
		{
			if ( a[i].y > k )
			{
				k = a[i].y;
				j++;
			}
		}
		printf("%d\n",j);
	}
	return 0;
}