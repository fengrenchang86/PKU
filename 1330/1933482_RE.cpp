#include <iostream>
using namespace std;

const int max = 100;

int main ()
{
	int a[max] = { -1 };
	int i,j,x,y,n,k;
	int tcase,it;
	scanf("%d",&tcase);
	for ( it = 0; it < tcase; it ++ )
	{
		scanf("%d",&n);
		for ( k = 0; k < n-1; k++ )
		{
			scanf("%d %d",&x,&y);
			a[y] = x;
		}
		scanf("%d %d",&x,&y);
		i = x;
		j = y;
		while ( 1 )
		{
			if ( a[i] == -2 )
				break;
			else if ( a[i] == -1 )
				i = j;
			k = i;
			i = a[i];
			a[k] = -2;
			if ( a[j] == -2 )
			{
				i = j;
				break;
			}
			else if ( a[j] == -1 )
				j = i;
			k = j;
			j = a[j];
			a[k] = -2;
		}
		printf("%d\n",i);
		for ( i = 0; i < max; i++ )
			a[i] = -1;
	}
	return 1;
}