#include <iostream>
using namespace std;
bool c[2][1002];
struct PP
{
	int x,y;
	int max;
}path[50][1002];
int MAX ( int a, int b )
{
	return a>b?a:b;
}
int main ()
{
	int tcase,n,i,j,k;
	int a[1002];
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		scanf("%d",&n);
		for ( i = 1; i <= n; i++ )
		{
			scanf("%d",&a[i]);
		}
		for ( i = 1; i <= 998; i++ )
			c[0][i] = false;
		c[0][0] = true;
		path[0][0].x= 0;
		path[0][0].y= 0;
		path[0][0].max = 0;
		for ( i = 1; i <= n; i++ )
		{
			for ( j = 0; j <= 998; j++ )
			{
				c[i%2][j] = false;
				
				if ( j-a[i] >= 0 && c[(i+1)%2][j-a[i]] == true )
				{
					path[i][j].x=i-1;
					path[i][j].y = j-a[i];
					path[i][j].max = path[i-1][j-a[i]].max;
					c[i%2][j] = true;
				}
				if ( j+a[i] <= 998 && c[(i+1)%2][j+a[i]] == true && c[i%2][j] == false )
				{
					path[i][j].x = i-1;
					path[i][j].y = j+a[i];
					path[i][j].max = MAX(j+a[i],path[i-1][j+a[i]].max);
					c[i%2][j] = true;
				}
				else if ( j+a[i] <= 998 && c[(i+1)%2][j+a[i]] == true )
				{
					if ( MAX(j+a[i],path[i-1][j+a[i]].max) < path[i][j].max )
					{
						path[i][j].x = i-1;
						path[i][j].y = j+a[i];
						path[i][j].max = MAX(j+a[i],path[i-1][j+a[i]].max);
					}
				}
			}
		}
		if ( c[n%2][0] == false )
			printf("IMPOSSIBLE\n");
		else
		{
			i = n;
			j = 0;
			while ( i >= 0 )
			{
				if ( path[i][j].y < j )
					a[i] *= -1;
				j = path[i][j].y;
				i --;
			}
			for ( i = 1; i <= n; i++ )
			{
				if ( a[i] > 0 )
					printf("D");
				else
					printf("U");
			}
			printf("\n");
		}
	}
	return 0;
}