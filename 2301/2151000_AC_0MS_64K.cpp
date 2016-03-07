#include <iostream.h>
void main ()
{
	int n;
	int i;
	int a;
	int b;
	int x;
	int y;
	cin>>n;
	for ( i = 0; i < n ; i++ )
	{
		cin>>a>>b;
		x = (a+b)/2;
		y = (a-b)/2;
		if ( a>=b && (a+b)%2==0 )
			cout<<x<<" "<<y<<endl;
		else
			cout<<"impossible"<<endl;
	}
}
