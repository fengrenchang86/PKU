#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int x,y;
	int id;
}a[60000];
int cmp1 ( const void*a, const void*b )
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return d->x - c->x;
}
int cmp2 ( const void*a, const void*b )
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return d->y - c->y;
}
int main ()
{
	int n,k,i;
	scanf("%d%d",&n,&k);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d%d",&a[i].x, &a[i].y);
		a[i].id = i+1;
	}
	qsort(a,n,sizeof(a[0]),cmp1);
	qsort(a,k,sizeof(a[0]),cmp2);
	printf("%d\n",a[0].id);
	return 0;
}