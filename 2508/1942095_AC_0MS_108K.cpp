#include <iostream>
#include <math.h>
const double pi = asin(1)*2;
using namespace std;
int main ()
{
	double r,h,d1,d2,a1,a2,A;
	double cita,afa;
	double ans;
	double R;
	while ( scanf("%lf %lf %lf %lf %lf %lf",&r,&h,&d1,&a1,&d2,&a2) != EOF )
	{
		A = a1-a2;
		if ( A < 0 )
			A *= -1.0;
		if ( A > 180 )
			A = 360 - A;
		A = A*1.0*pi/180.0;
		R = 1.0*sqrt(h*h+r*r);
			cita = r*A/R;
		afa = 2.0*pi*r/R;
		if ( cita > afa )
			cita = afa;
		ans = d1*d1+d2*d2-2.0*d1*d2*cos(cita);
		ans = sqrt(ans);
		printf("%.2f\n",ans);
	}
	return 1;
}