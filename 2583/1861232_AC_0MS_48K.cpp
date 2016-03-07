#include <iostream.h>
double a;
double b;
double c;
double f( double x )
{
	return a*x*x+b*x+c;
}
void main ()
{
	int e1;
	int e2;
	int e3;
	while ( cin>>e1>>e2>>e3 )
	{
		a = (e3-e1-2*e2+2*e1)/2.0;
		b = e2-e1-a;
		c = e1;
		cout<<f(3.0)<<" "<<f(4.0)<<" "<<f(5.0)<<endl;
	}
}