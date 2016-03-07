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
	double x;
	double y;
	while ( cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4 )
	{
		if ( x2 == x3 && y2 == y3 )
		{
			x = x1+x4-x2;
			y = y1+y4-y2;
		}
		else if ( x1 == x3 && y1 == y3 )
		{
			x = x2+x4-x3;
			y = y2+y4-y3;
		}
		else
		{
			x = x1+x3-x2;
			y = y1+y3-y2;
		}
		cout<<setiosflags(ios::fixed)<<setprecision(3)<<x<<" "<<y<<endl;
	}
}

