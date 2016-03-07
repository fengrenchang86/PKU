#include <iostream.h>
void main ()
{
	int f ( int );
	char n[100];
	int ans ;
	int i;
	while ( cin>>n )
	{
	if ( n[0] == '0' )break;
	ans = 0;
	for ( i = 0; n[i] != NULL; i++ )
		ans += ( n[i] - '0' );
	
	while ( ans >= 10 )
	{
		ans = f ( ans );
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