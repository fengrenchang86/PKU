#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	int x,y,z;
	while ( cin>>x>>y )
	{
		 if ( x > y )
		 {
			 z = x;
			 x = y;
			 y = z;
		 }
		 if ( x == y )
		 {
			 z = int(sqrt(double(x+y)));
		 }
		 else
			 z = int(sqrt(double(x+x+1)));
		if ( z == 0 )
			cout<<"Impossible"<<endl;
		else
			cout<<z<<endl;
	}
	return 0;
}