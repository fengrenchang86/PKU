
#include <iostream.h>
void main ()
{
	int i;
	int n;
	char a[500];
	char b[500];
	int c[500];
	int j;
	int s1;
	int s2;
	cin>>n;
	for ( j = 0; j < n; j++ )
	{
		cin>>a>>b;
		i = 0;
		while ( a[i] != NULL )
			i++;
		s1 = i-1;
		i = 0;
		while ( b[i] != NULL )
			i++;
		s2 = i-1;
		i = 0;
		while ( s1!=0||s2!=0)
		{
			c[i++] = a[s1]+b[s2]-'0'-'0';
			if ( s1 == 0 )
				a[0] = '0';
			if ( s2 == 0 )
				b[0] = '0';
			if ( s1 > 0 )
				s1--;
			if ( s2 > 0 )
				s2--;
		}
		c[i++] = a[0] + b[0] - '0' - '0';
		s1 = i;
		c[i] = 0;
		i = 0;
		while ( i < s1 )
		{
			while ( c[i] >= 10 )
			{
				c[i]-=10;
				c[i+1]++;
			}
			i++;
		}
		while ( c[s1] == 0 )
			s1--;
		for ( i = s1; i >= 0; i-- )
			cout<<c[i];
		cout<<endl;
	}
}