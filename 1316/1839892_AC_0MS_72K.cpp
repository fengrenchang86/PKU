#include <iostream.h>
void main ()
{
	int result ( int );
	int a[11000];
	int i;
	int n;
	int d;
	for ( i = 0; i < 11000; i++ )
		a[i] = 0;
	i = 1;
	while ( i < 10000 )
	{
		n = result ( i );
		a[n] = 1;
		i++;
	}
	d = 0;
	for ( i = 1; i < 10000; i++ )
	{
		if (a[i] != 1 )
			cout<<i<<endl;
	}
	
}

int result ( int k )
{
	int sum = k;
	int i = k;
	while ( i != 0 )
	{
		sum += ( i - i/10*10 );
		i /= 10;
	}
	return sum;
}