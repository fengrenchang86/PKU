#include<iostream>
using namespace std;
const double pi = 3.1415927;
int main ()
{
	long double d;
	int round;
	long double second;
	int c = 1;
	long double ans;
	while( cin>>d>>round>>second && round != 0 )
	{
		printf("Trip #%d: ",c++);
		ans = pi*1.0*d/5280.0*round/12.0;
		printf("%0.2f %0.2f\n",ans,ans/second*3600);
	}
	return 1;
}
