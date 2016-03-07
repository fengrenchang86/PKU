#include <iostream.h>
int t[10000];
int f ( int n )
{
	int k = n;
	int c = 1;
	while ( k != 1 )
	{
		if ( k % 2 == 0 )
		{
			k = k / 2;
			if ( k < 1000 )
			t[k] = c;
		}
		else
		{
			k = 3 * k + 1;
			if ( k < 1000 )
			t[k] = c;
		}
		c++;
	}
	return c;
}

void main () 
{
	int a;
	int b;
	int i;
	int k;
	int max;
	while ( cin>>a>>b )
	{
		max = 0;
		for ( i = 0 ; i < b+1; i++ )
			t[i] = 0;
		for ( i = b; i >= a; i-- )
		{
			if ( t[i] == 0 )
			{
				k = f ( i );
				if ( k > max )
					max = k;
			}
		}
		cout<<max<<endl;
	}
}