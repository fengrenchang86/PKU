#include <iostream>
#include <math.h>
using namespace std;
#define pi 3.1415926
int main ()
{
	double N[200];
	int k,i;
	double a;
	cin>>k;
	for ( i = 0; i < k; i++ )
	{
		cin>>N[i];
		N[i] = double(N[i]);
	}
	cin>>a;
	if ( fabs(a-pi/2) <= 0.000000000001 )
	{
		cout<<"NO"<<endl;
		return 0;
	}
	for ( i = 0; i < k-1; i++ )
	{
		a = double(a)*N[i]/N[i+1 ];
		if ( a >= pi/2  )
			break;
	}
	if ( i < k-1 )
		cout<<"NO"<<endl;
	else
		printf("%.4lf\n",a);
	return 0;
}