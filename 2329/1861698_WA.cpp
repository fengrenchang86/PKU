#include <iostream.h>
int a[200][200];
int f ( int i, int j , int n)
{
	int c = 0;
	int d;
	if ( i-1 >= 0 )
	{
		if ( j-1 >= 0 )
		{
			if ( a[i-1][j-1] != 0 )
			{
				c++;
				d = a[i-1][j-1];
			}
		}
		if ( j+1 < n )
		{
			if ( a[i-1][j+1] != 0 )
			{
				c++;
				d = a[i-1][j+1];
			}
		}
		if ( a[i-1][j] != 0 )
		{
			c++;
			d = a[i-1][j];
		}
	}
	if ( i+1 < n )
	{
		if ( j-1 >= 0 )
		{
			if ( a[i+1][j-1] != 0 )
			{
				c++;
				d = a[i+1][j-1];
			}
		}
		if ( j+1 < n )
		{
			if ( a[i+1][j+1] != 0 )
			{
				c++;
				d = a[i+1][j+1];
			}
		}
		if ( a[i+1][j] != 0 )
		{
			c++;
			d = a[i+1][j];
		}
	}
	if ( j-1 >= 0 )
	{
		if ( a[i][j-1] != 0 )
		{
			c++;
			d = a[i][j-1];
		}
	}
	if ( j+1 < n )
	{
		if ( a[i][j+1] != 0 )
		{
			c++;
			d = a[i][j+1];
		}
	}
	if ( c == 1 )
		return d;
	else 
		return 0;
}

void main ()
{
	int n;
	int i;
	int j;
	cin>>n;
	for ( i = 0 ; i < n; i++ )
		for ( j = 0 ; j < n; j ++ )
			cin>>a[i][j];
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			if ( a[i][j] == 0 )
				a[i][j] = f(i,j,n);
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

}