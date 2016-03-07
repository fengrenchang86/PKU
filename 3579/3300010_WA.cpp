
#include <iostream>
#include <stdlib.h>
using namespace std;
int arr[100100];
int n;
__int64 m;
int cmp ( const void*a, const void*b )
{
	return *(int*)a - *(int*)b;
}
int f ( int x, int key )
{
	int begin = x+1,end=n,mid=(begin+end)/2;
	while ( begin < end )
	{
		if ( arr[mid]-arr[x] >= key )
			end = mid;
		else
			begin = mid+1;
		mid = (begin+end)/2;
	}
	if ( arr[mid]-arr[x] > key )
		return mid-x-1;
	return mid-x;
}
int main ()
{
	int i,j;
	int begin,end,mid;
	while ( scanf("%d",&n) != EOF )
	{
		m = n;
		m = m*(m-1)/2;
		m = (m-1)/2;
		for ( i = 1; i <= n; i++ )
			scanf("%d",&arr[i]);
		arr[0] = -2000000000;
		qsort(arr,n+1,sizeof(arr[0]),cmp);
		begin = 0;
		end = arr[n]-arr[1];
		mid = (begin+end)/2;
		while ( begin < end )
		{
			j = m+1;
			for ( i = 1; i < n; i++ )
			{
				j-=f(i,mid);
				if ( j < 0 )
					break;
			}
			if ( j <= 0 )
				end = mid;
			else if ( j > 0 )
				begin = mid+1;
			mid = (begin+end)/2;
		}
		printf("%d\n",mid);
	}
	return 0;
}