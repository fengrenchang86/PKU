#include <iostream.h>
int a;
int b;
int c;
int f( int x )
{
	return a*x*x+b*x+c;
}
void main ()
{
	int e1;
	int e2;
	int e3;
	while ( cin>>e1>>e2>>e3 )
	{
		c = e1;
		a = (e3-e2)/3;
		b = e2-e1-a;
		cout<<f(3)<<" "<<f(4)<<" "<<f(5)<<endl;
	}
}