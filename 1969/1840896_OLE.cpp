#include <iostream.h>
#include <math.h>
void main()
{
	int i;
	int n;
	int d;
	int j;
	int ans;
	while ( 1 )
	{
	cin>>n;
	if ( n == 1 )
	{
		cout<<"1/1"<<endl;
		continue;
	}
	else if ( n==2)
	{
		cout<<"1/2"<<endl;
		continue;
	}
	else if ( n == 3 )
	{
		cout<<"2/1"<<endl;
		continue;
	}
	else;
	i = (sqrt(1+8*n)-1)/2;
	ans = i+1;
	i = ( i*i + i ) / 2;
	d = n - i - 1;
	if ( d == -1 )
	{
		ans--;
		i = ans;
		ans = 1;
	}
	else
	{
	i = ans;	
	ans = ans - d;
	}
	cout<<"TERM ";
	if ( i%2!=0)
		cout<<ans<<'/'<<i+1-ans<<endl;
	else 
		cout<<i+1-ans<<'/'<<ans<<endl;
	}	
}