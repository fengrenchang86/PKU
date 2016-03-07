#include <iostream>
using namespace std;
int m;
int sum;
int power ( int a, int b )
{
	if ( a == 0 )
		return 0;
	else if ( b == 0 )
		return 1;
	__int64 x = __int64(power(a,b/2));
	x *= x;
	x %= m;
	if ( b % 2 == 1 )
	{
		x *= a;
		x %= m;
	}
	return int(x);
}
int main ()
{
	int tcase,n,i,a,b;
	cin>>tcase;
	while ( tcase-- )
	{
		sum = 0;
		cin>>m>>n;
		for ( i = 0; i < n; i++ )
		{
			cin>>a>>b;
			sum += power(a,b);
			sum %= m;
		}
		cout<<sum<<endl;
	}
	return 0;
}