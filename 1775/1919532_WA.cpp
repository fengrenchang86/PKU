#include <iostream>
using namespace std;
int main ()
{
	int list[10] = {1,2,6,24,120,720,5040,40320,362880};
	short a[9] = { 0, 0, 0 ,0 , 0, 0 ,0 ,0 ,0};
	int count = 0;
	int p = 0;
	int v[520] = { 0 };
	int i = 0;
	while ( p < 9 )
	{
		a[0] ++;
		p = 0;
		while ( a[p] == 2 )
		{
			a[p+1]++;
			a[p++] = 0;
		}
		for ( i = 0; i < 9; i++ )
			if ( a[i] == 1 )
				v[count]+=list[i];
		count++;
	}
	while ( scanf("%d",&p) && p>0 )
	{
		i=0;
		while ( v[i] < p )
			i++;
		if ( v[i] == p )
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 1;
}