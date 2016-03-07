#include <iostream>
using namespace std;
const double pi = 3.14159;
int main ()
{
	char begin[10];
	int x,y,z;
	double s;
	while ( cin>>begin && begin[3]!='O' )
	{
		cin>>x>>y>>z;
		cin>>begin;
		s = 2.0*z/360*pi*x;
		s*=2;
//		s = int(s);
		if ( s/5 > y )
			cout<<"NO "<<y*5<<endl;
		else
			cout<<"YES "<<y-int(s/5)<<endl;
	}
	return 1;
}