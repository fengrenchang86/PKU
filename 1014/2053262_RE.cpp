#include <iostream>
using namespace std;
const int MAX = 20010;
int a[MAX];
int d[2][MAX];
int main ()
{
	int flag = 0;
	int v[6];
	int i,j,sum,num;
	int tcase = 1;
	while ( scanf("%d %d %d %d %d %d",&v[0],&v[1],&v[2],&v[3],&v[4],&v[5]) )
	{
		num = v[0] + v[1] + v[2] + v[3] + v[4] + v[5];
		if ( num == 0 )
			break;
		printf("Collection #%d:\n",tcase);
		tcase++;
		sum = v[0]+2*v[1]+3*v[2]+4*v[3]+5*v[4]+6*v[5];
		if ( sum %2==1 )
		{
			printf("Can't be divided.\n\n");
			continue;
		}
		sum /= 2;
		j = 1;
		for ( i = 0; i <= sum; i++ )
			d[0][i] = 0;
		d[1][0] = 0;
		for ( i = 0; i < v[5]; i++ )
			a[j++] = 6;
		for ( i = 0; i < v[4]; i++ )
			a[j++] = 5;
		for ( i = 0; i < v[3]; i++ )
			a[j++] = 4;
		for ( i = 0; i < v[2]; i++ )
			a[j++] = 3;
		for ( i = 0; i < v[1]; i++ )
			a[j++] = 2;
		for ( i = 0; i < v[0]; i++ )
			a[j++] = 1;
		for ( i = 1; i <= num; i++ )
		{
			for ( j = 1; j <= sum; j++ )
			{
				if ( j < a[i] )
					d[i%2][j] = d[(i-1)%2][j];
				else
				{
					if ( d[(i-1)%2][j] > d[(i-1)%2][j-a[i%2]]+a[i] )
						d[i%2][j] =	d[(i-1)%2][j];
					else
						d[i%2][j] = d[(i-1)%2][j-a[i%2]]+a[i];
				}
			}
			if ( d[i%2][sum] == sum )
			{
				flag = 1;
				break;
			}
		}
		if ( flag == 1 )
			printf("Can be divided.\n");
		else
			printf("Can't be divided.\n");
		flag = 0;
		printf("\n");
	}
	return 0;
}