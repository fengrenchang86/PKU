#include <iostream.h>
void main ()
{
	char input[30];
	int n[30];
	int ans ;
	int i = 0;
	for ( i = 0; i < 30; i++ )
		n[i] = 0;
	int k;
	int sum = 0;
	i = 0;
	while ( cin>>input && input[0] != '0')
	{
		for ( k = 0; input[k] != NULL; k++ )
			n[i] += (input[k]-'0');
		i++;
	}

	int j = 0;
	while ( j < i )
	{
	ans = 0;
	sum = n[j];
	k = sum;
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
	j++;
	}
}
