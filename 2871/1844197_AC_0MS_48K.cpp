#include <iostream.h>
#include <iomanip.h>
void main ()
{
	double a;
	double b;
	cin>>a;
	while ( cin>>b && b!=999)
	{
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<b-a<<endl;
		a = b;
	}
	cout<<"End of Output"<<endl;
}