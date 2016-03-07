
#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp ( const void *a, const void*b )
{
	return ( (int*)b-(int*)a );
}
int n,m,k;
int a[200200];
__int64 t,v;
bool ok(__int64 t)
	{
		int i;
		__int64 tmp=0,j=m*t;
		for(i=0;i<n;i++)
		{
			if (a[i]-t<=0)
				continue;
			if ((a[i]-t)%(k-1)==0)
				tmp=(a[i]-t)/(k-1);
			else
				tmp=(a[i]-t)/(k-1)+1;
			
			if (tmp>t||tmp>j)
				return false;
			j-=tmp;
		}
		return true;
	}
int main ()
{
	int tcase,i;
	__int64 begin,end,mid;
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		scanf("%d",&n);
		v = 0;
		for ( i = 0; i < n; i++ )
		{
//			a[i] = (rand()*rand())%100000000;
			scanf("%d",&a[i]);
			if ( v < a[i] )
				v = a[i];
		}
		scanf("%d%d",&m,&k);
	//	m = rand();
	//	k = rand();
		if ( k == 1 )
		{
			printf("%d\n",v);
			continue;
		}
		k--;
		begin = 1;
		end = v;
		while ( begin < end )
		{
			mid = (begin+end)/2;
			if ( ok(mid)==false )
				begin = mid+1;
			else
				end = mid;
		}

		printf("%I64d\n",end);
	}
	return 0;
}
