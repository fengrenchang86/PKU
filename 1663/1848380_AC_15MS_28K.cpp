
#include <iostream.h>
void main ()
{
	int n;
	int i;
	cin>>n;
	int x;
	int y;
	int ans;
	for ( i = 0; i < n; i++ )
	{
		cin>>x>>y;
		if ( !(x == y) && !(x-y == 2 ) )
		{
			cout<<"No Number"<<endl;
			continue;
		}
		else
		{
			if ( x%2 == 0 )
				ans = 2*x;
			else 
				ans = 2*x - 1;
			if ( x != y )
				ans = ans - 2;
		}
		cout<<ans<<endl;
	}
}