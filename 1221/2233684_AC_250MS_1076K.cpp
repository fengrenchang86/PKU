#include <iostream>
using namespace std;
const int max = 500;
int main ()
{
	int a[max][max];
	int b[max];
	int c[max];
	int i,j,k;
	_int64 sum;
	for ( i = 0; i < max; i++ )
	{
		for ( j = 0; j < max; j++ )
			if ( i != j )
				a[i][j] = 0;
			else
				a[i][j] = 1;
	}
	for ( i = 2; i < max; i++ )
	{
		for ( j = i-1; j >= 1; j-- )
		{
			k = j;
			for ( ; k >= 1; k-- )
				a[i][j] += a[i-j][k];
		}
	}
	for ( i = 1; i < max; i++ )
	{
		b[i] = 0;
		for ( j = 1; j <= i; j++ )
			b[i] += a[i][j];
	}
	b[1] = 1;
	while ( cin>>k && k != 0 )
	{
		if ( k % 2 == 0 )
		{
			sum = b[k/2] + 1;
			i = 2;
		}
		else
		{
			sum = 1;
			i = 1;
		}
		while ( (k-i)/2 >= 1 )
		{
			for ( j = 1; j <= i; j++ )
				sum += a[(k-i)/2][j];
			i += 2;
		}
		printf("%d ",k);
		printf("%I64d\n",sum);
	}
	return 0;
}