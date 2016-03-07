#include <iostream>
using namespace std;
int main ()
{
	int a[101010];
	int l[101010];
	int r[101010];
	int sum1,sum2;
	int max;
	int i,n;
	while ( scanf("%d",&n) && n != 0 )
	{
		for ( i = 1; i <= n; i++ )
			scanf("%d",&a[i]);
		sum1 = 0;
		sum2 = 0;
		l[0] = 0;
		r[n+1] = 0;
		max = -2000;
		for ( i = 1; i <= n-1; i++ )
		{
			sum1 += a[i];
			if ( sum1 > max )
				max = i;
			if ( sum1 < 0 )
			{
				l[i] = l[i-1];
				sum1 = 0;
			}
			else if ( a[i] > 0 )
				l[i] = sum1;
			else
				l[i] = l[i-1];
		}
		max = -2000;
		for ( i = n; i > 1; i-- )
		{
			sum2 += a[i];
			if ( sum2 > max )
				max = i;
			if ( sum2 < 0 )
			{
				r[i] = r[i+1];
				sum2 = 0;
			}
			else if ( a[i] > 0 )
				r[i] = sum2;
			else
				r[i] = r[i+1];
		}
		max = -20000000;
		for ( i = 1; i <= n-1; i++ )
		{
			if ( l[i] + r[i+1] > max )
				max = l[i] + r[i+1];
		}
		printf("%d\n",max);
	}
	return 0;
}