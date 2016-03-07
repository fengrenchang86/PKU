
#include <iostream>
using namespace std;
int p[2000000];
bool isprime ( int n )
{
	if ( n%2==0 && n!=2)
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
	for ( i = 3; i*i<=n ; i+=2 )
	{
		if ( isprime(n) == true )
		{
			sum += f(n);
			return sum;
		}
		while ( n % i == 0 )
		{
			sum += f(i);
			n /= i;
		}
	}
	if ( n != 1 )
		sum += f(n);
	return sum;
}
int main ()
{
	int n,i,k=0;
	while ( cin>>n && n!=0 )
//	n = 50000000;
//	while ( n < 100000000 )
	{
		i = n+1;
		while ( 1 )
		{
			if ( isprime(i) == true )
			{
				i++;
				continue;
			}
			if ( f(i)==g(i) )
				break;
			i++;
		}
		n = i;
		cout<<i<<endl;
	}
	return 0;
}
