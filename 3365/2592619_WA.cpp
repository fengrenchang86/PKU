#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	int a,b,c;
	double x,y,r1,r2,h,s=0;
	double begin,end,mid;
	double pi = asin(1)*2;
	while ( cin>>a>>b )
	{
		if ( a > b )
		{
			c = a;
			a = b;
			b = c;
		}
		x = double(b)/2.0;
		y = double(b);
//		if ( y/(2.0*pi) >= double(a) )
		begin = 0;
		end = b;
		while ( end-begin > 0.0000000000001 )
		{
			mid = (begin+end)/2.0;
			if ( a > mid )
				r1 = mid/2;
			else
				r1 = a/2;
			if ( a > y-mid )
				r2 = a/(2.0*pi);
			else
				r2 = (y-mid)/(2.0*pi);
			if ( r1 < r2 )
				begin = mid;
			else
				end = mid;
		}
		if ( mid > a )
		{
			mid = a;
			r1 = double(a)/2.0;
			h = pi*r1*r1*double(a);
			s = double(a)*double(a)*double(b-mid)/4.0/pi;
			if ( s < h )
				s = h;
		}
		else
		{
			s = double(a)*double(a)*double(b-mid)/4.0/pi;
			h = double(b-mid)*double(b-mid)*double(a)/4.0/pi;
			if ( s < h )
				s = h;
		}
		printf("%.3lf\n",s);
	}
	return 0;
}