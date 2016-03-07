#include <iostream>
#include <fstream.h>
using namespace std;
struct ac
{
	int x,y;
	int pos;
	ac(){pos=0;}
}a[1002];
int fmax ( int a, int b, int c )
{
	if ( a > b )
	{
		if ( c > a )
			return c;
		else
			return a;
	}
	else
	{
		if ( c >= b )
			return c;
		else
			return b;
	}
}
int fmax ( int a, int b )
{
	return a>b?a:b;
}
int main ()
{
	int v[1002][16][16];
	int i,j,k;
//	freopen("in.txt","r",stdin);
	int n = 1;
	while ( scanf("%d%d",&a[n].x,&a[n].y) != EOF )
		n++;
	v[1][0][0] = 0;
	v[1][1][0] = a[1].x;
	v[1][0][1] = a[1].y;
	for ( i = 2; i < n; i++ )
	{
		for ( j = 0; j <= i && j <= 15; j++ )
		{
			for ( k = 0; j+k <= i && k <= 15; k++ )
			{
				if ( j-1 <0  && k-1 >= 0 )
					v[i][j][k] = fmax(v[i-1][j][k-1]+a[i].y,v[i-1][j][k]);
				else if ( k-1 < 0 && j-1 >= 0)
					v[i][j][k] = fmax(v[i-1][j-1][k]+a[i].x,v[i-1][j][k]);
				else if ( k-1 < 0 && j-1 < 0 )
					v[i][j][k] = 0;
				else
				v[i][j][k] = fmax(v[i-1][j-1][k]+a[i].x,v[i-1][j][k-1]+a[i].y,v[i-1][j][k]);
			}
		}
	}
	printf("%d\n",v[n-1][15][15]);
	return 0;
}