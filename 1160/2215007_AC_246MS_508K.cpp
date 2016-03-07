#include <iostream>
using namespace std;
int main ()
{
	int sum[301];
	int a[301][31];
	int num[301];
	int d[301][301];
	int i,j,k,p,v;
	int min;
	scanf("%d%d",&v,&p);
	sum[0] = 0;
	for ( i = 1; i <= v; i++ )
	{
		scanf("%d",&num[i]);
		sum[i] = sum[i-1] + num[i];
		d[i][i] = 0;
	}
	if ( p == v )
	{
		cout<<0<<endl;
		return 0;
	}
	for ( i = 1; i < v; i++ )
	{
		for ( j = i+1; j <= v; j++ )
		{
			min = 99999999;
			for ( k = i; k <= j; k++ )
			{
				if ( (2*k-j-i+1)*num[k]-2*sum[k]+sum[i-1]+sum[j] < min )
					min = (2*k-j-i+1)*num[k]-2*sum[k]+sum[i-1]+sum[j];
			}
			d[i][j] = min;
		}
	}
	for ( i = 1; i <= v; i++ )
		a[i][1] = d[1][i];
	for ( j = 2; j <= p; j++ )
	{
		for ( i = j; i <= v; i++ )
		{
			min = 99999999;
			for ( k = j; k < i; k++ )
			{
				if ( a[k][j-1]+d[k+1][i] < min )
					min = a[k][j-1]+d[k+1][i];
			}
			a[i][j] = min;
		}
	}
	cout<<a[v][p]<<endl;
	return 0;
}