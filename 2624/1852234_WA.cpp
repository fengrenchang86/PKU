#include <iostream.h>
#include <iomanip.h>
void main () 
{
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
		cout<<setiosflags(ios::fixed)<<setprecision(3)<<x<<" "<<y<<endl;
	}
}