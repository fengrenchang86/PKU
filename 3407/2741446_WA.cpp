
#include <iostream>
#include <math.h>
using namespace std;
const double pi = 3.1415926;
struct ac
{
	int degreej,minutej,degreew,minutew;
	char ns,we;
	double x,y,z,r;
}t[2];
double trans ( int a, int b )
{
	double c = double(a)+double(b)/60.0;
	c = double(c*pi)/double(180.0);
	return c;
}
int main ()
{
	double R = 6370.0;
	cin>>t[0].degreew>>t[0].minutew>>t[0].ns>>t[0].degreej>>t[0].minutej>>t[0].we;
	cin>>t[1].degreew>>t[1].minutew>>t[1].ns>>t[1].degreej>>t[1].minutej>>t[1].we;
	double w;
	int i;
	for ( i = 0; i <= 1; i++ )
	{
		w = trans(t[i].degreew,t[i].minutew);
		t[i].r = R*cos(pi*double(t[i].degreew+double(t[i].minutew)/60.0)/180.0);
		t[i].z = R*sin(w);
		if ( t[i].ns == 'S'  )
			t[i].z *= -1;
		w = trans(t[i].degreej,t[i].minutej);
		t[i].x = sin(pi*double(t[i].degreej+double(t[i].minutej)/60.0)/180.0);
		t[i].x *= t[i].r;
		if ( t[i].we == 'E' && t[i].degreej < 180 )
			t[i].x *= -1;
		if ( t[i].degreej < 90 )
			t[i].y = -1*t[i].r*cos(w);
		else
			t[i].y = t[i].r*cos(w);
	}
	w = (t[0].x-t[1].x)*(t[0].x-t[1].x) + (t[0].y-t[1].y)*(t[0].y-t[1].y) + (t[0].z-t[1].z)*(t[0].z-t[1].z);
	w = 1.0-double(w)*0.5/double(R*R);
	w = acos(w);
	w *= R;
	if ( w > pi*R )
		w = 2.0*pi*R-w;
	printf("%.4lf\n",w);
	return 0;
}
