#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
const double pi = asin(1)*2;
void main ()
{
	double v;
	double low,high;
	double DE,FD,H,AE;
	double temp;
	int AB,AC,AD,BC,BD,CD;
	double A1,A2;
	double s;
	cin>>AB>>AC>>AD>>BC>>BD>>CD;
	A1 = 1.0*(AD*AD+CD*CD-AC*AC)/(2.0*AD*CD);
	A1 = acos(A1);
	AE = 1.0*sin(A1)*AD;
	DE = 1.0*(AD*AD+CD*CD-AC*AC)/(2.0*CD);
	FD = BD - 1.0*(AB*AB+BD*BD-AD*AD)/(2.0*BD);
	A2 = acos((BD*BD+CD*CD-BC*BC)*1.0/(2*BD*CD));
	s = 1.0/2*BD*CD*sin(A2);
	low = 0.0;
	high = 2.0*pi;
	while ( high - low >= 0.00000001 )
	{
		A1 = (high+low)/2;
		temp = cos(A1)*DE - cos( A2-A1 )*FD;
		if ( temp >= -0.00000001 && temp <= 0.00000001 )
			break;
//		temp = fabs(temp);
		if ( temp < 0 )
			high = A1;
		else 
			low = A1;
	}
	A2 = A2 - A1;
	temp = A2*DE;
	H = sqrt(AE*AE-temp*temp);
	v = 1.0/3*s*H;
//	int ans = v*10000;
//	if ( ans % 10 >= 5 )
//		v+=0.0001;
	printf("%.4lf\n",v);
}