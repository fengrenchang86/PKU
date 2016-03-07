#include <iostream>
using namespace std;
int a[520];
int main ()
{
	int tc,n,m,i,j,k;
	int begin,end,mid;
	scanf("%d",&tc);
	while (tc-- )
	{
		scanf("%d%d",&n,&m);
		for ( i = 0; i < n; i++ )
			scanf("%d",&a[i]);
		begin = 1;
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
				cout<<a[i]<<" ";
			else
				cout<<-a[i]<<" / ";
		}
		cout<<endl;
	}
	return 0;
}