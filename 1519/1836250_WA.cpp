#include <iostream.h>
void main ()
{
	int f ( int );
	int n;
	int ans ;
	while ( 1 )
	{
	cin>>n;
	if ( n == 0 )break;
	ans = n;
	while ( 1 )
	{
		ans = f ( ans );
		if ( ans >= 10 )
			continue;
		else
			break;
	}
	cout<<ans<<endl;
	}
}

int f ( int i )
{
	int sum = 0;
	int k = i;
	while ( k != 0 )
	{
		sum += k - k/10*10;
		k /= 10;
	}
	return sum;
}