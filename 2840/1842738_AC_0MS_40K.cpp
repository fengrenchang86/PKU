#include <iostream.h>
void main ()
{
	int n;
	char in[30];
	int i;
	int j;
	int h;
	int m;
	cin>>n;
	for ( i = 0; i < n; i++ )
	{
		h = 0;
		m = 0;
		cin>>in;
		for ( j = 0; in[j] != ':'; j++ )
		{
			h *= 10;
			h += (in[j] - '0' );
		}
		j++;
		while ( in[j] != NULL )
		{
			m *= 10;
			m += ( in[j] - '0' );
			j++;
		}
		h += 12;
		h %= 24;
		if ( m != 0 )
		{
			cout<<0<<endl;
			continue ;
		}
		if ( h == 0 )
			cout<<24<<endl;
		else
			cout<<h<<endl;
	}
}