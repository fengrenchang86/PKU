#include <iostream>
using namespace std;
int c[520][520];
int sum[520][520];
int path[520][520];
int a[520];
int m,n;
int funMax ( int x, int y )
{
	return x>y?x:y;
}
void init ()
{
	int i,j,k,t;
	cin>>m>>n;
	for ( i = 1; i <= m; i++ )
		scanf("%d",&a[i]);
	for ( i = 1; i <= m; i++ )
		sum[i][i] = a[i];
	for ( i = 1; i < m; i++ )
	{
		for ( j = i+1; j <= m; j++ )
			sum[i][j] = sum[i][j-1] + a[j];
	}
	c[1][1] = a[1];
	for ( i = 2; i <= m; i++ )
	{
		c[i][i] = funMax(c[i-1][i-1],a[i]);
		c[i][1] = sum[1][i];
		path[i][i] = i-1;
	}
	for ( i = 3; i <= m; i++ )
	{
		for ( j = 2; j <= n && j < i; j++ )
		{
			c[i][j] = 2000000000;
			for ( k = j-1; k < i; k++ )
			{
				t = funMax(c[k][j-1],sum[k+1][i]);
				if ( c[i][j] > t )
				{
					c[i][j] = t;
					path[i][j] = k;
				}
			}
		}
	}
	i = m;
	j = n;
	while ( j > 1 )
	{
		i = path[i][j];
		a[i] *= -1;
		j--;
	}
//	cout<<c[m][n]<<endl;
	for ( i = 1; i <= m; i++ )
	{
		if ( a[i] > 0 )
			cout<<a[i]<<" ";
		else
			cout<<-a[i]<<" / ";
	}
	cout<<endl;
}
int main ()
{
	int t,i;
	cin>>t;
	for ( i = 0; i < t; i++ )
		init();
	return 0;
}                                        