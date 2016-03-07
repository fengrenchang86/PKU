#include <iostream.h>
#include <math.h>
int prime[1000];
void make ( )
{
	int c = 3;
	int i;
	int j;
	prime[0] = 1;
	prime[1] = 2;
	prime[2] = 3;
	for ( i = 5; c < 1000; i++ )
	{
		for ( j = 2; j < sqrt(i); j++ )
		{
			if ( i%j == 0 )
				break;
		}
		if ( i%j != 0 )
			prime[c++] = i;
	}
}

void main ()
{
	make();
	int i;
	int n;
	int c;
	int a;
	int b;

	while (cin>>n>>c )
	{
	cout<<n<<" "<<c<<": ";
	for ( i = 0; prime[i] < n; i++ );
	if ( i%2 == 0 )
	{
		b = i/2-1-(c-1);
		if ( b < 0 )
			b = 0;
		a = i/2 + c-1;
		if ( a > i-1 )
			a = i-1;
	}
	else
	{
		b = i/2 - (c-1);
		if ( b < 0 )
			b = 0;
		a = i/2+c-1;
		if ( a > i-1 )
			a = i-1;
	}
	for ( i = b; i <= a; i++ )
		cout<<prime[i]<<" ";
	cout<<endl;
	cout<<endl;
	}
}