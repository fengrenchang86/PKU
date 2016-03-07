#include <iostream.h>
void main ()
{
	int i;
	int n;
	int x;
	int y;
	cin>>n;
	for ( i = 0; i < n; i++ )
	{
		cin>>x>>y;
		if ( x < y )
			cout<<"NO BRAINS"<<endl;
		else 
			cout<<"MMM BRAINS"<<endl;
	}
}