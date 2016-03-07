#include <iostream.h>
#include <math.h>
int prime[50000];
int isprime ( int p )
{
	int i;
	int n = sqrt (p );
	for ( i = 2; i <= n; i++ )
	{
		if ( p % i == 0 )
			return 0;
	}
	return 1;
}
void main ()
{
	int i = 3;
	int j = 0;
	int n;
	bool su = false;
	while(cin>>n && n!=0)
	{
		i = 3;
		j = 0;
	if ( isprime(n-2) == 1 )
	{
		cout<<n<<" = 2 + "<<n-2<<endl;
		continue;
	}
	while ( i <= n/2 )
	{
		
		if ( isprime (i) == 0 )
		{
			i++;
			continue;
		}
		j = isprime (n - i );
		if ( j== 1)
		{
			su = true;
			break;
		}
		i+=2;
	}
	if ( su == true )
		cout<<n<<" = "<<i<<" + "<<n-i<<endl;
	else
		cout<<"Goldbach's conjecture is wrong."<<endl;
	}
}
