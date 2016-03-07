#include <iostream>
using namespace std;
int main ()
{
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	if ( a > e || c > e )
	{
		cout<<"No"<<endl;
		return 0;
	}
	if ( a > c )
	{
		if ( b > c )
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	else
	{
		if ( d > a )
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}