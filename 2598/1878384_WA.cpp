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
		if ( l <= 1 )
			p = 1000.0*2.0*l/pi;
		else
		{
			p = 2000*l*(1.0/l*acos(1.0/l)-sqrt(1-1.0/l/l)+1)/pi;
			p++;
		}
		k = p;
		cout<<k<<endl;
	}
	return 1;
}