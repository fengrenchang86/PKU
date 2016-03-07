#include <math.h>
#include <iostream>
using namespace std;
int make ( int a[])
{
	a[0]=1;
	a[1] = 2;
	int i ;
	int j;
	int c = 2;
	for ( i = 3; i < 8000; i++ )
	{
		for ( j = 2; j < sqrt(i); j++ )
			if ( i%j==0 )
				break;
		if ( i%j != 0 )
			a[c++] = i;
	}
	return c;
}
int ip ( int n )
{
	int i;
	int t = sqrt(n);
	for ( i = 2; i <= t; i++ )
		if ( n%i == 0 )
			return 0;
	return 1;
}
int main ()
{
	int prime[2000];
	int i;
	int last = 	make ( prime)-1;
	int n;
	cin>>n;
	int num;
	int max = 0;
	int j;
	int su = 0;
	int fac;
	for ( i = 0; i < n; i++ )
	{
		su = 0;
		cin>>num;
		for ( j = last; j >= 0; j-- )
		{
			if ( num % prime[j] == 0 )
			{
				su = 1;
				break;
			}
		}
		if ( su == 1 )
		{
			if ( prime[j] > max )
			{
				max = prime[j];
				fac = num;
			}
		}
	}
	cout<<fac<<endl;
	return 1;
}