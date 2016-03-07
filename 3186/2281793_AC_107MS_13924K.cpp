#include <iostream>
using namespace std;
int a[2002][2002];
int v[2002];
int main ()
{
	int i,j,n;
	scanf("%d",&n);
	for ( i = 1; i <= n;i++ )
		scanf("%d",&v[i]);
	a[1][n] = 0;
	for ( i = 2; i <= n; i++ )
	{
		a[i][n] = a[i-1][n] + (i-1)*v[i-1];
		a[1][n-i+1] = a[1][n-i+2] + (i-1)*v[n-i+2];
	}
	for ( i = 2; i < n; i++ )
	{
		for ( j = n-1; j >= i; j-- )
		{
			if ( a[i-1][j] + v[i-1]*(i-1+n-j) > a[i][j+1] + v[j+1]*(i-1+n-j) )
				a[i][j] = a[i-1][j] + v[i-1]*(i-1+n-j);
			else
				a[i][j] = a[i][j+1] + v[j+1]*(i-1+n-j);
		}
	}
	j = 0;
	for ( i = 1; i <= n; i++ )
	{
		if ( a[i][i]+n*v[i] > j )
			j = a[i][i]+n*v[i];
	}
	printf("%d\n",j);
	return 0;
}
