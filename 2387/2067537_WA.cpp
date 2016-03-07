#include <iostream>
using namespace std;
int main ()
{
	int t,n;
	int it;
	scanf("%d%d",&t,&n);
	int *Y = new int[n+1];
	int *value = new int[n+1];
	int **c = new int*[n+1];
	int i,j;
	for ( i = 0; i <= n; i++ )
		c[i] = new int[n+1];
	for ( i = 0; i <= n; i++ )
	{
		Y[i] = 0;
		value[i] = 999999;
		for ( j = 0; j <= n; j++ )
			c[i][j] = 999999;
	}
	int x,y,distance;
	Y[1] = 1;
	for ( it = 0; it < t; it++ )
	{
		scanf("%d%d%d", &x, &y, &distance);
		c[x][y] = distance;
		c[y][x] = distance;
	}
	for ( i = 2; i <= n; i++ )
	{
		if ( c[i][1] < value[i] )
			value[i] = c[i][1];
	}
	int min;
	for ( j = 1; j <= n-1; j++ )
	{
		min = 1;
		for ( i = 2; i <= n; i++ )
		{
			if ( Y[i] == 0 )
			{
				if ( value[i] < value[min] )
					min = i;
			}
		}
		Y[min] = 1;
		for ( i = 1; i <= n; i++ )
		{
			if ( Y[i] == 0 )
				if ( value[min]+c[i][min] < value[i] )
					value[i] = value[min]+c[i][min];
		}
	}
	cout<<value[n]<<endl;
	return 0;
}