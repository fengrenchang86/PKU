#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main ()
{
	unsigned int m,n;
	int i;
	unsigned int h;
	int c = 0;
	for ( i = 6; c < 10; i++ )
	{
		h = sqrt((i*i+i)/2);
		if ( 2*h * h == i*i+i )
		{
			cout<<setw(10)<<h<<setw(10)<<i<<endl;
			c++;
		}
	}
	return 1;
}
