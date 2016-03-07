#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	int base[50];
	int sum[50];
	int i = 0;
	int d;
	base[0] = 1;
	for ( i = 1; i < 32; i++ )
		base[i] = base[i-1]*(-2);
	sum[0] = base[0];
	sum[1] = base[1];
	for ( i = 2; i < 32; i++ )
		sum[i] = base[i] + sum[i-2];
//	for ( i = 0; i < 32; i++ )
//		printf("the %d number is %d\n",i,base[i]);
//	for ( i = 0; i < 32; i++ )
//		printf("the %d number: %d\n",i,sum[i]);
	
	int n;
	int a[50];
	while ( scanf("%d",&n) != EOF )
	{
		for ( i = 0; i < 40; i++ )
			a[i] = 0;
		if ( n < 0 )
			i = 31;
		else if ( n > 0 )
			i = 30;
		else
		{
			printf("0\n");
			continue;
		}
		while ( i >= 0 )
		{
			if ( n == 0 )
				break;
			if ( base[i]/n<0 )
				i--;
			while ( abs(n-base[i]) > abs(sum[i-1]) )
				i-=2;
			a[i] = 1;
			n -= base[i];
			i--;
		}
		i = 30;
		while ( a[i] == 0 )
			i--;
		while ( i >= 0 )
			printf("%d",a[i--]);
		printf("\n");
	}
	return 1;
}