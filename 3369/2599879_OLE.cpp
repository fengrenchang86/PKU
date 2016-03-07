#include <iostream>
#include <math.h>
using namespace std;
double a[5];
int main ()
{
	double a,b,c,d;
	int count = 0;
	int h;
	char ch[120];
	for ( a = 0.01; a*a*a*a<=20; a+=0.01 )
	{
		for ( b = a; b+a+b+b<=20&&b*a*b*b<=20; b+=0.01 )
		{
			for ( c = b; a+b+c+c<=20&&a*b*c*c<=20;c+=0.01 )
			{
				d = (a+b+c)/(a*b*c-1);
				h = d*100;
				d = h/100;
//				d = double(int(d*100)/100);
				if ( a+b+c+d-a*b*c*d > 0.001 || a+b+c+d-a*b*c*d < -0.001 )
					continue;
				if ( d >= c && a+b+c+d <= 20 )
				{
					printf("%.2lf %.2lf %.2lf %.2lf\n",a,b,c,d);
			//		count++;
				}
			}
		}
	}
//	cout<<count<<endl;
	return 0;
}