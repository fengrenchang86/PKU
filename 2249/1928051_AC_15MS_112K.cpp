#include <iostream>
#include <iomanip>
using namespace std;
int cheng ( int a[], int size, int k )
{
	int i;
	for ( i = 0; i < size; i++ )
		a[i] *= k;
	for ( i = 0; i < size; i++ )
	{
		a[i+1]+=a[i]/10000;
		a[i] %= 10000;
	}
	while ( a[size] > 0 )
		size++;
	return size;
}
int chu ( int a[], int size, int k )
{
	int i;
	for ( i = size-1; i > 0; i-- )
	{
		a[i-1]+=10000*(a[i]%k);
		a[i] /= k;
	}
	a[0] /= k;
	while ( a[size-1] == 0 )
		size--;
	return size;
}
int main ()
{
	int n,k;
	int a[1000];
	int size;
	int i;
	while ( scanf("%d %d",&n,&k ) && !(n==0&&k==0) )
	{
		if ( k == 0 )
		{
			printf("1\n");
			continue;
		}
		if ( n - k < k )
			k = n-k;
		for ( i = 0; i < 1000; i++ )
			a[i] = 0;
		a[0] = 1;
		size = 1;
		for ( i = 0; i < k; i++ )
		{
			size = cheng(a,size,n-i);
			size = chu(a,size,i+1);
		}
		cout<<a[size-1];
		for ( i = size-2; i >= 0; i-- )
			cout<<setw(4)<<setfill('0')<<a[i];
		cout<<endl;
	}
	return 1;
}
