#include <iostream>
using namespace std;
int n,m,k;
int a[100200];
bool ok ( _int64 mid )
{
	int i;
	_int64 v,t=m*mid;
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
	}
	if ( t >= 0 )
		return true;
	else
		return false;
}
int main ()
{
	int tcase,i;
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
			if ( ok(mid) == false )
				begin = mid+1;
			else
			{
				if ( ok(mid-1)==false )
				{
					printf("%I64d\n",mid);
					break;
				}
				else
					end = mid;
			}			
		}
		
	}
	return 0;
}