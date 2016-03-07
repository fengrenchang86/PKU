#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	int sum;
	_int64 x,n,i;
	int tcase;
	cin>>tcase;
	while ( tcase )
	{
		tcase--;
		scanf("%I64d",&i);
		scanf("%I64d",&x);
		printf("%I64d ",i);
		sum = 0;
		for ( i = 2; i <= (sqrt(1+4*x)-1); i++ )
		{
			n = (x-(i*i-i)/2)/i;
			if ( x == (i*i-i)/2+i*n && n > 0 && n < x)
				sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}