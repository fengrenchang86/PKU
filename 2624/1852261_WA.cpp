#include <iostream.h>
#include <iomanip.h>
void main () 
{
	double re ( double );
	double x1;
	double x2;
	double x3;
	double x4;
	double y1;
	double y2;
	double y3;
	double y4;
	double k1;
	double k2;
	double x;
	double y;
	while ( cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4 )
	{
		if ( x1 == x2 )
		{
			x = x4;
			k2 = (y4-y3)/(x4-x3);
			y = k2*x - k2*x1 + y1;
		}
		else if ( x3 == x4 )
		{
			x = x1;
			k1 = (y2-y1)/(x2-x1);
			y = k1*x - k1*x4 + y4;
		}
		else
		{
			k1 = (y2-y1)/(x2-x1);
			k2 = (y4-y3)/(x4-x3);
			x = (y4-y1+k2*x1-k1*x4)/(k2-k1);
			y = y1 + k2*x - k2*x1;
		}
		x = re ( x );
		y = re ( y );
		cout<<setiosflags(ios::fixed)<<setprecision(3)<<x<<" "<<y<<endl;
	}
}

double re ( double d )
{
	int temp;
	int fu;
	if ( d < 0 )
	{
		fu = 1;
		d = d*(-1.0);
	}
	else
		fu = 0;
	temp = d*10000;
	if ( temp - temp/10*10 >= 5 )
		temp = temp/10 + 1;
	else
		temp = temp/10;
	d = 1.0*temp/1000;
	if ( fu = 1 )
		d = d * ( -1.0 );
	return d;
}