#include <iostream>
using namespace std;
int a[60000];
int l[60000];
int r[60000];
int main ()
{
	int n,i,j,begin,end,mid;
	while ( scanf("%d",&n) !=EOF )
	{
		a[0] = 2000000;
		a[n+1] = -1;
		for ( i = 1; i <= n; i++ )
			scanf("%d",&a[i]);
		l[0] = 0;
		for ( i = 1; i <= n; i++ )
		{
			if ( a[i] < a[i-1] )
				l[i] = i;
			else
			{
				j = i;
				while ( a[i] > a[j-1] )
					j = l[j-1];
				l[i] = j;
			}
		}
		r[n+1] = n+1;
		for ( i = n; i >= 1; i-- )
		{
			if ( a[i] > a[i+1] )
				r[i] = i;
			else
			{
				j = i;
				while ( a[i] < a[j+1] )
					j = r[j+1];
				r[i] = j;
			}
		}
	//	for ( i = 1; i <= n+1; i++ )
	//		printf("%3d",a[i]);
	//	printf("\n");
	//	for ( i = 1; i <= n+1; i++ )
	///		printf("%3d",l[i]);
	//	printf("\n");
	//	for ( i = 1; i <= n+1; i++ )
	//		printf("%3d",r[i]);
	//	printf("\n");
		begin = 0;
		end = n-1;
		while ( begin < end-1 )
		{
			mid = (begin+end)/2;
			for ( i = 1; i+mid <= n; i++ )
			{
				if ( r[i]-i+1 >= mid && l[mid+i] <= i )
					break;
			}
			if ( i+mid <= n )
				begin = mid;
			else
				end = mid-1;
		}
		for ( i = 1; i+end <= n; i++ )
		{
			if ( r[i]-i+1 >= end && l[end+i] <= i )
				break;
		}
		if ( i+end <= n )
			mid = end;
		else
			mid = begin;
		if ( mid == 0 )
			mid = -1;
		cout<<mid<<endl;
	}
	return 0;
}