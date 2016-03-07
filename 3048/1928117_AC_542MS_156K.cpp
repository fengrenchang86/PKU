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
	for ( i = 3; i < 20000; i++ )
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
	int prime[10000];
	int i;
	int size = 	make ( prime);
	int n;
	cin>>n;
	int num;
	int max = 0;
	int j;
	int k = 0;
	int su;
	int fac;
	for ( i = 0; i < n; i++ )
	{
		cin>>num;
		if ( num != 1 )
		for ( j = 0; ; j++ )
		{
			if ( num%prime[j]==0 )
				k = j;
			if (prime[j] >= num)
				break;
		}
		else
			k = 1;
		if ( k > max )
		{
			su = num;
			max = k;
		}
	}
	cout<<su<<endl;
	return 1;
}