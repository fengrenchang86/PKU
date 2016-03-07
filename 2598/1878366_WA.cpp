#include <iostream>
#include <math.h>
const double pi = 3.14;
using namespace std;
int main ()
{
	float l;
	double p;
	int k;
	while ( cin>>l )
	{
		if ( l <= 0.5 )
			p = 1000.0*2.0*l/pi;
		else
		{
			p = 2000*l*(1.0/l*acos(1.0/l)-sqrt(1-1.0/l/l)+1)/pi;
			
		}
		k = p*10;
		if ( k%10 >= 5 )
			k = k/10+1;
		else
			k /= 10;
		cout<<k<<endl;
	}
	return 1;
}