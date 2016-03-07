#include <iostream>
using namespace std;
int main ()
{
	int tc;
	int i,k,n,a,b;
	scanf("%d",&tc);
	while ( tc-- )
	{
		scanf("%d",&n);
		scanf("%d",&a);
		b = a;
		for ( i = 1; i < n; i++ )
		{
			scanf("%d",&k);
			if ( k > a )
				a = k;
			if ( k < b )
				b = k;
		}
		printf("%d\n",2*(a-b));
	}
	return 0;
}