#include <iostream.h>
#include <math.h>
#include <iomanip.h>
const double pi = 3.1415926;
const double PI = 3.1415926;
void main ()
{
	int i;
	int n;
	cin>>n;
	double R;
	int num;
	double a;
	double r;
	for ( i = 0; i < 1000000; )
		i++;
	for ( i = 0; i < n; i++)
	{
		cin>>R>>num;
		a = PI/num;
		a = sin(a);
		r = (R*a)/(a+1);
		cout<<"Scenario #"<<i+1<<":"<<endl;
		cout<<setiosflags(ios::fixed)<<setprecision(3)<<r<<endl;
		cout<<endl;
	}
}