#include <iostream.h>
void main ()
{
	char a[30];
	char b[30];
	int m1 = 0, c1 = 0, x1 = 0, i1 = 0;
	int m2 = 0, c2 = 0, x2 = 0, i2 = 0;
	int sum;
	int i,n;
	int t = 0;
	int j;
	int k;
	cin>>n;
	for ( i = 0; i < n; i++ )
	{
		m1 = 0;
		c1 = 0;
		x1 = 0;
		i1 = 0;
		m2 = 0;
		c2 = 0;
		x2 = 0;
		i2 = 0;
		cin>>a>>b;
		for ( j = 0; a[j] != NULL; j++ )
		{
			if ( a[j] == 'm' )
			{
				if ( a[j-1] > '1' && a[j-1] <='9')
					m1 = a[j-1] - '0';
				else
					m1 = 1;
			}
			else if (a[j] == 'c' )
			{
				if ( a[j-1] > '1' && a[j-1] <='9')
					c1 = a[j-1] - '0';
				else
					c1 = 1;
			}
			else if (a[j] == 'x' )
			{
				if ( a[j-1] > '1' && a[j-1] <='9')
					x1 = a[j-1] - '0';
				else
					x1 = 1;
			}
			else if ( a[j] == 'i' )
			{
				if ( a[j-1] > '1' && a[j-1] <='9')
					i1 = a[j-1] - '0';
				else
					i1 = 1;
			}
		}
		
		for ( j = 0; b[j] != NULL; j++ )
		{
			if ( b[j] == 'm' )
			{
				if ( b[j-1] > '1' && b[j-1] <= '9' )
					m2 = b[j-1] - '0';
				else
					m2 = 1;
			}
			else if (b[j] == 'c' )
			{
				if ( b[j-1] > '1' && b[j-1] <= '9' )
					c2 = b[j-1] - '0';
				else
					c2 = 1;
			}
			else if (b[j] == 'x' )
			{
				if ( b[j-1] > '1' && b[j-1] <= '9' )
					x2 = b[j-1] - '0';
				else
					x2 = 1;
			}
			else if ( b[j] == 'i' )
			{
				if ( b[j-1] > '1' && b[j-1] <= '9' )
					i2 = b[j-1] - '0';
				else
					i2 = 1;
			}
		}
	
		sum = (m1+m2)*1000 + (c1+c2)*100 + (x1+x2)*10 + i1+i2;
		m1 = sum/1000;
		sum = sum - sum/1000*1000;
		c1 = sum / 100;
		sum = sum - sum/100*100;
		x1 = sum / 10;
		sum = sum - sum/10*10;
		i1 = sum;
		if ( m1 == 1 )
			cout<<'m';
		else if ( m1 > 1 )
			cout<<m1<<'m';
		if ( c1 == 1 )
			cout<<'c';
		else if ( c1 > 1 )
			cout<<c1<<'c';
		if ( x1 == 1 )
			cout<<'x';
		else if ( x1 > 1 )
			cout<<x1<<'x';
		if ( i1 == 1 )
			cout<<'i';
		else if ( i1 > 1 )
			cout<<i1<<'i';
		cout<<endl;
	}
}