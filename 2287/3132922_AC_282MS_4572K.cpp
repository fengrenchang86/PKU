#include <iostream>
#include <stdlib.h>
using namespace std;
int c[1100][1100];
int max ( int x, int y )
{
	return x>y?x:y;
}
int cmp ( const void *a , const void *b ) 
{ 
     return *(int *)b - *(int *)a; 
} 
int main ()
{
	int a[1100];
	int b[1100];
	int i,j,n,x,y;
	while ( scanf("%d",&n) && n )
	{
		for ( i = 1; i <= n; i++ )
			scanf("%d",&a[i]);
		for ( i = 1; i <= n; i++ )
			scanf("%d",&b[i]);
		b[0] = a[0] = 2000000;
		qsort(a,n+1,sizeof(a[0]),cmp);
		qsort(b,n+1,sizeof(b[0]),cmp);
		if ( a[n] > b[1] )
			c[1][0] = 200;
		else if ( a[n] == b[1] )
			c[1][0] = 0;
		else
			c[1][0] = -200;
		if ( a[1] > b[1] )
			c[1][1] = 200;
		else if ( a[1] == b[1] )
			c[1][1] = 0;
		else
			c[1][1] = -200;
		for ( i = 2; i <= n; i++ )
		{
			c[i][0] = c[i-1][0];
			if ( b[i] > a[n-i+1] )
				c[i][0] -= 200;
			else if ( b[i] < a[n-i+1] )
				c[i][0] += 200;
			for ( j = 1; j <= i; j++ )
			{
				if ( b[i] < a[n-i+j+1] )
					x = 200;
				else if ( b[i] == a[n-i+j+1] )
					x = 0;
				else
					x = -200;
				if ( b[i] < a[j] )
					y = 200;
				else if ( b[i] == a[j] )
					y = 0;
				else
					y = -200;
				if ( i-1 >= j )
					c[i][j] = max(c[i-1][j]+x,c[i-1][j-1]+y);
				else
					c[i][j] = c[i-1][j-1]+y;
			}
		}
		y = c[n][0];
		for ( i = 1; i <= n; i++ )
		{
			if ( c[n][i] > y )
				y = c[n][i];
		}
		printf("%d\n",y);
	}
	return 0;
}