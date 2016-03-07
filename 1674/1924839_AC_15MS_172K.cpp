#include <iostream>
using namespace std;
const int max = 10010;
void main ()
{
	int t;
	int it;
	int n;
	int i;
	int c = 0;
	int a[max];
	int b[max];
	scanf("%d",&t);
	for ( it = 0; it < t; it++ )
	{
		c = 0;
		scanf("%d",&n);
		for ( i = 1; i <= n; i++ )
		{
			scanf("%d",&b[i]);
			a[b[i]] = i;
		}
		for ( i = 1; i <= n; i++ )
		{
			if ( b[i] != i )
			{
				b[a[i]] = b[i];
				a[b[i]] = a[i];
				a[i] = i;
				c++;
			}
		}
		printf("%d\n",c);
	}
	
}