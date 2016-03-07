#include <iostream.h>
#include <iomanip.h>
void main () 
{
	float re ( float );
	float x1;
	float x2;
	float x3;
	float x4;
	float y1;
	float y2;
	float y3;
	float y4;
	float x;
	float y;
	while ( cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4 )
	{
		x = x1+x4-x2;
		y = y1+y4-y2;
		cout<<setiosflags(ios::fixed)<<setprecision(3)<<x<<" "<<y<<endl;
	}
}

float re ( float d )
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
	if ( fu == 1 )
		d = d * ( -1.0 );
	return d;
}