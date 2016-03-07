#include <iostream.h>
void main ()
{
	int n;
	int a;
	int b;
	int c;
	int i;
	cin>>n;
	for ( i = 0; i < n; i++ )
	{
		cin>>a>>b>>c;
		if ( a+c > b )
			cout<<"do not advertise"<<endl;
		else if ( a + c < b )
			cout<<"advertise"<<endl;
		else 
			cout<<"does not matter"<<endl;
	}
}