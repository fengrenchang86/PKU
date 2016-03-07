#include <iostream>
using namespace std;
int main ()
{
	int n,m;
	int i,j,k;
	cin>>n>>m;
	int **a = new int*[n+1];
	for ( i = 0; i <= n; i++ )
		a[i] = new int[n+1];
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
		for ( j = 1; j <= n; j++ )
			if ( a[j][i] == 1 )
			for ( k = 1; k <= n; k++ )
				if ( a[j][i] && a[i][k] )
					a[j][k] = 1;
	k = 0;
/*	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= n; j++ )
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
*/	for ( j = 1; j <= n; j++ )
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
	return 0;
}