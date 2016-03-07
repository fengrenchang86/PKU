#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	int x,y;
	while ( cin>>x>>y )
	{
		x = int(sqrt(x+y));
		if ( x == 0 )
			cout<<"Impossible"<<endl;
		else
			cout<<x<<endl;
	}
	return 0;
}