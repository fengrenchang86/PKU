#include <iostream.h>
#include <iomanip.h>
double re( int i )
{
	if ( i == 0)
		return 1;
	double sum = 1.0;
	int k = i;
	while ( k > 1 )
	{
		sum = sum / k;
		k--;
	}
	return sum;
}
void main ()
{
	int i = 0;
	double suma = 0.0;
	cout<<"n e"<<endl;
	cout<<"- -----------"<<endl;
	while ( i < 10 )
	{
		cout<<i;
		suma += re ( i );
		cout<<" "<<setprecision(10)<<suma<<endl;
		i++;
	}

}

