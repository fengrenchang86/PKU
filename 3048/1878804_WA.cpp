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
	if ( n == 1 )
		return 1;
	int i;
	int t = sqrt(n);
	for ( i = 1; i <= t; i++ )
		if ( n%i == 0 )
			return 0;
	return 1;
}
int main ()
{
//	int prime[2000];
	int i;
//	int last = 	make ( prime)-1;
	int n;
	cin>>n;
	int num;
	int max = 0;
	int j;
	int k;
	int su = 0;
	int fac;
	for ( i = 0; i < n; i++ )
	{
		su = 0;
		cin>>num;
		k = num;
		for ( j = 1; j <= k; j++ )
		{
			su = ip ( j );
			if ( su == 0 )
				continue;
			if ( k%j==0 )
			{
				k/=j;
				if ( j > max )
				{
					max = j;
					fac = num;
				}
			}
		}
		
	}
	cout<<fac<<endl;
	return 1;
}