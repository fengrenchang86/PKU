#include <iostream.h>
void main ()
{
	int n;
	int k;
	int i;
	int sum;
	while ( cin>>n>>k )
	{	
		sum = 0;
		for ( i = 1; i <= n; i++ )
			sum += (k%i);
		cout<<sum<<endl;
	}
}
