#include <stdio.h>
long a[1000100];
void main ()
{
	int i;
	a[1] = 1;
	a[2] = 2;
	for ( i = 3; i <= 1000000; i++ )
	{
		if ( i % 2 == 1 )	
		{
			a[i] = a[i-1];
		}
		else
		{
			a[i] = a[i-2] + a[i/2];
		}
		a[i] %= 1000000000;
	}
	scanf("%d",&i);
	printf("%d\n",a[i]);
}