#include <iostream>
using namespace std;
int main ()
{
	int n,k;
	while ( scanf("%d%d",&n,&k) != EOF )
	{
		k = k < n-k ? k:n-k;
		if ( k == 0 )
		{
			cout<<1<<endl;
			continue;
		}
		if ( k == 1 && n%2==1)
			cout<<1<<endl;
		else
			cout<<0<<endl;
	}
	return 0;
}