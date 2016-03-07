#include <iostream>
using namespace std;
int main ()
{
	int a[100200];
	int tcase,n,m,k,i;
	_int64 begin,end,mid;
	_int64 t,v;
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		scanf("%d",&n);
		v = 0;
		for ( i = 0; i < n; i++ )
		{
			scanf("%d",&a[i]);
			if ( a[i] > k )
				v = a[i];
		}
		scanf("%d%d",&m,&k);
		if ( k == 1 )
		{
			printf("%I64d\n",v);
			continue;
		}
		k--;
		begin = 0;
		end = v;
		while ( begin+1 <= end )
		{
			mid = (begin+end)/2;
			t = mid*m;
			for ( i = 0; i < n; i++ )
			{
				if ( a[i] > mid )
				{
					if ( (a[i]-mid)%k == 0 )
						v = (a[i]-mid)/k;
					else
						v = (a[i]-mid)/k+1;
					if ( v > mid )
						t = -1;
					else
						t -= v;
					if ( t < 0 )
						break;
				}
			}
			if ( t < 0 )
				begin = mid+1;
			else
				end = mid;
			
		}
		printf("%I64d\n",end);
	}
	return 0;
}