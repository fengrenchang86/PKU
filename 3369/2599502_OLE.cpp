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
		for ( b = a; b <= 2.12; b+=0.01 )
		{
			for ( c = b; c <= 2.12;c+=0.01 )
			{
				d = (a+b+c)/(a*b*c-1);
				if ( d > c && a+b+c+d <= 20 )
				{
					printf("%.3lf %.3lf %.3lf %.3lf\n",a,b,c,d);
				}
			}
		}
	}
	return 0;
}