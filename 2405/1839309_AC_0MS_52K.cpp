#include <iostream.h>
#include <iomanip.h>
#include <math.h>
const double PI = 3.1415926536;
void main ()
{
	long double d;
	long double D;
	long double v;
	while ( cin>>D>>v && D != 0 && v != 0 )
	{
		D = pow ( D, 3);
		d = D - 6 * v / PI;
		d = powl ( d, 1.0/3 );
		cout<<setiosflags(ios::fixed)<<setprecision(3)<<d<<endl;
	}
}