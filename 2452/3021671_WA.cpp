#include <iostream>
using namespace std;
int a[60000];
int c[60000];
int main ()
{
	int n,i,ans;
	while ( scanf("%d",&n) != EOF )
	{
		ans = -1;
		for ( i = 0; i < n; i++ )
		{
			c[i] = 0;
			scanf("%d",&a[i]);
		}
		for ( i = 1; i < n; i++ )
		{
			if ( a[i] > a[i-1] )
				c[i] = c[i-1]+1;
			if ( c[i] > ans )
				ans = c[i];
		}
		if ( ans == 0 )
			ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}