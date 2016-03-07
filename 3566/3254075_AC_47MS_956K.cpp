#include <iostream>
using namespace std;
int v[60][60][60];
int main ()
{
	int n;
	int i,j,k;
	while ( cin>>n )
	{
		for ( i = 0; i < n; i++ )
		{
			for ( j = 0; j < n; j++ )
			{
				v[i][j][0] = i;
				v[i][j][1] = j;
			}
		}
		printf("%d 2 %d\n",n,n);
		for ( i = 0; i < n; i++ )
		{
			for ( j = 0; j < n; j++ )
			{
				for ( k = 0; k <= 1; k++ )
				{
					if ( v[i][j][k] < 26 )
						printf("%c",char(v[i][j][k]+'A'));
					else
						printf("%c",char(v[i][j][k]-26+'a'));
				}
				printf("\n");
			}
			printf("\n");
		}
	}
	return 0;
}