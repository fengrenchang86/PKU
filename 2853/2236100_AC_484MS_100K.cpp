#include <iostream>
#include <math.h>
using namespace std;
int f ( int x, int y )
{
	if ( x < y )
		return 0;
	else if ( x == y && x >= 1)
		return 1;
	else if ( y < 1 )
		return 0;
	else
	{
		return f(x-y,y-1);
	}
}
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
		for ( i = 2; i <= 131072; i++ )
		{
			n = (x-(i*i-i)/2)/i;
			if ( x == (i*i-i)/2+i*n && n > 0 && n < x)
				sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}