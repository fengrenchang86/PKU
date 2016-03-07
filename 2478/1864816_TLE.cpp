#include <iostream.h>
int z ( int m, int n )
{
	int k;
	while ( n != 0 )
	{
		k = m;
		m = n;
		n = k%n;
	}
	if ( m == 1 )
		return 1;
	else
		return 0;
}

void main ()
{
	int i;
	int j;
	int n;
	int sum;
	while ( cin>>n && n != 0 )
	{
		sum = 0;
		for ( i = 3; i <= n; i++ )
		{
			sum++;
			for ( j = 2; j <= (i-1)/2; j++ )
			{
				sum+= z ( i ,j );
			}
		}
		sum *= 2;
		sum++;
		cout<<sum<<endl;
	}
}