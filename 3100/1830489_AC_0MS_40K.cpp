#include <iostream.h>
void main ()
{
	int chengfang ( int , int );
	int m;
	int n;
	int i;
	int temp;
	int min;
	while ( 1 )
	{
		cin>>m>>n;
		if ( m == 0 && n == 0 )
			break;
		for ( i = 1; ; i++ )
		{
			temp = chengfang ( i, n );
			if ( m <= temp )
				break;
		}
		min = temp - m;
		temp = chengfang( i-1, n );
		temp = m - temp;
		if ( min > temp )
		{
			temp = min;
			i = i-1;
		}
		cout<<i<<endl;
	}

}

int chengfang ( int p, int n )
{
	int i;
	int result = 1;
	for ( i = 0; i < n; i++ )
		result *= p;
	return result;
}