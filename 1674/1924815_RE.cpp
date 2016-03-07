#include <iostream>
using namespace std;
const int max = 1000;
void main ()
{
	int t;
	int it;
	int n;
	int i;
	int c = 0;
	int temp;
	int a[max];
	scanf("%d",&t);
	for ( it = 0; it < t; it++ )
	{
		scanf("%d",&n);
		for ( i = 1; i <= n; i++ )
		{
			scanf("%d",&temp);
			a[temp] = i;
		}
		for ( i = 1; i <= n; i++ )
		{
			if ( a[i] != i )
			{
				temp = a[a[i]];
				a[a[i]] = a[i];
				a[i] = temp;
				c++;
			}
		}
		printf("%d\n",c);
	}
	
}