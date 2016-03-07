#include <iostream>
#include <math.h>
using namespace std;
double e =  2.718281828;
double h;
int main ()
{
	char ch1,ch2;
	double a,b;
	double c,d;
	double H,D,T;
	while ( cin>>ch1 && ch1!='E')
	{
		H = D = T = -1;
		cin>>a>>ch2>>b;
		if ( ch1 == 'D' )
			D = a;
		else if ( ch1 == 'T' )
			T = a;
		else
			H = a;
		if ( ch2 == 'D' )
			D = b;
		else if ( ch2 == 'T' )
			T = b;
		else
			H = b;
		if ( H == -1 )
		{
			c = 1/273.16 - (1/(D+273.16));
			c *= 5417.7530;
			d = exp(c);
			d *= 6.11;
			h = 0.5555*(d-10);
			H = T + h;
//			printf("%.1lf\n",T+h);
		}
		else if ( T == -1 )
		{
			c = 1/273.16 - (1/(D+273.16));
			c *= 5417.7530;
			d = exp(c);
			d *= 6.11;
			h = 0.5555*(d-10);
	//		printf("%.1lf\n",H-h);
			T = H-h;
		}
		else
		{
			h = H-T;
			d = h/0.5555+10.0;
			d /= 6.11;
			a = 0.0;
			b = 6000.0;
			a = log(d);
			a/=5417.7530 ;
			a = 1/273.16-a;
			a = 1.0/a;
			a -=273.16;
			D = a;
		}
		printf("T %.1lf D %.1lf H %.1lf\n",T,D,H);
	}
	return 0;
}