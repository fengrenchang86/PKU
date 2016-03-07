#include <iostream>
using namespace std;
int main ()
{
	int c;
	int n;
	int k;
	int s = 0;
	scanf("%d",&n);
	int i;
	int open = 0;
	for ( i = 0; i < n; i++ )
	{
		scanf("%d",&k);
		if (open==0 && k <= s )
		{
			open = 1;
			cout<<i<<endl;
		}
		if ( open == 1 && k >= s )
		{
			open = 0;
		}
		s = k;
	}
	if ( open == 0 )
		cout<<n<<endl;
	return 1;
}