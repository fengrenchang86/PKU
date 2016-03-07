#include <iostream>
#include <math.h>
using namespace std;
int make ( int a[] )
{
	a[0]=2;
	int c = 1;
	int i;
	int j;
	int t;
	for ( i = 3; c < 1300; i+=2 )
	{
		t = sqrt(i);
		for ( j = 2; j <= t; j++ )
		{
			if ( i%j==0 )
				break;
		}
		if ( i%j!=0 )
			a[c++] = i;
	}
	return c-1;
}


int main ()
{
	int a[2000];
	int max = make(a);
	int p;
	int i;
	int j;
	int c;
	int sum;
	while ( cin>>p && p!=0 )
	{
		sum = 0;
		c = 0;
		for ( i = 0; a[i]<=p; i++ )
		{
			for ( j = i; sum < p; j++ )
			{
				sum += a[j];
			}
			if ( sum == p )
				c++;
			sum = 0;
		}
		cout<<c<<endl;
	}
	return 1;
}