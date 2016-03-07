#include <iostream.h>
#include <iomanip.h>
#include <math.h>

void main ()
{
	double h1;
	double V;
	double H;
	double S;
	double alp;
	int e[6];
	int i;
	for ( i = 0; i < 6; i++ )
		cin>>e[i];
	alp = 1.0*( e[3]*e[3] + e[4]*e[4] - e[5]*e[5] ) / (2.0 *  e[3] * e[4] );
	alp = acos(alp);
	S = 0.5 * e[3] * e[4] * sin(alp);
	h1 = S * 2.0 / e[5];
	h1 = h1 * 2.0 / 3;
	H = sqrt ( e[0]*e[0] - h1 *h1 );
	V = 1.0/3 * S * H;
	cout<<setiosflags(ios::fixed)<<setprecision(8)<<V<<endl;
}