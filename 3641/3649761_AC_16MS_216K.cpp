
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
__int64 acPower ( int a, int b, int p )
{
	if ( b == 0 )
		return 1;
	else if ( b == 1 )
		return a%p;
	__int64 k = acPower(a,b/2,p);
	k = (k*k)%p;
	if ( b % 2 == 1 )
		k = k*a;
	k %= p;
	return k;
}
int main ()
{
	int a,p,j;
	while ( scanf("%d%d",&p,&a) != EOF )
	{
		if ( a== 0 && p == 0 )
			break;
		j = 1;
		j = acPower(a,p,p);
		if ( j == a && !isprime(p) )
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}