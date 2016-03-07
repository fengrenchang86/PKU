#include <iostream>
using namespace std;
double a[5];
int main ()
{
	double a,b,c,d;
//	int count = 0;
//	char ch[120];
	for ( a = 0.01; a <= 2.12; a+=0.01 )
	{
		for ( b = a; b+a<=20&&b*a<=20; b+=0.01 )
		{
			for ( c = b; a+b+c<=20&&a*b*c<=20;c+=0.01 )
			{
				d = (a+b+c)/(a*b*c-1);
				if ( a+b+c+d-a*b*c*d >0.000001 || a*b*c*d-a-b-c-d > 0.000001 )
					continue;
				if ( d >= c && a+b+c+d <= 20 )
				{
					printf("%.2lf %.2lf %.2lf %.2lf\n",a,b,c,d);
				}
			}
		}
	}
	return 0;
}