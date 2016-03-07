#include <iostream.h>
void main ()
{
	char input[100];
	int i = 0;
	int k;
	int sum = 0;
	i = 0;
	while ( cin>>input && (input[1] != 0 || input[0] != '0'))
	{
		sum = 0;
		for ( k = 0; input[k] != NULL; k++ )
			sum += (input[k]-'0');

		
	while ( sum >= 10 )
	{
		k = sum;
		sum = 0;
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
