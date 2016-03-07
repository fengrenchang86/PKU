
#include <iostream>
#include <math.h>
using namespace std;
int prime[32768];
void make ()
{
	prime[2] = 1;
	prime[3] = 1;
	int i,j,k;
	for ( i = 5; i <= 32768; i+=2 )
	{
		k = sqrt(i);
		for ( j = 3; j <= k; j+=2 )
			if ( i%j == 0 )
				break;
		if ( i%j != 0 )
			prime[i] = 1;
	}
}
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
	memset(prime,0,sizeof(prime));
/*	for ( i = 3; i <= 32768; i++ )
	{
		if ( isprime(p,n);
	}
	while ( cin>>n && n != 0 )
	{
		sum = 0;
		sum += isprime(2,n);
		for ( i = 3; i <= n/2; i+=2 )
			sum+=isprime(i,n);
		cout<<sum<<endl;
	}*/
	make();
	while ( scanf("%d",&n) && n != 0 )
	{
		sum = 0;
		if ( prime[n-2] == 1 )
			sum++;
		for ( i = 3; i <= n/2; i++ )
		{
			if ( prime[i] == 1 && prime[n-i] == 1 )
				sum++;
		}
		printf("%d\n",sum);
	}
}

