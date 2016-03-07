#include <iostream.h>
int a;
int b;
int f ( int n )
{
	int k = n;
	int c = 1;
	while ( k != 1 )
	{
		if ( k % 2 == 0 )
			k = k / 2;
		else
			k = 3 * k + 1;
		c++;
	}
	return c;
}

void main () 
{
	int i;
	int k;
	int max;
	while ( cin>>a>>b )
	{
		cout<<a<<" "<<b;
		if ( a > b )
		{
			k = a;
			a = b;
			b = k;
		}
		max = 0;
		for ( i = b; i >= a; i-- )
		{
			k = f ( i );
			if ( k > max )
				max = k;
		}
		cout<<" "<<max<<endl;

	}
}