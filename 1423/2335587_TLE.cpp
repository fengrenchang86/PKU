#include <iostream>
#include <math.h>
using namespace std;
const double pi = asin(1)*2;
int main ()
{
	int n,i;
	double sum=0.0;
	int tcase;
	cin>>tcase;
	while ( tcase )
	{
		tcase--;
		cin>>n;
		sum = 0.0;
		for ( i =2; i <= n; i++ )
			sum += log10(i);
		i = sum;
		cout<<i+1<<endl;
	}
	return 1;
}