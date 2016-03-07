#include <iostream.h>
#include <math.h>

int prime[32768];
int isprime ( int p, int n )
{
	int i;
	int j = sqrt(p);
	if ( p%2==0)
		return 0;
	for ( i = 3; i <= j; i+=2 )
	{
		if ( p%i==0 )
			return 0;
	}
	p = n-p;
	j = sqrt(p);
	if ( p%2 ==0 )
		return 0;
	for ( i = 3; i <= j; i+=2 )
	{
		if (p%i==0 )
			return 0;
	}
	return 1;
}

void main ()
{
	int n;
	int sum;
	int i;
	while ( cin>>n && n != 0 )
	{
		sum = 0;
		sum += isprime(2,n);
		for ( i = 3; i <= n/2; i+=1 )
			sum+=isprime(i,n);
		cout<<sum<<endl;
	}
}
