#include <iostream>
using namespace std;

int gcd ( int m, int n )
{
	int k = m%n;
	while ( k != 0 )
	{
		m = n;
		n = k;
		k = m%n;
	}
	return n;
}
int main ()
{
	int a,b;
	int x,y;
	cin>>a>>b;
	x = 32767*a/b;
	y = x+1;
	if ( 1.0*a/b-1.0*x/32767 > 1.0*a/b-1.0*y/32767 )
		x = y;
	y = gcd(x,32767);
	cout<<x/y<<" "<<32767/y<<endl;
	return 0;
}