#include <iostream>
using namespace std;
int ww ( int a, int b, int c )
{
	if ( a <= 0 || b<= 0 || c<=0 )
		return 1;
	if( a > 20 || b>20 || c>20 )
		return ww(20,20,20);
	if ( a < b && b < c )
		return (ww(a, b, c-1) + ww(a, b-1, c-1) - ww(a, b-1, c) );
	return (ww(a-1, b, c) + ww(a-1, b-1, c) + ww(a-1, b, c-1) - ww(a-1, b-1, c-1) );
}
int main ()
{
	int w[21][21][21];
	int i,j,k;
	for ( i = 0; i < 21; i++ )
	{
		for ( j = 0; j < 21; j++ )
			w[i][j][0] = w[0][i][j] = w[i][0][j] = 1;
	}
	for ( i = 1; i < 21; i++ )
		for ( j = 1; j <21; j++ )
			for  ( k = 1;k < 21; k++ )
			{
				if ( i < j && j < k )
					w[i][j][k] = w[i][j][k-1]+w[i][j-1][k-1]-w[i][j-1][k];
				else
					w[i][j][k] = w[i-1][j][k]-w[i-1][j-1][k-1]+w[i-1][j-1][k]+w[i-1][j][k-1];
			}
				
	int a,b,c;
	while ( scanf("%d %d %d",&a,&b,&c)&&!(a==-1&&b==-1&&c==-1) )
	{
		printf("w(%d, %d, %d) = ",a,b,c);
		if ( a > 20 || b>20 || c>20 )
			a = b= c = 20;
		else if ( a <= 0 || b<=0 || c<=0 )
			a = b= c = 0;
		printf("%d\n",w[a][b][c]);
	//	printf("%d\n",ww(a,b,c));
	}
	return 1;
}