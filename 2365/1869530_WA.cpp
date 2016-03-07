#include <iostream.h>
#include <math.h>
#include <iomanip.h>
const double PI = asin(1)*2;
void main()
{
	double data[200][2];
	int n;
	int r;
	int i;
	double l1;
//	double l2;
	double x1;
	double x2;
//	double x3;
	double y1;
	double y2;
//	double y3;
//	double k1;
//	double k2;
//	double k;
	double l = 0.0;
	double rope = 0.0;
	cin>>n>>r;
	for ( i = 0; i < n; i++ )
		cin>>data[i][0]>>data[i][1];
	if ( n == 1 )
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<PI*r*r<<endl;
	else
	{
		l = 0.0;
		for ( i = 0; i < n; i++ )
		{		
			x1 = data[i%n][0];
			y1 = data[i%n][1];

			x2 = data[(i+1)%n][0];
			y2 = data[(i+1)%n][1];

//			x3 = data[(i+2)%n][0];
//			y3 = data[(i+2)%n][1];

			l1 = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
//			l2 = (x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
			l1 = sqrt(l1);
//			l2 = sqrt(l2);
			l += l1;
	//		k1 = (y3-y2)/(x3-x2);
	//		k2 = (y1-y2)/(x1-x2);
	//		k1 = (k1-k2)/(1+k1*k2);
	//		if ( k1 > PI )
	//			k1 = 2*PI - k1;
	//		k = atan(k1);
	//		k = (x1-x2)*(x3-x2)+(y1-y2)*(y3-y2);
	//		k = fabs(k);
	//		k = k / (l1*l2);
	//		k = acos(k);
	//		if ( k > PI/2 )
	//			k = PI - k;
	//		k = r*k;
	//		rope += k;
		}
		rope = PI*(2)*r;
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<rope+l<<endl;
	}
}