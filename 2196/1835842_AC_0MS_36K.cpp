#include <iostream.h>
void main ()
{
	int base ( int , int );
	int i = 2991;
	int t1;
	int t2;
	while ( i < 10000 )
	{
		t1 = base ( i, 10 );
		t2 = base ( i, 12 );
		if ( t1 == t2 )
		{
			t1 = base ( i ,16 );
			if ( t1 == t2 )
				cout<<i<<endl;
		}
		i++;

	}
}


int base ( int k, int base )
{
	int sum = 0;
	int i;
	i = k / (base*base*base);
	sum += i;
	k = k - i * base * base * base;
	i = k / ( base*base );
	sum += i;
	k = k - i * base * base;
	i = k / base;
	sum += i;
	k = k - i * base;
	i = k;
	sum += i;
	return sum;
}