#include <iostream>
using namespace std;
__int64 a[520];
int main ()
{
	__int64 tc,n,m,i,j,k;
	__int64 begin,end,mid;
	scanf("%I64d",&tc);
	while (tc-- )
	{
		scanf("%I64d%I64d",&n,&m);
		begin = -1;
		for ( i = 0; i < n; i++ )
		{
			scanf("%I64d",&a[i]);
			if ( begin < a[i] )
				begin = a[i];
		}
		end = 10000000;
		while ( begin < end )
		{
			mid = (begin+end)/2;
			j = 0;
			k = 1;
			for ( i = 0; i < n && k <= m; i++ )
			{
				if ( j + a[i] <= mid )
					j += a[i];
				else
				{
					k++;
					j = a[i];
				}
			}
			if ( k <= m )
				end = mid;
			else
				begin = mid+1;
		}
//		cout<<begin<<endl;
		k = 1;
		j = 0;
		for ( i = n-1; i >= 0; i-- )
		{
			if ( a[i] + j > begin )
			{
				j = a[i];
				a[i] *= -1;
				k++;
			}
			else if ( m-k-1 == i )
			{
				a[i] *= -1;
				k++;
			}
			else
			{
				j += a[i];
			}
		}
		for ( i = 0; i < n; i++ )
		{
			if ( a[i] > 0 )
				printf("%I64d ",a[i]);
			else
			{
				printf("%I64d",-a[i]);
				cout<<" / ";
			}
		}
		cout<<endl;
	}
	return 0;
}