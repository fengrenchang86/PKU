#include <iostream>
using namespace std;
int main ()
{
	int ans;
	int n;
	short a[101][101];
	int i;
	int j;
	int r,c;
	int x=-1,y=-1;
	int temp;
	while ( scanf("%d",&n) && n != 0 )
	{
		ans = 0;
		r = c = 0;
		for ( i = 0; i < n; i++ )
		{
			for (j  = 0 ;j < n; j++ )
				scanf("%d",&a[i][j]);
		}
		for ( i = 0; i < n; i++ )
		{
			temp = 0;
			for ( j = 0; j< n;j++ )
				temp += a[i][j];
			if ( temp % 2 == 1 )
			{
				r++;
				x = i;
			}
			if ( r == 2 )
			{
				ans = 2;
				printf("Corrupt\n");
				break;
			}
		}
		if ( ans == 2 )
			continue;
		for ( j = 0; j < n; j++ )
		{
			temp = 0;
			for ( i = 0; i < n; i++ )
				temp += a[i][j];
			if ( temp % 2 == 1 )
			{
				c++;
				y = j;
			}
			if ( c == 2 )
			{
				ans = 2;
				printf("Corrupt\n");
				break;
			}
		}
		if ( ans == 2 )
			continue;
		else if ( r==1 && c==1 )
			printf("Change bit (%d,%d)\n",x+1,y+1);
		else
			printf("OK\n");
	}
	return 1;
}