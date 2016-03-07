#include <iostream.h>
void main ()
{
	char n[30];
	int ans ;
	int i;
	int k;
	int sum = 0;
	while ( cin>>n )
	{
	if ( n[0] == '0' )break;
	ans = 0;
	for ( i = 0; n[i] != NULL; i++ )
		ans += ( n[i] - '0' );
	sum = ans;
	k = ans;
	while ( sum >= 10 )
	{
		sum=0;
		while ( k != 0 )
		{
			
			sum+= k - k/10*10;
			k = k / 10;
		}
		k = sum;
	}
	cout<<sum<<endl;
	}
}
