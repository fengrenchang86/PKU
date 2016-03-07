#include <iostream.h>
void main ()
{
	int input;
	int i = 0;
	int k;
	int sum = 0;
	i = 0;
	while ( cin>>input && input != 0)
	{
		sum = input;		
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
