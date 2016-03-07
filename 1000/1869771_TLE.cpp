#include <iostream.h>
#include <math.h>
int main ()
{
	int i;
	double k = 34.234;
	int *t;
	bool *bb;
	k = k * k;
	k = sqrt(k*k*k);
	double a,b;
	while ( 1 )
	{
		a = a*a;
		b = b*b;
		a = sqrt(a);
		b = sqrt(b);
		cout<<a+b<<endl;
		for ( i = 0; i < 200000000; i++ )
		{
			i++;
			i--;
		}
	}
	return 1;
}