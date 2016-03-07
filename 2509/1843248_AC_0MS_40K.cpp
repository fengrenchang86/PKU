#include <iostream.h>
void main ()
{
	int n;
	int k;
	int sum;
	int c;
	int g;
	while ( cin>>n>>k && n!=0 && k!=0)
	{
		sum = n;
		g = n;
		while ( g >= k )
		{			
			c = g/k;
			g = g - c*k + c;
			sum += c;
		}
		cout<<sum<<endl;
	}
}