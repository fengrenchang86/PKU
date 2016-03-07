#include <iostream.h>
void main ()
{
	int x[200];
	int y[200];
	double k[2000];
	int m[2000];
	double h;
	int i;
	for ( i = 0; i < 2000;i++ )
		m[i] = 0;
	int j;
	int f;
	int c = 0;
	int p;
	int n;
	cin>>n;
	for ( p = 0; p < n; p++ )
	{
		cin>>x[p]>>y[p];
	}
	for ( i = 0; i < p-1; i++ )
	{
		for ( j = i+1; j < p; j++ )
		{
			h = (y[j]-y[i])/(x[j]-x[i]);
			for ( f = 0; f < c; f++ )
			{
				if ( h == k[f] )
				{
					m[i]++;
					break;
				}
			}
			if ( f == c )
			{
				k[c] = h;
				m[c++]++;
			}				
		}
	}
	j = m[0];
	for ( i = 0; i < c; i++ )
	{
		if ( m[i] > j )
			j = m[i];
	}
	cout<<j<<endl;
}