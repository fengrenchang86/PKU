#include<iostream.h>
#include <math.h>
const double e = 2.718281828459;
const double pi = asin(1)*2;
void main ()
{
	int i;
	int n = 4;
	int k;
	double min = 10000;
	double s = 100000;
	double s1;
	double s2;
	k = 1;
	while ( cin>>n && n != 0  )
	{
		n = n-1960;
		n = n/10;
		n += 2;
		n = pow(2,n);
		min = 1000000;
	for ( i = 1; i <= 254016; i++ )
	{
		s1 = pow(2.0*pi*i, 1.0/2/i )*i/e;
		s2 = pow(2.0,1.0*n/i);
		if ( s2 > s1 && s2-s1 < min )
		{
			min = s2 - s1;
			k = i;
		}
	}
	cout<<k<<endl;
	}
}

//10000000