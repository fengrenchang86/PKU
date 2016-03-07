#include <iostream>
using namespace std;
int f ( char a )
{
	if ( a == 'A' )
		return 0;
	if ( a == 'C' )
		return 1;
	if ( a == 'G' )
		return 2;
	if ( a == 'T' )
		return 3;
	else
		return 4;
}
int main ()
{
	int t;
	int ti;
	int size1,size2;
	int i;
	int j;
	char a[120];
	char b[120];
	short list[5][5] = { {5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},
	{-1,-2,-2,5,-1},{-3,-4,-2,-1,0} };
	int c[120][120];
	scanf("%d",&t);
	for ( ti = 0; ti < t; ti++ )
	{
		scanf("%d %s",&size1,a);
		scanf("%d %s",&size2,b);
		a[size1++] = ' ';
		a[size1] = NULL;
		b[size2++] = ' ';
		b[size2] = NULL;
		c[0][0] = 0;
		for ( i = 0; i <= size1; i++ )
			c[i+1][0] = c[i][0] + list[f(a[i])][4];
		for ( j = 0; j <= size2; j++ )
			c[0][j+1] = c[0][j] + list[4][f(b[j])];
		for ( i = 0; i < size1; i++ )
			for ( j = 0; j < size2; j++ )
			{
				c[i+1][j+1] = c[i][j] + list[f(a[i])][f(b[j])];
				if ( c[i+1][j+1] < c[i][j+1]+list[f(a[i])][4] )
					c[i+1][j+1] = c[i][j+1]+list[f(a[i])][4];
				if ( c[i+1][j+1] < c[i+1][j]+list[4][f(b[j])])
					 c[i+1][j+1] = c[i+1][j]+list[4][f(b[j])];
			}
		printf("%d\n",c[i][j]);
	}
	return 1;
}