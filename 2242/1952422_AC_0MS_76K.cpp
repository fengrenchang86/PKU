#include <iostream>
#include <math.h>
using namespace std;
const double pi = 3.141592653589793;
//列方程解出圆心坐标，过了sample的数据，但不AC
/*
int main ()
{
	double x1,y1,x2,y2,x3,y3,x,y;
	double k1,k2,k;
	double r,s;
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
			y = k2*(x-(x2+x3)/2)+(y2+y3)/2;
		}
		
		r = sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
		s = 2.0*3.141592653589793*r;
		printf("%.2f\n",s);
	}
	return 1;
}*/
void main ()
{
	double x1,y1,x2,y2,x3,y3;
	double a,b,c;
	double a1,a2;
	double r;
	while ( scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF )
	{
		a = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
		b = (x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
		c = (x1-x3)*(x1-x3)+(y3-y1)*(y3-y1);
		a1 = (a+b-c)/2.0/sqrt(a*b);
		a1 = acos(a1);
		a1 *= 2.0;
		if ( a1 > pi )
			a1 = 2*pi - a1;
		else if ( fabs(a1 - pi) < 0.0000000000001 )
		{
			a1 = ( b+c-a)/2.0/sqrt(b*c);
			a1 = acos(a1);
			a1 *= 2.0;
			if ( a1 > pi )
				a1 = 2*pi - a1;
			c = a;
		}
		a2 = (pi-a1)/2;
		r = sqrt(c)/sin(a1)*sin(a2);
//		r = sin(a2)/sin(a1)*sqrt(c);
		r = 2*pi*r;
		printf("%.2lf\n",r);
	}
	return;
}
