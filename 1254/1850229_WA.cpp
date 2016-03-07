#include <iostream.h>
#include <iomanip.h>
#include <math.h>
const double PI = 3.1415926535898;
void main () 
{
	int i;
	int n;
	int x1;
	int x2;
	int y1;
	int y2;
	int a1;
	int a2;
	double k1;
	double k2;
	double x;
	double y;
	int temp;
	cin>>n;
	for ( i = 0; i < n; i++ )
	{
		cin>>x1>>y1>>a1;
		cin>>x2>>y2>>a2;
		if ( a1%180 == 0 )
		{
			x = x1;
			k2 = 1.0*tan(a2*PI/180);
			k2 = 1/k2;
			y = k2*x-k2*x2+y2;
			temp = x*100000;
			if ( temp - temp/10*10 >= 5 )
				temp = 1.0*temp/10 + 1;
			else
				temp = 1.0*temp/10;
			x = 1.0*temp/10000;
			temp = y*100000;
			if ( temp - temp/10*10 >= 5 )
				temp = 1.0*temp/10+1;
			else
				temp = 1.0*temp/10;
			y = 1.0*temp/10000;
			cout<<setiosflags(ios::fixed)<<setprecision(4)<<x<<" "<<y<<endl;
			continue;
		}
		if ( a2%180 == 0 )
		{
			x = x2;
			k1 = 1.0*tan(a1*PI/180);
			k1 = 1/k1;
			y = k1*x1-k1*x+y1;
			temp = x*100000;
			if ( temp - temp/10*10 >= 5 )
				temp = 1.0*temp/10 + 1;
			else
				temp = 1.0*temp/10;
			x = 1.0*temp/10000;
			temp = y*100000;
			if ( temp - temp/10*10 >= 5 )
				temp = 1.0*temp/10+1;
			else
				temp = 1.0*temp/10;
			y = 1.0*temp/10000;
			cout<<setiosflags(ios::fixed)<<setprecision(4)<<x<<" "<<y<<endl;
			continue;
		}
		k1 = 1.0*tan(a1*PI/180);
		k1 = 1/k1;
		k2 = 1.0*tan(a2*PI/180);
		k2 = 1/k2;
		x = (y2-y1+k1*x1-k2*x2)/(k1-k2);
		y = y2+k2*x-k2*x2;
		temp = x*100000;
		if ( temp - temp/10*10 >= 5 )
				temp = 1.0*temp/10 + 1;
			else
				temp = 1.0*temp/10;
			x = 1.0*temp/10000;
			temp = y*100000;
			if ( temp - temp/10*10 >= 5 )
				temp = 1.0*temp/10+1;
			else
				temp = 1.0*temp/10;
			y = 1.0*temp/10000;
		cout<<setiosflags(ios::fixed)<<setprecision(4)<<x<<" "<<y<<endl;
	}
}