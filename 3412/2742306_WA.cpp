#include <iostream>
#include <math.h>
using namespace std;
#define pi 3.1415926
int main ()
{
	double N[200];
	int k,i;
	double a;
	while ( cin>>k )
	{
	for ( i = 0; i < k; i++ )
	{
		cin>>N[i];
		N[i] = double(N[i]);
	}
	cin>>a;	
	if ( fabs(a-pi/2) <= 0.000000000001 )
	{
		cout<<"NO"<<endl;
		continue;
	}
	if ( k == 1 )
	{
		printf("%.3lf\n",a);
		continue;
	}
	a = sin(a);
	for ( i = 0; i < k-1; i++ )
	{
		a = double(a)*N[i]/N[i+1];
		if ( a > 1.0 )
			break;
		if ( asin(a) >= pi/2.0  )
			break;
	}
	if ( i < k-1 )
		cout<<"NO"<<endl;
	else
		printf("%.3lf\n",a);
	}
	return 0;
}