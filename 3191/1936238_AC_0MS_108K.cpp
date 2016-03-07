#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	double base[50];
	double sum[50];
	double x,y;
	int i = 0;
	int d;
	base[0] = 1;
	for ( i = 1; i <= 32; i++ )
		base[i] = base[i-1]*(-2);
	sum[0] = base[0];
	sum[1] = base[1];
	for ( i = 2; i <= 32; i++ )
		sum[i] = base[i] + sum[i-2];
//	for ( i = 0; i <= 32; i++ )
//		printf("the %d number is %f\n",i,base[i]);
//	for ( i = 0; i <= 32; i++ )
//		printf("the %d number: %f\n",i,sum[i]);
	
	double n;
	int a[50];
//	while ( scanf("%d",&n) != EOF )
	scanf("%lf",&n);
	{
		for ( i = 0; i < 40; i++ )
			a[i] = 0;
		if ( n < 0 )
			i = 31;
		else if ( n > 0 )
			i = 32;
		else
		{
			printf("0\n");
	//		continue;
			return 1;
		}
		while ( i >= 0 )
		{
			if ( n == 0 )
				break;
			if ( base[i]/n<0 )
				i--;
			x = n-base[i];
			y = sum[i-1];
			if ( x < 0 )
				x *= -1;
			if  ( y < 0 )
				y *= -1;
			while ( x - y > 0 )
			{
				i-=2;
				x = n-base[i];
				y = sum[i-1];
				if ( x < 0 )
					x *= -1;
				if ( y < 0 )
					y *= -1;
			}
			a[i] = 1;
			n -= base[i];
			i--;
		}
		i = 32;
		while ( a[i] == 0 )
			i--;
		while ( i >= 0 )
			printf("%d",a[i--]);
		printf("\n");
	}
	return 1;
}