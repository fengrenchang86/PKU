#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp ( const void *a, const void*b )
{
	return ( (int*)b-(int*)a );
}
int n,m,k;
int a[100200];
_int64 v,t,mid;
bool ok ()
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
	int begin,end;
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		scanf("%d",&n);
		for ( i = 0; i < n; i++ )
			scanf("%d",&a[i]);
		qsort(a,n,sizeof(a[0]),cmp);
		scanf("%d%d",&m,&k);
		if ( k == 1 )
		{
			printf("%d\n",a[0]);
			continue;
		}
		k--;
		begin = 1;
		end = a[0];
		mid = (begin+end)/2;
		while ( begin < end )
		{
			if ( ok() == false )
				begin = mid+1;
			else
				end = mid;
			mid = (begin+end)/2;
		}
		printf("%d\n",end);
	}
	return 0;
}