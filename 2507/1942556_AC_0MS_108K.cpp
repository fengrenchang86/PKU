
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
void main ()
{
	double x;
	double y;
	double c;
	double k;
	double low, high, mid;
	double d;
	while ( scanf("%lf %lf %lf",&x,&y,&c)!=EOF )
	{
		low = 0.0;
		high = 1.0*x;
		while ( high-low > 0.0001 )
		{
			mid = (high+low)/2.0;
			if ( 1.0/sqrt(x*x-mid*mid)+1.0/sqrt(y*y-mid*mid) < 1.0/c )
				low = mid;
			else
				high = mid;
		}
		printf("%.3f\n",low);
	}
}