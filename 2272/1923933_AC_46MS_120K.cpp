#include <iostream>
#include <math.h>
using namespace std;
int r(double x, double y )
{
	double r = sqrt(x*x+y*y);
	if ( r <= 3 )
		return 100;
	else if ( r <= 6 )
		return 80;
	else if ( r <= 9 )
		return 60;
	else if ( r <= 12 )
		return 40;
	else if ( r <= 15 )
		return 20;
	else 
		return 0;
}
int main ()
{
	double x[6],y[6];
	int i;
	int a[2];
	while ( 1 )
	{
		for ( i = 0; i < 6; i++ )
			cin>>x[i]>>y[i];
		if ( x[0] == -100 )
			break;
		a[0] = a[1] = 0;
		for ( i = 0; i < 3; i++ )
			a[0] += r(x[i],y[i]);
		for ( i = 3; i < 6; i++ )
			a[1] += r(x[i],y[i]);
		printf("SCORE: %d to %d, ",a[0],a[1]);
		if ( a[0] > a[1] )
			printf("PLAYER 1 WINS.\n");
		else if ( a[1] > a[0] )
			printf("PLAYER 2 WINS.\n");
		else
			printf("TIE.\n");

	}
	return 1;
}
