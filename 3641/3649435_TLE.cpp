
#include <iostream>
using namespace std;
bool isprime ( int p )
{
	if ( p == 2 )
		return true;
	int i;
	for ( i = 3; i*i <= p; i+=2 )
	{
		if ( p % i == 0 )
			return false;
	}
	return true;
}
int main ()
{
	int a,p,i,j;
	while ( cin>>p>>a )
	{
		if ( a== 0 && p == 0 )
			break;
		j = 1;
		for ( i = 0; i < p-1; i++ )
		{
			j *= a;
			j %= p;
		}
		if ( j == 1 && !isprime(p) )
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}