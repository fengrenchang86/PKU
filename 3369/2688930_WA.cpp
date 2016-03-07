#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	int a,b,c,d;
	for ( a = 1; a*a*a*a<=2000000000;a++)
	{
		for ( b = a; b+a+b+b<=2000&&b*a*b*b<=2000000000; b++ )
		{
			for ( c = b; a+b+c+c<=2000&&a*b*c*c<=2000000000;c++ )
			{
				if ( a*b*c<=1000000)
					continue;
				d = (a+b+c)*1000000/(a*b*c-1000000);
				if ( 1000000*(a+b+c+d)-a*b*c*d !=0 )
					continue;
				if ( d >= c && a+b+c+d < 2000 )
				{
					printf("%.2f %.2f %.2f %.2lf\n",double(a)/100.0,double(b)/100.0,double(c)/100.0,double(d)/100.0);
				}
			}
		}
	}
	return 0;
}
