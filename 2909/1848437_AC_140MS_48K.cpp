#include < iostream.h>
#include < math.h>
int isprime ( int n )
{
	int m;
	m = sqrt(n)+1;
	int i;
	for ( i = 2; i <= m; i++ )
	{
		if ( n % i == 0 )
			return 0;
	}
	return 1;
}

void main ()

{
	int n;
	int p;
	int i;
	while ( cin>>n && n != 0 )
	{
		p = 0;
		for ( i = 2; i <= (n+1)/2; i++ )
		{
			if ( isprime(i) == 1 )
			{
				if ( isprime( n - i ) == 1 )
					p++;
			}
		}
		cout<<p<<endl;
	}
}