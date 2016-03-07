#include <iostream.h>
void main ()
{
	int p;
	int c = 1;
	int temp = 0;
	int m = 1;
	while (cin>>p )
	{
		if ( p == 0 )
			break;
		m =1;
		c = 1;
		while ( 1 )
	{
		temp = m / p;
		m = m % p;
		if ( m == 0 )
			break;
		c++;
		m = m * 10 + 1;		
	}
	cout<<c<<endl;
	}
}