#include <iostream>
using namespace std;
int main ()
{
	int x;
	int a[6][2];
	int i,j;
	i = 0;
	while ( scanf("%d %d",&a[i][0],&a[i][1]) !=EOF )
	{
		if ( a[i][0] > a[i][1] )
		{
			j = a[i][0];
			a[i][0] = a[i][1];
			a[i][1] = j;
		}
		i++;
		if ( i < 6 )
			continue;
		for ( i = 0; i < 5; i++ )
		{
			for ( j = i+1; j < 6; j++ )
			{
				if ( a[i][0] < a[j][0] )
				{
					x = a[i][0];
					a[i][0] = a[j][0];
					a[j][0] = x;
					x = a[i][1];
					a[i][1] = a[j][1];
					a[j][1] = x;
				}
				if ( a[i][0] == a[j][0] && a[i][1] < a[j][1] )
				{
					x = a[i][0];
					a[i][0] = a[j][0];
					a[j][0] = x;
					x = a[i][1];
					a[i][1] = a[j][1];
					a[j][1] = x;
				}
			}
		}
		j = 0;
		for ( i = 0; i < 6; i+=2 )
		{
			if ( !(a[i][0] == a[i+1][0] && a[i][1] == a[i+1][1] ))
			{
				j = 1;
				break;
			}
		}
		if ( j == 0 )
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");
	i = 0;
	break;
	}
	return 1;
}