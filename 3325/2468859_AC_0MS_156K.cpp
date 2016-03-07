#include <iostream>
using namespace std;
int main ()
{
	int n,i;
	int min,max,d;
	int sum;
	while ( scanf("%d",&n) && n!= 0 )
	{
		sum = 0;
		min = 20000;
		max = 0;
		for ( i = 0; i < n; i++ )
		{
			scanf("%d",&d);
			sum +=d;
			if ( d < min )
				min = d;
			if ( d > max )
				max = d;
		}
		sum -= (min+max);
		sum /= (n-2);
		printf("%d\n",sum);
	}
	return 0;
}

