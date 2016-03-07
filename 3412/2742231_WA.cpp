#include <iostream>
#include <math.h>
using namespace std;
#define pi asin(1)*2
int main ()
{
	double N[200];
	int k,i;
	double a;
	cin>>k;
	for ( i = 0; i < k; i++ )
		cin>>N[i];
	cin>>a;
	for ( i = 0; i < k-1; i++ )
	{
		a = a*N[i]/N[i+1 ];
		if ( a >= pi/2  )
			break;
	}
	if ( i < k-1 )
		cout<<"NO"<<endl;
	else
		printf("%.2lf\n",a);
	return 0;
}