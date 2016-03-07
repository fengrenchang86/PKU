#include <iostream>
using namespace std;
int main ()
{
	int list[10] = {1,1,2,6,24,120,720,5040,40320,362880};
	int d[12];
	int e[12];
	d[0] = list[0];
	e[0] = list[1];
	short a[9] = { 0, 0, 0 ,0 , 0, 0 ,0 ,0 ,0};
	int count = 0;
	int p = 0;
	int v[520] = { 0 };
	int i = 1;
	while ( i < 12 )
	{
		d[i] = d[i-1]+list[i];
		e[i] = e[i-1]+list[i+1];
//		printf("d[i]=%d\n",d[i]);
//		printf("e[i]=%d\n",e[i]);
		i++;
	}
	while ( scanf("%d",&p) && p>=0 )
	{
		if ( p == 0 )
		{
			printf("NO\n");
			continue;
		}
		for ( i = 0; i < 12; i++ )
		{
			if ( p == d[i] )
			{
				printf("YES\n");
				break;
			}
		}
		if ( p != d[i] )
		{
			for ( i = 0; i < 12; i++ )
			{
				if ( p == e[i] )
				{
					printf("YES\n");
					break;
				}
			}
			if ( p != e[i] )
				printf("NO\n");
		}
	}
	return 1;
}