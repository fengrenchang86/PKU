

#include <iostream.h>
#include <iomanip.h>
#include <math.h>
const double PI=3.14159265358;
void main ()
{

	double x1, x2, y1, y2, r1, r2;
	double r;
	double i;
//	double j;
	double a1;
	double a2;
	double ans;
	double s1;
	double s2;
	double s1t;
	double s2t;
	int a;
//	double sin1;
//	double sin2;
//	double cos1;
//	double cos2;
//	double s;
	cin>>x1>>y1>>r1>>x2>>y2>>r2;
	r = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	if ( r >r1+r2 )
		ans = 0;
	else if ( fabs(r1-r2) > r )
	{
		r= r1 > r2 ? r2:r1;
		ans = PI * r * r;
	}
	else
	{
		i = r1 > r2 ? r1:r2;
		if ( r > i )
		{
			i = (r1*r1 - r2*r2)/2/r + r/2;
			a1 = acos(fabs(i/r1));
			a2 = acos ( (r-i)/r2);			
			s1 = a1 * r1 * r1;
			s1t = 0.5 * r1 * r1 * sin(2*a1);
			s2 = a2 * r2 * r2;
			s2t = 0.5 * r2 * r2 * sin(2*a2);			
			ans = s1 - s1t + s2 - s2t;
		}
		else
		{
			if ( r1 < r2 )
			{
				i = r1;
				r1 = r2;
				r2 = i;
			}
			i = (r1*r1 - r2*r2 - r*r)/(2*r);
			a1 = acos((r+i)/r1);
			a2 = acos ( i/r2);			
			s1 = a1 * r1 * r1;
			s1t = 0.5 * r1 * r1 * sin(2*a1);
			s2 = a2 * r2 * r2;
			s2t = 0.5 * r2 * r2 * sin(2*a2);			
			ans = s1 - s1t + PI * r2*r2-(s2 - s2t);
		}

	}
	a = ans * 10000;
	if ( a - a/10*10 >= 5 )
		a = a / 10 + 1;
	else
		a = a / 10;
	cout<<a/1000<<'.';
	a = a - a/1000*1000;
	cout<<setw(3)<<setfill('0')<<a<<endl;
	
}

