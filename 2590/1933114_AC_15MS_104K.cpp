#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	int a,b,d,m,n,i;
	scanf("%d",&n);
	for ( i = 0; i < n; i ++ )
	{
		scanf("%d %d",&a,&b);
		if ( a > b )
			d = a - b;
		else
			d = b - a;
		m = sqrt(d);
		if ( d == 0 )
			d = 0;
		else if ( m*m==d )
			d = 2*m-1;
		else
		{
			if ( d <= m*(m+1) )
				d = 2*m;
			else
				d = 2*m+1;
		}
		printf("%d\n",d);
	}
	return 1;
}