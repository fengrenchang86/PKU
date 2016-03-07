#include <iostream.h>
void main ()
{
	int i;
	int n;
	int sum;
	while ( cin>>n && n != 0 )
	{
		sum = 0;
		for ( i = 2; i <= n; i++ )
		{
			sum += (i-1)/2;
		}
		sum *= 2;
		sum++;
		cout<<sum<<endl;
	}
}