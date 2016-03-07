#include <iostream>
#include <stdlib.h>
using namespace std;
int a[100100];
int cmp ( const void*a, const void *b )
{
	return ((int*)a-(int*)b);
}
int min ( int a, int b )
{
	return a<b?a:b;
}
int min ( int a, int b, int c )
{
	return min(min(a,b),min(b,c));
}
int find ( int key, int n )
{
	int begin,end,mid;
	begin = 0;
	end = n-1;
	while ( begin < end )
	{
		mid = (begin+end)/2;
		if ( key > a[mid] )
			begin = mid+1;
		else
			end = mid;
	}
	return begin;
}
int main ()
{
	int n,m,i,key,pos;
	__int64 sum = 0;
	scanf("%d%d",&n,&m);
	for ( i = 0; i < n; i++ )
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(a[0]),cmp);
	for ( i = 0; i < m; i++ )
	{
		scanf("%d",&key);
		pos = find(key,n);
		if ( pos > 0 && pos < n-1 )
			sum += min(abs(key-a[pos]),abs(key-a[pos-1]),abs(key-a[pos+1]));
		else if ( pos > 0 )
			sum += min(abs(key-a[pos]),abs(key-a[pos-1]));
		else if ( pos < n-1 )
			sum += min(abs(key-a[pos]),abs(key-a[pos+1]));
		else
			sum += abs(key-a[pos]);
	}
	printf("%I64d\n",sum);
	return 0;
}