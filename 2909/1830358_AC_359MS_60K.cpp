#include <iostream.h>
#include <math.h>
int prime[3520];
void main ()
{
	int n;
	void make_primes ();
	make_primes ( );
	int x = 0;
	int y = 1;
	int pnum = 0;
	int count = 0;
	while ( 1 )
	{
		cin>>n;
		if ( n == 0 )
			break;
		x = 0;
		y = 0;
		pnum = 0;
		count = 0;
		while ( prime[x] + prime[y] <= n )
		{
			if ( prime[x] + prime[y] == n )
				pnum++;
			y++;
			if ( prime[x] + prime[y] > n )
			{
				x++;
				y = ++count;
			}
		}
		cout<<pnum<<endl;
	}
	
	
}

void make_primes ( )
{
	int i = 1;
	int j = 1;
	int count = 0;
	bool isprime = true;
	for ( i = 2; i < 32768; i++ )
	{
		isprime = true;
		for ( j = 2; j <= sqrt(i); j++ )
		{
			if ( i % j == 0 )
			{
				isprime = false;
				break;
			}
		}
		if ( isprime == true )
			prime[count++] = i;
	}
}	