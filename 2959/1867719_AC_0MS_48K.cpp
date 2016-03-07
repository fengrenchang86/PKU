#include <iostream.h>
#include <math.h>
const double pi = asin(1)*2;
void main ()
{
	double D;
	double d;
	double s;
	int n;
	int i;
	double alp;
	int num;
	cin>>n;
	for ( i = 0; i < n; i++ )
	{
		cin>>D>>d>>s;
		alp = 1 - 2.0*(d+s)*(d+s)/(1.0*(D-d)*(D-d));
		alp = acos(alp);
		num = 2.0*pi/alp;
		cout<<num<<endl;
	}
}