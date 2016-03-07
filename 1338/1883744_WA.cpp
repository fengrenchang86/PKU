#include <iostream>
#include <math.h>
using namespace std;
int makeprime ( int p[])
{
	int i;
	int j;
	int c = 0;
	for ( i = 7; c < 1500; i++ )
	{
		for ( j = 2; j <= sqrt(i); j++ )
			if ( i%j==0 )
				break;
		if ( i % j != 0 )
			p[c++] = i;
	}
	return c;
}

int main ()
{
	unsigned int i;
	int j;
	int p[1600];
	int q = makeprime(p);
//	for ( i = 0; i < q; i++ )
//		cout<<p[i]<<" ";
	int c = 6;
	int u[1600];
	u[0] = 1;
	u[1] = 2;
	u[2] = 3;
	u[3] = 4;
	u[4] = 5;
	u[5] = 6;
//	for ( i = 0; i < 6; i++ )
//		cout<<u[i]<<" ";
	for ( i = 7; c < 1500; i++ )
	{
		for ( j = 0; p[j] < i; j++ )
			if ( i%p[j] == 0 )
				break;
		if ( i%p[j] != 0 )
		{
			u[c++] = i;
		//	cout<<u[c-1]<<" ";
		}
	}
	int n;
	while ( cin>>n && n!= 0 )
		cout<<u[n-1]<<endl;
	/*
	for ( i = 0; i < 32; i++ )
	{
		p2[i] = pow(2,i);
		cout<<i<<" "<<p2[i]<<endl;
	}
	for ( i = 0; i < 20; i++ )
	{
		p3[i] = pow(3,i);
		cout<<i<<" "<<p3[i]<<endl;
	}
	for ( i = 0; i < 15; i++ )
	{
		p5[i] = pow(5,i);
		cout<<i<<" "<<p5[i]<<endl;
	}
	*/
	/*
	unsigned int a[1510];
	int c = 0;
	int k;
	for ( i = 2; c < 1500; i++ )
	{
		k = i;
		while ( k % 2 == 0 )
			k/=2;
		while ( k%3==0 )
			k/=3;
		while ( k%5==0 )
			k/=5;
		if ( k == 1 )
			a[c++] = i;
	}
	for ( i = 0; i < 1500; i++ )
		cout<<a[i]<<" ";
	*/
	return 1;
}

