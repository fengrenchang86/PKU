#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp ( const void *a, const void*b )
{
	return ( (int*)b-(int*)a );
}
int n,m,k;
int a[100200];
__int64 t;
bool ok ( int mid )
{
	int i,v;
	t = __int64(m*mid);
	for ( i = 0; i < n; i++ )
	{
		if( a[i] > mid )
		{
			if ( (a[i]-mid)%k==0 )
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
	int tcase,i,v;
	int begin,end,mid;
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
		while ( begin < end )
		{
			mid = (begin+end)/2;
			if ( ok(mid)==false )
				begin = mid+1;
			else
			{
				if (ok(mid-1)==false )
				{
					end = mid;
					break;
				}
				end = mid-1;
			}
		}
	/*	while ( begin < end )
		{
			mid = (begin+end)/2;
			t = (__int64)m*mid;
			for ( i = 0; i < n; i++ )
			{
				if ( a[i] > mid )
				{
					if ( (a[i]-mid)%k==0 )
						v = (a[i]-mid)/k;
					else
						v = (a[i]-mid)/k+1;
					if ( v > t || v > mid )
					{
						t = -1;
						break;
					}
					t -=v;
				}
				else
					break;
			}
			if ( t < 0 )
				begin = mid+1;
			else
				end = mid;
		}
		*/
		printf("%d\n",end);
	}
	return 0;
}