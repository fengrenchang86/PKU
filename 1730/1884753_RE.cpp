#include <iostream>
#include <math.h>
using namespace std;

int make ( int t[] )
{
	int i;
	int c = 2;
	t[0] = 2;
	t[1] = 3;
	int j;
	for ( i = 3; c < 8000; i+=2 )
	{
		for ( j = 3; j <= sqrt(i); j++ )
			if ( i%j==0 )
				break;
		if ( i % j != 0 )
			t[c++] = i;
	}
	return c;
}
int isprime ( int p, int begin )
{
	int i;
	for ( i = begin; i <= sqrt(p); i++ )
		if ( p%i == 0 )
			return 0;
	return 1;
}

int main ()
{
	int c;
	int prime[10000];
	c = make ( prime );
	int i;
	int k;
	int min;
	int n;
	int h;
	int temp;
	while ( scanf("%d",&n) && n!=0 )
	{
		temp = isprime(n,2);
		if ( temp == 0 )
		{
			cout<<1<<endl;
			continue;
		}
		min = n;
		k = n;
		i = 0;

		while ( 1 )
		{
			h = 0;
			while ( k%prime[i] == 0 )
			{
				k/= prime[i];
				h++;
			}
			if ( h < min && h != 0 )
				min = h;
			if ( k == 1 )
				break;
			i++;
			temp = isprime(k,prime[i-1]);
			if ( temp == 1 && k > 8000)
				break;
		}
		cout<<min<<endl;
	}
	return 1;
}