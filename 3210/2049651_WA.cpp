#include <iostream>
using  namespace std;
int main ()
{
	int n;
	while ( scanf("%d",&n) && n!=0 )
	{
		if ( n == 2 )
			cout<<"No Solution!"<<endl;
		else
		{
			cout<<n/2*2<<endl;
		}
	}
	return 1;
}