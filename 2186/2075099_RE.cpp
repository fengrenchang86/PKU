#include <iostream>
using namespace std;
int main ()
{
	char a[11000][11000];
	int n,m;
	int i,j,k;
	while ( scanf("%d%d",&n,&m) != EOF )
	{
	for ( i = 1; i <= n;i++ )
		for (j  = 1; j <= n; j++ )
		{
			if ( i == j )
				a[i][j] = 1;
			else
				a[i][j] = 0;
		}
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d",&j,&k);
		a[j][k] = 1;
	}
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= n; j++ )
		{
			if ( a[j][i] == 1 )
			{
				for ( k = 1; k <= n; k++ )
				{
					if ( a[i][k]==1 )
						a[j][k] = 1;
				}
			}
		}
	}
	k = 0;
	for ( j = 1; j <= n; j++ )
	{
		for ( i = 1; i <= n; i++ )
		{
			if ( a[i][j] == 0 )
				break;
		}
		if ( i == n+1 )
			k++;
	}
	cout<<k<<endl;
	}
	return 0;
}