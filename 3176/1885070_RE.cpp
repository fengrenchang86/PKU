#include <iostream>
using namespace std;
int main ()
{
	short a[330][330] = {0};
	int n;
	int i;
	int j;
	int k;
	scanf("%d",&n);
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= i; j++ )
			scanf("%d",&a[i][j]);
	}
	for ( j = 2; j <= n; j++ )
		{
			for ( k = 1; k <= j; k++ )
				a[j][k] += a[j-1][k-1]>a[j-1][k]?a[j-1][k-1]:a[j-1][k];
		}
		k = 0;
		for ( j = 1; j <= n; j++ )
			if ( a[n][j] > k )
				k = a[n][j];
		cout<<k<<endl;
	return 1;
}