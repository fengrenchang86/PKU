#include <iostream>
using namespace std;
int c[120][120];
int a[120];
int main ()
{
	int min(int,int);
	int n,i,j,k;
	while ( scanf("%d",&n) != EOF )
	{
		for ( i = 1; i <= n; i++ )
			scanf("%d",&a[i]);
		for ( i = 1; i < n; i++ )
			c[i][i+1] = 0;
		for ( i = 2; i < n; i++ )
			c[i-1][i+1] = a[i-1]*a[i]*a[i+1];
		for ( j = 3; j < n; j++ )
		{
			for ( i=1;i+j <= n; i++ )
			{
				c[i][i+j] = 2000000000;
				for ( k = i+1; k < i+j; k++ )
					c[i][i+j] = min(c[i][i+j],c[i][k]+c[k][i+j]+a[i]*a[k]*a[i+j]);
			}
		}
		cout<<c[1][n]<<endl;
	}
	return 0;
}
int min ( int x, int y )
{
	return x<y?x:y;
}