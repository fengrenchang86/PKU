#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
	fstream fin("file.txt");
	int n,m;
	int *a = new int[120];
	int *b = new int[120];
	int *c;
	int v[120][120];
	int h[120][120];
	int i,j,k;
	int max;
	while ( fin>>n>>m && !(m==0&&n==0))
	{
		for ( i = 1; i <= n; i++ )
		{
			for ( j = 1; j <= n; j++ )
				fin>>v[i][j];
		}
		for ( i = 1; i <= m; i++ )
		{
			for ( j = 1; j <= n; j++ )
				fin>>h[i][j];
		}
		for ( i = 1; i <= n; i++ )
			a[i] = h[1][i] - v[1][i];
		for ( i = 2; i <= m; i++ )
		{
			for ( j = 1; j <= n; j++ )
			{
				max = -99999;
				for ( k = 1; k <= n; k++ )
				{
					if ( a[k] + h[i][j] - v[k][j] > max )
						max = a[k] + h[i][j] - v[k][j];
				}
				b[j] = max ;
			}
			c = b;
			b = a;
			a = c;
		}
		max = -99999;
		for ( i = 1; i <= n; i++ )
		{
			if ( max < a[i] )
				max = a[i];
		}
		cout<<max<<endl;
	}
	return 0;
}