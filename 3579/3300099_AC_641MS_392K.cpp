
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int arr[100100];
int n;
vector<int>a;
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
		if ( arr[mid]-arr[x] > key )
			end = mid;
		else
			begin = mid+1;
		mid = (begin+end)/2;
	}
	if ( arr[mid]-arr[x] > key )
		return mid-x-1;
	return mid-x;
}
int test()
{
	int i,j;
	a.clear();
	for ( i = 1; i < n; i++ )
	{
		for ( j = i+1; j <= n; j++ )
			a.push_back(arr[j]-arr[i]);
	}
	sort(a.begin(),a.end());
	cout<<a[m]<<endl;
	return a[m];
}
int main ()
{
	int i,j,k;
	int begin,end,mid;
	while ( scanf("%d",&n) != EOF )
//	for ( k = 1; k <= 1000; k++ )
	{
//		n = 2000;
		m = n;
		m = m*(m-1)/2;
		m = (m-1)/2;
		for ( i = 1; i <= n; i++ )
			scanf("%d",&arr[i]);
//		for ( i = 1; i <= n; i++ )
//			arr[i] = (rand()*rand())%1000;
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
	//	printf("******\n");
		printf("%d\n",mid);
	//	test();
	}
	return 0;
}