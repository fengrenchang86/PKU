#include <iostream>
using namespace std;
int main ()
{
	int tcase;
	int i,n,sum;
	int a[1001];
	scanf("%d",&tcase);
	while ( tcase )
	{
		scanf("%d",&n);
		for ( i = 1; i <= n; i++ )
			scanf("%d",&a[i]);
		if ( n == 1 )
		{
			printf("%d\n",a[1]);
			tcase--;
			continue;
		}
		if ( n % 2 == 0 )
		{
			sum = a[2];
			i = 4;
		}
		else
		{
			sum = a[1] + a[2] + a[3];
			i = 5;
		}
		while ( i <= n )
		{
			if ( a[i] + 2*a[2] + a[1] < 2*a[1]+a[i]+a[i-1] )
				sum += a[i] + 2*a[2] + a[1];
			else
				sum += 2*a[1]+a[i]+a[i-1];
			i+=2;
		}
		printf("%d\n",sum);
		tcase--;
	}
	return 0;
}