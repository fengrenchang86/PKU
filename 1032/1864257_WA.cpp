#include <iostream.h>
void main ()
{
	int n;
	cin>>n;
	if ( n % 2 == 0 )
		cout<<n/2-1<<" "<<n/2+1<<endl;
	else
		cout<<n/2<<" "<<n/2+1<<endl;
}