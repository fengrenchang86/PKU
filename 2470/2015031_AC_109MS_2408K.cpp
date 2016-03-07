#include <iostream>
using namespace std;
int main ()
{
	int n;
	int i;
	bool amb;
	while ( scanf("%d",&n) && n != 0 )
	{
		amb = true;
		int *a = new int[n+1];
		for ( i = 1; i <= n; i++ )
			scanf("%d",&a[i]);
		for ( i = 1; i <= n; i++ )
		{
			if ( a[a[i]] != i )
			{
				amb = false;
				break;
			}
		}
		if ( amb == true )
			printf("ambiguous\n");
		else
			printf("not ambiguous\n");
	}
	return 1;
}