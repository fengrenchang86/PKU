
#include <iostream>
using namespace std;
int a[10000];
int b[10000];
int n;
int maxL( int n )
{
	for ( int i = 0, temp = 0; i < n; i++ )
		if ( b[i] > temp )
			temp = b[i];
		return temp;
}
int LISdyna ()
{
	int i,j,k;
	for ( i =1,b[0]=1;i < n; i++ )
	{
		for ( j = 0, k=0;j<i;j++ )
		{
			if ( a[j] < a[i] && k < b[j] )
				k = b[j];
		}
		b[i] = k+1;
	}
	return maxL(n);
}
int binary ( int i, int k )
{
	if ( a[i] < b[1])
		return 1;
	for ( int h = 1, j=k; h != j-1; )
	{
		if ( b[k=(h+j)/2] < a[i] )
			h = k;
		else
			j = k;
	}
	return j;
}
int LIS ()
{
	b[1] = a[0];
	for ( int i=1,k=1;i<n;i++ )
	{
		if ( a[i] >= b[k] )
			b[++k] = a[i];
		else
			b[binary(i,k)] = a[i];
	}
	return k;
}
int main ()
{
	int i;
	scanf("%d",&n);
		for ( i = 0; i < n; i++ )
		{
			scanf("%d",&a[i]);
		}
		printf("%d\n",LISdyna());
	return 0;
}