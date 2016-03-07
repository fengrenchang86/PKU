#include <iostream>
#include <math.h>
using namespace std;
const double pi = asin(1)*2;
int main ()
{
	int n,i;
	double sum=0.0;
	double e = 2.718281821459045;
	int tcase;
	cin>>tcase;
	while ( tcase )
	{
		tcase--;
		cin>>n;
	//	if ( n < 10000 )
		{
			sum = n*log10(n/e)+log10(sqrt(2.0*pi*n));
			i = sum;
			cout<<i+1<<endl;
		}
	}
	return 1;
}