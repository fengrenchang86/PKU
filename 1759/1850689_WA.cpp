#include <iostream.h>
#include <iomanip.h>
#include <math.h>
void main ()
{
	int n;
	double a1;
	double r1;
	double r2;
	double i;
	double sum;
	double a2;
	int a;
	{
		cin>>n>>a1;
	r1 = (n-1)*(n-2)+a1;
	a = (sqrt(a1)+1);
	i = a1/(a-1)+a-1 <= a1/a+a ? a :a+1;
	a2 = 2 - i - a1/(i-1);
	r2 = (n-1)*a2;
	sum = r1+r2;
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<sum<<endl;
	}
}