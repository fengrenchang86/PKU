#include <iostream>
using namespace std;
int main ()
{
	int b[8002];
	int a[8002];
	int n,i,j,c;
	scanf("%d",&n);
	for ( i = 0; i <= n; i++ )
		a[i] = 0;
	for ( i = 2; i <= n; i++ )
		scanf("%d",&b[i]);
	b[1] = 0;
	for ( i = n; i >= 1; i-- )
	{
		c = 0;
		j = 1;
		while ( c < b[i] )
		{
			if ( a[j] == 0 )
				c++;
			j++;
		}
		while ( a[j] != 0 )
			j++;
		a[j] = i;
	}
	for ( i = 1; i <= n; i++ )
		b[a[i]] = i;
	for ( i = 1; i <= n; i++ )
		printf("%d\n",b[i]);
	return 0;
}