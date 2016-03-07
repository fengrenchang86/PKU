#include <iostream>
using namespace std;
int main ()
{
	char a[160][30];
	int n;
	int i;
	int j;
	int x,y;
	char c[500];
	while ( scanf("%d",&n) && n!=0 )
	{
		scanf("%s",c);
		for ( x = 0; x < 160; x++ )
			for ( y = 0; y < 30; y++ )
				a[x][y] = 0;
		j = 0;
		i = 0;
		x = y = 0;
		while ( c[i] != NULL )
		{	
			if ( j%2==0 )
			{
				for ( x = 0; x < n&&c[i]!=NULL; x++ )
					a[j][x] = c[i++];
				j++;
			}
			else
			{
				for ( x = n-1; x >= 0&&c[i]!=NULL; x-- )
					a[j][x] = c[i++];
				j++;
			}
		}
		for ( y = 0; y < n; y++ )
		{
			for ( x = 0; a[x][y]!=NULL; x++ )
				printf("%c",a[x][y]);
		}
		printf("\n");
	}
	return 1;
}