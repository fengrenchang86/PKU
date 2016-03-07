#include <iostream>
using namespace std;
int acMin=2000000000;
int v;
int run ()
{
	acMin = 2000000000;
	int i,j,k;
	int x,y,z;
	for ( i = 1; i*i <= v; i++ )
	{
		if ( v % i != 0 )
			continue;
		for ( j = i; i*j <= v; j++ )
		{
			if ( v/i%j != 0 )
				continue;
			k = v/i/j;
			if ( 2*(i*j+j*k+i*k) < acMin )
			{
				acMin = 2*(i*j+j*k+i*k);
				x = i;
				y = j;
				z = k;
			}
		}
	}
	cout<<x<<" "<<y<<" "<<z<<endl;
	return 0;
}
int main ()
{
	while ( cin>>v )
		run();
	return 0;
}
