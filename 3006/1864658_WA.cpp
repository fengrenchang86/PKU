#include <iostream.h>
#include <math.h>

void main ()
{
	int a;
	int d;
	int n;
	int i;
	int c;
	int k;
	int j;
	int sum = 0;
	while ( cin>>a>>d>>n && !(a==0 && d==0 && n==0 ) )
	{
		sum = a;
		c = 0;
		for ( i = a; c < n; i += d )
		{
			k = 1;
			for ( j = 2; j <= sqrt(i)+3; j++ )
			{
				if ( i%j == 0 )
				{
					k = 0;
					break;
				}
			}
			c+=k;
			sum += d;
		}
		sum -= d;
		if ( sum == 1 )
			sum++;
		cout<<sum<<endl;
	}
}