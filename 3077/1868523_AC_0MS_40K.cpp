#include <iostream.h>

int power ( int a ,int b )
{
	int sum = 1;
	int i = 0;
	while ( i < b )
		sum*=a;
	return sum;
}
void main ()
{
	int n;
	int k;
	int count;
	int c;
	int i;
	int j;
	cin>>n;
	for ( j = 0; j < n; j++ )
	{
		cin>>k;
		count = 0;
		c = k;
		while ( c/10!=0 )
		{
			if ( c%10 >= 5 )
				c = c/10+1;
			else
				c = c/10;
			count++;
		}
		for ( i = 0; i < count; i++ )
			c *= 10;
		cout<<c<<endl;

	}
}