#include <iostream>
using namespace std;
int f ( int x, int y )
{
	int i = 0;
	while ( y > x )
	{
		y/=2;
		i++;
	}
	return i;
}
int main ()
{
	int a,b,c,d,t,m;
	while ( cin>>a>>b>>c>>d )
	{
		if ( a > b )
		{
			t = a;
			a = b;
			b = t;
		}
		if ( c > d )
		{
			t = c;
			c = d;
			d = t;
		}
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