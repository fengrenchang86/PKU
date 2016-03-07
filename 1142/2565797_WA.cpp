#include <iostream>
using namespace std;
bool isprime ( int n )
{
	if ( n%2==0 )
		return false;
	int i;
	for ( i = 3; i*i <= n; i+=2 )
	{
		if ( n%i==0)
			return false;
	}
	return true;
}
int f ( int n )
{
	int sum = 0;
	while ( n != 0 )
	{
		sum += n%10;
		n/=10;
	}
	return sum;
}
int g( int n )
{
	int i;
	int sum=0;
	while ( n % 2 == 0 )
	{
		sum += 2;
		n /= 2;
	}
	for ( i = 3; n!=0 ; i+=2 )
	{
		if ( isprime(n) == true )
		{
			sum += f(n);
			break;
		}
		while ( n % i == 0 )
		{
			sum += f(i);
			n /= i;
		}
	}
	return sum;
}
int main ()
{
	int n,i;
	while ( cin>>n && n!=0 )
	{
		i = n+1;
		while ( 1 )
		{
			if ( f(i)==g(i) )
				break;
			i++;
		}
		cout<<i<<endl;
	}
	return 0;
}