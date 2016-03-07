#include <stdio.h>
int main ()
{
	int n,i;
	int a[60];
	int sum;
	int d;
	int tc = 1;
	while ( scanf("%d",&n) && n!=0 )
	{
		sum = 0;
		for ( i = 0; i <n ;i++ )
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}
		printf("Set #%d\n",tc);
		tc++;
		sum /= n;
		d = 0;
		for ( i = 0; i < n; i++ )
		{
			if( a[i] > sum )
				d += (a[i]-sum);
		}
		printf("The minimum number of moves is %d.\n",d);
	}
	return 0;
}