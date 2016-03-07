#include <iostream>
using namespace std;

int main ()
{
	int w[22][22][22];
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
				if (( i < j) && (j < k ))
					w[i][j][k] = w[i][j][k-1]+w[i][j-1][k-1]-w[i][j-1][k];
				else
					w[i][j][k] = w[i-1][j][k]-w[i-1][j-1][k-1]+w[i-1][j-1][k]+w[i-1][j][k-1];
			}
				
	int a,b,c,x,y,z;
	while ( scanf("%d %d %d",&a,&b,&c)!=EOF )
	{
		if ( a==-1&&b==-1&&c==-1)
			break;
		x = a;
		y = b;
		z = c;
		if ( a <= 0 || b<=0 || c<=0 )
			printf("w(%d, %d, 1) = %d\n",x,y,z);
		else if ( a > 20 || b>20 || c>20 )
			printf("w(%d, %d, %d) = %d\n",x,y,z,w[20][20][20]);
		else
		printf("w(%d, %d, %d) = %d\n",x,y,z,w[a][b][c]);
	}
	return 1;
}