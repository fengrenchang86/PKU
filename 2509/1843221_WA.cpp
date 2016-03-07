#include <iostream.h>
void main ()
{
	int n;
	int k;
	int sum;
	int c;
	while ( cin>>n>>k )
	{
		c = n;
		sum = n;
		while ( c > 0 )
		{
			c = c/k;
			sum += c;
		}
		cout<<sum<<endl;
	}
}