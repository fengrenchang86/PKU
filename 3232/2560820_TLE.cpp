#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp ( const void *a, const void*b )
{
	return ( (int*)b-(int*)a );
}
int n,m,k;
int a[100200];
_int64 v,t;
bool ok ( _int64 mid )
{
	int i;
	t=_int64(m*mid);
	for ( i = 0; i < n; i++ )
	{
		if( a[i] > mid )
		{
			if( (a[i]-mid)%k == 0 )
				v = (a[i]-mid)/k;
			else
				v = (a[i]-mid)/k+1;
			if ( v > mid || v > t )
				return false;
			t -= v;
		}
		else
			return true;
	}
	return true;
}
int main ()
{
	int tcase,i;
	_int64 begin,end,mid;
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		scanf("%d",&n);
		v = 0;
		for ( i = 0; i < n; i++ )
		{
			scanf("%d",&a[i]);
			if ( a[i] > v )
				v = a[i];
		}
		scanf("%d%d",&m,&k);
		if ( k == 1 )
		{
			printf("%I64d\n",v);
			continue;
		}
		qsort(a,n,sizeof(a[0]),cmp);
		k--;
		begin = 1;
		end = v;
		mid = (begin+end)/2;
		while ( begin < end )
		{
			if ( ok(mid) == false )
				begin = mid+1;
			else
				end = mid;
			mid = (begin+end)/2;
		}
		printf("%I64d\n",end);
	}
	return 0;
}