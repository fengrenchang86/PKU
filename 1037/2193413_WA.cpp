#include <iostream>
#include <fstream>
using namespace std;
_int64 a[21][21][2];
_int64 b[21];
int v[21];
int pre;
int main ()
{
//	fstream cin("in.txt");
	a[1][1][0] = 1;
	a[1][1][1] = 1;
	a[2][1][0] = 0;
	a[2][1][1] = 1;
	a[2][2][0] = 1;
	a[2][2][1] = 0;
	int i,j,k;
	for ( i = 3; i <= 20; i++ )//length
	{
		for ( j = 1; j <= i; j++ )//the first dig
		{
			a[i][j][0] = 0;
			a[i][j][1] = 0;
			for ( k = 1; k <= i; k++ )
			{
				if ( k > j )
					a[i][j][1] += a[i-1][k-1][0];
				else if ( k < j )
					a[i][j][0] += a[i-1][k][1];
			}
		}
	}
	for ( i = 1; i <= 20; i++ )
	{
		b[i] = 0;
		for ( j = 1; j <= i; j++ )
			b[i] += (a[i][j][0]+a[i][j][1]);
	}
	void print(int k);
	void h(int &c, int j, int &g);
	int tcase,it;
	int n,c;
	int f(int &c, int j);
	cin>>tcase;
	int up;
	for ( it = 0; it < tcase; it++ )
	{
		memset(v,0,sizeof(v));
		cin>>n>>c;
		up = f(c,n);
		j = n-1;
		while ( j > 0 )
		{
			h(c,j,up);
			j--;
		}
		cout<<endl;
	}
	return 0;
}
void print ( int k )
{
	int c = 0;
	int i = -1;
	while ( c < k )
	{
		i++;
		if ( v[i] == 0 )
			c++;
	}
	v[i] = 1;
	pre = i;
	printf(" %d",i);
}
void h ( int &c, int j, int &g )
{
	int i;
	if ( g == 1 )
	{
		i = pre;
		g = 0;
		while ( c > 0 && i <= j)
		{
			c -= a[j][i][0];
			i++;
		}
		if ( c <= 0 )
		{
			c += a[j][i-1][0];
		}
		print(i);
	}
	else
	{
		i = 1;
		g = 1;
		while ( c > 0 && i <= j)
		{
			c -= a[j][i][1];
			i++;
		}
		if ( c <= 0 )
		{
			c += a[j][i-1][1];
		}
		print(i);
	}
}
int f ( int &c, int j )
{
	int i = 1;
	int g;
	while ( c > 0 )
	{
		c -= a[j][i][0];
		g = 0;
		if ( c <= 0 )
			break;
		c -= a[j][i][1];
		g = 1;
		i++;
	}
	if ( g == 1 )
	{
		i--;
		c += a[j][i][1];
	}
	else
		c += a[j][i][0];
	pre = i;
	v[i] = 1;
	cout<<i;
	return g;
}
