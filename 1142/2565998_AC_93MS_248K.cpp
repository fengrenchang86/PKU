
#include <iostream>
using namespace std;
bool p[70000];
void make ()
{
	int i,j;
	for ( i = 0; i <= 65800; i++ )
		p[i] = false;
	p[2] = true;
	p[3] = true;
	for ( i = 5; i <= 65580; i+=2 )
	{
		for ( j = 3; j*j <= i; j+=2 )
		{
			if ( i%j==0)
				break;
		}
		if ( i%j != 0 )
			p[i] = true;
	}
}
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
	int num = n;
	int i;
	int sum=0;
	while ( n % 2 == 0 )
	{
		sum += 2;
		n /= 2;
	}
	for ( i = 3; i*i<=num ; i+=2 )
	{
		if ( p[i] == false )
			continue;
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
	make();
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
