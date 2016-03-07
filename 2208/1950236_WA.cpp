#include <iostream>
//#include <iomanip>
#include <math.h>
using namespace std;
const double pi = asin(1)*2;
///*
void main ()
{
	double v;
	double low,high;
	double DE,FD,H,AE;
	double temp;
	int AB,AC,AD,BC,BD,CD;
	double A1,A2,a;
	double s;
	cin>>AB>>AC>>AD>>BC>>BD>>CD;
	A1 = 1.0*(AD*AD+CD*CD-AC*AC)/(2.0*AD*CD);
	a = A1;
	A1 = acos(A1);
	AE = 1.0*sin(A1)*AD;
	DE = 1.0*(AD*AD+CD*CD-AC*AC)/(2.0*CD);
	FD = BD - 1.0*(AB*AB+BD*BD-AD*AD)/(2.0*BD);
	A2 = acos(1.0*(BD*BD+CD*CD-BC*BC)*1.0/(2.0*BD*CD));
	s = 1.0/2*BD*CD*sin(A2);
	low = 0.0;
	high = 1.0*pi;
	while ( high - low >= 0.00000001 )
	{
		A1 = (high+low)/2;
		temp = cos(A1)*DE - cos( A2-A1 )*FD;
//		temp = fabs(temp);
		if ( temp < 0 )
			high = A1;
		else 
			low = A1;
	}
	A2 = A2 - A1;
	temp = tan(A2)*DE;
	H = sqrt(AE*AE-temp*temp);
	v = 1.0/3*s*H;
//	int ans = v*10000;
//	if ( ans % 10 >= 5 )
//		v+=0.0001;
	printf("%.4lf\n",v);
}
//*/
/*
void main ()
{
	int AB,AC,AD,BC,BD,CD;
	double t1,t2,t3;
	double x,y,z;
	double a;
	cin>>AB>>AC>>AD>>BC>>BD>>CD;
	a = 1.0*(BC*BC+BD*BD-CD*CD)/(2*BC*BD);
	x = 0.5*(BC*BC+AB*AB-AC*AC)/BC;
	double low,high;
	low = 0.0;
	high = 1.0*AB;
	while ( high-low > 0.0000000001 )
	{
		z = (high+low)/2.0;
		t1 = AD*AD-z*z-(x-BD*a)*(x-BD*a);
		t1 = sqrt(t1);
		t2 = sqrt(AC*AC-z*z-(x-BC)*(x-BC));
		t3 = BD* sin(acos(a));
		if ( t1+t3-t2 > 0 )
			low = z;
		else
			high = z;
	}
	double s = 0.5*BD*BC*sin(acos(a));
	double v = 1.0/3*s*z;
	printf("%0.4lf\n",v);
}
*/