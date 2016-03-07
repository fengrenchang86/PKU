#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	double x1,y1,x2,y2,x3,y3,x,y;
	double k1,k2,k;
	double r,s;
//	double pi = 3.141592653589793;
	double pi = asin(1)*2;
	while ( scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF )
	{
		x1*=1.0;x2*=1.0;x3*=1.0;
		y1*=1.0;y2*=1.0;y3*=1.0;
		if ( y1==y2 )
		{
			k2 = 1.0*(x2-x3)/(y3-y2);
			x = 1.0*(x1+x2)/2;
			y = k2*(x-(x2+x3)/2)+(y2+y3)/2;
		}
		else if ( y2 == y3 )
		{
			k1 = 1.0*(x1-x2)/(y2-y1);
			x = 1.0*(x2+x3)/2;
			y = k1*(x-(x1+x2)/2)+(y1+y2)/2;
		}
		else
		{
			k1 = 1.0*(x1-x2)/(y2-y1);
			k2 = 1.0*(x2-x3)/(y3-y2);
			x = k1*(x1+x2)/2-k2*(x2+x3)/2+(y3-y1)/2;
			y = k1*(x-(x1+x2)/2)+(y1+y2)/2;
		}
		
		r = (x-x2)*(x-x2)+(y-y2)*(y-y2);
		r = sqrt(r);
		s = 2*pi*r;
		printf("%.2f\n",s);
	}
	return 1;
}