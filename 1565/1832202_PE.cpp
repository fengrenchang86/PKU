#include <iostream.h>
void main ()
{
	unsigned int cf ( int, int );
	char in[64];
	int arr[32];
	int c[10];
	int i;
	int len;
	int sum;
	for ( i = 0; i < 31; i++ )
		arr[i] = cf ( 2, i+1 ) - 1;

	for ( i = 0; i < 10; i++ )
		c[i] = 0;
	while ( cin>>in )
	{
		if ( in[0] == '0' )
			break;
		sum = 0;
		len = 0;
		while ( in[len] != NULL )
			len++;
		len--;
		for ( i = len; i >= 0; i-- )
			sum += ( in[i] - '0' ) * arr[len - i];
		cout<<sum;


	}
}

unsigned int cf ( int p, int n )
{
	int i;
	unsigned int ans = 1;
	for ( i = 0; i < n; i++ )
		ans *= p;
	return ans;
}