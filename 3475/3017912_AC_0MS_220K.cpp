#include <iostream>
using namespace std;
int f ( int x, int y )
{
	double a=double(x),b=double(y);
	int i = 0;
	while ( b > a )
	{
		b/=2.0;
		i++;
	}
	return i;
}
int main ()
{
	int a,b,c,d,t,m;
	while ( cin>>a>>b>>c>>d )
	{
		t = f(a,c);
		t += f(b,d);
		m = f(b,c);
		m += f(a,d);
		if ( t < m )
			cout<<t<<endl;
		else
			cout<<m<<endl;
	}
	return 0;
}