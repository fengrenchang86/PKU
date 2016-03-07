#include <iostream>
using namespace std;
const short max = 100;
int main ()
{
	unsigned short c[max][max];
	unsigned short a[max];
	unsigned short X[max];
	unsigned short Y[max];
	int t,n;
	int min = 65534;
	int it;
	int i,j;
	int x,y,distance;
	cin>>t>>n;
	for ( i = 0; i <= n; i++ )
		for ( j = 0; j <= n; j++ )
			c[i][j] = 65534;
	for ( i = 0; i < max; i++ )
		a[i] = 65534;
	a[1] = 0;
	for ( it = 0; it < t; it++ )
	{
		scanf("%d%d%d",&x,&y,&distance);
		c[x][y] = distance;
	}
	for ( i = 1; i <= n; i++ )
	{
		if ( c[1][i] < a[i] )
			a[i] = c[1][i];
	}
	for ( i = 1; i <= n; i++ )
	{
		Y[i] = 1;
		X[i] = 0;
	}
	Y[1] = 0;
	short position;
	for ( j = 1; j<=n-1; j++ )
	{
		min = 65534;
		for ( i = 2; i <= n; i++ )
		{
			if ( Y[i] == 1 && a[i] < min )
			{
				position = i;
				min = a[i];
			}
		}
		Y[position] = 0;
		for ( i = 2; i <= n; i++ )
		{
			if ( Y[i] == 1 && a[position] + c[position][i] < a[i] )
				a[i] = a[position] + c[position][i];
		}
	}
	cout<<a[n]<<endl;
	return 0;
}