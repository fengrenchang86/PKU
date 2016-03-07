#include <iostream>
using namespace std;
int main ()
{
	int tcase,it;
	int m,n,p;
	int i,j,k;
	int x,ix;
	cin>>tcase;
	for ( it = 0; it < tcase; it++ )
	{
		int a[120][120];
		int b[120][120];
		int c[120][120];
		scanf("%d",&x);
		scanf("%d%d",&m,&n);
		for ( i = 0; i < m; i++ )
			for ( j = 0; j < n; j++ )
				scanf("%d",&a[i][j]);
		for ( ix = 1; ix < x; ix++ )
		{
			scanf("%d%d",&n,&p);
			for ( i = 0; i < n; i++ )
				for ( j =0 ; j < p; j++ )
					scanf("%d",&b[i][j]);
			for ( i = 0; i < m; i++ )
			{
				for ( j = 0; j < p; j++ )
				{
					c[i][j] = 0;
					for ( k = 0; k < n; k++ )
						c[i][j] += a[i][k]*b[k][j];
				}
			}
			for ( i = 0; i < m; i++ )
				for ( j = 0; j < p; j++ )
					a[i][j] = c[i][j];
		}
		for ( i = 0; i < m; i++ )
		{
			printf("%d",a[i][0]);
			for ( j = 1; j < p; j++ )
				printf(" %d",a[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}