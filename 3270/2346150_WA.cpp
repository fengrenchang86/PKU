#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int data;
	int pos;
	int rank;
}a[10010];
int cmp ( const void *a, const void *b )
{
	return (*(ac*)a).data - (*(ac*)b).data;
}
int main ()
{
	int i,j,t,n;
	_int64 sum = 0;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d",&a[i].data);
		a[i].pos = i;
	}
	qsort(a,n,sizeof(a[0]),cmp);
	for ( i = 0; i < n; i++ )
		a[i].rank = i;
	for ( i = 0; i < n; i++ )
	{
		while ( a[i].pos != a[i].rank )
		{
			j = a[i].pos;
			sum += a[i].data+a[j].data;
			t = a[j].pos;
			a[j].pos = a[i].pos;
			a[i].pos = t;
		}
	}
	printf("%I64d\n",sum);
	return 0;
}