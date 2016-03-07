#include <iostream>
using namespace std;
int main ()
{
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	if ( a <= d && c <=e || c <= b && a <= c || a+c<=e )
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}