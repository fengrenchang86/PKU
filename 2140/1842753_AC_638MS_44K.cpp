#include <iostream.h>
void main ()
{
	int n;
	double i;
	int j;
	int c= 0;
	cin>>n;
	for ( j = 1; j <= n; j++ )
	{
		i = 1.0*n/j - 1.0*(j-1)/2;
		if ( int(i) == i && i>0 )
			c++;
	}
	cout<<c<<endl;
}