#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	double a,b,c;
	double x,y,r1,r2,h,s=0;
	double begin,end,mid;
	double pi = asin(1)*2;
	while ( cin>>a>>b )
	{
		if ( a == 0 && b== 0 )
			break;
		if ( a > b )
		{
			c = a;
			a = b;
			b = c;
		}
		x = double(a);
		y = double(b);
		begin = 0.0;
		end = y;
		while ( end-begin > 0.00000000001 )
		{
			mid = (begin+end)/2.0;
			if ( x > mid )
				r1 = mid/2;
			else
				r1 = x/2;
			if ( a > y-mid )
			{
				r2 = a/(2.0*pi);
				h = y-mid;
			}
			else
			{
				r2 = (y-mid)/(2.0*pi);
				h = x;
			}
			if ( r1 < r2 )
				begin = mid;
			else
				end = mid;
		}
		if ( mid >= x )
		{
			mid = x;
			r1 = double(x)/2.0;
			h = pi*r1*r1*double(x);
//			s = double(a)*double(a)*double(y-mid)/4.0/pi;
//			if ( s < h )
			s = h;
		}
		else
		{
			s = h*pi*r1*r1;
		}
		h = x*x/4/pi*(y-x/pi);
		if ( h > s )
			s = h;
		printf("%.3lf\n",s);
	}
	return 0;
}