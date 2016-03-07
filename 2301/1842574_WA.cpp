#include <iostream.h>
void main ()
{
	int n;
	int i;
	int a;
	int b;
	double x;
	double y;
	cin>>n;
	for ( i = 0; i < n ; i++ )
	{
		cin>>a>>b;
		x = (a+b)/2;
		y = (a-b)/2;
		if ( x == int ( x ) && y == int ( y ) && x >= 0 && y >= 0 )
			cout<<x<<" "<<y<<endl;
		else
			cout<<"impossible"<<endl;
	}
}