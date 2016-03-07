#include <iostream.h>
#include <math.h>
int T[ ] = {1,2,3,4,5,6,7,8,9,10};
int primes[200];
void main ( )
{
	void make_primes ( );
	make_primes();
	int sum;
	int c;
	int end;
	int i;
	int j;
	bool exit = false;
	int count = 0;
	while (1)
	{
	exit = false;
	cin>>sum>>c;
	count = 0;
	if ( sum == 0 && c == 0 )
		break;
	int *temp = new int[c];
	for ( end = 0; primes[end] <= sum; end++ )
		;
	end--;
	for ( i = 0; i < c; i++ )
		temp[i] = i;
	temp[i-1]--;
	while ( 1 )
	{
		i = c - 1;
		temp[i]++;
		while ( temp[i] > end + i - c )
		{
			i--;
			temp[i]++;
			if ( i == -1 )
				exit = true;
		}
		i++;
		while ( i <= c - 1 && i > 0)
		{
			temp[i] = temp[i-1] + 1;
			i++;
		}
		j = 0;
		for ( i = 0; i < c; i++ )
			j += primes[temp[i]];
		if ( j == sum )
			count++;
		if ( exit == true )
			break;
	}
	cout<<count<<endl;
	}
}


void make_primes ( )
{
	int i = 1;
	int j = 1;
	int count = 0;
	bool isprime = true;
	for ( i = 2; i < 1300; i++ )
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
			primes[count++] = i;
	}
}	