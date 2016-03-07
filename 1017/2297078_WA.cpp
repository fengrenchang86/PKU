#include <iostream>
using namespace std;
int a[7];
int v[7][7];
int count,s;
void init ()
{
	int i,j;
	for ( i = 1; i <= 6; i++ )
	{
		for ( j = 1; j <= 6; j++ )
			v[i][j] = 0;
	}
	s = 64;
}
int find ( int x, int y, int k )
{
	int i,j;
	if ( x+k-1 > 6 || y+k-1 > 6 )
		return 0;
	for ( i = x; i <= x+k-1; i++ )
	{
		for ( j = y; j<= y+k-1; j++ )
		{
			if ( v[i][j] == 1 )
				return 0;
		}
	}
	for ( i = x; i <= x+k-1; i++ )
	{
		for ( j = y; j<= y+k-1; j++ )
		{
			v[i][j] = 1;
		}
	}
	s -= k*k;
	a[k]--;
	count--;
	return 1;
}
int main ()
{
	int i,j,p;
	int c;
	int f;
	while ( cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6] )
	{
		count = a[1]+a[2]+a[3]+a[4]+a[5];
		if( count == 0 )
			break;
		c = a[6];
		while ( count > 0 )
		{
			p = 5;
			init();
			while ( p > 0 )
			{
				if ( a[p] > 0 && s > p*p)
				{
					f = 0;
					for ( i = 1; i <= 6; i++ )
					{
						for ( j = 1; j <= 6; j++ )
						{
							f = find(i,j,p);
							if ( f == 1 )
								break;
						}
						if ( f == 1 )
							break;
					}
					if ( f == 0 )
						p--;
				}
				else
					p--;
			}
			c++;
		}
		cout<<c<<endl;
	}
	return 0;
}