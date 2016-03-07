#include <iostream>
using namespace std;
int main ()
{
	int tcase,it;
	int m,n,p;
	int i,j,k;
	int x,ix;
	int **a = new int*[120];
	for ( i = 0; i < 120; i++ )
		a[i] = new int[120];
	int **b = new int*[120];
	for ( i = 0; i < 120; i++ )
		b[i] = new int[120];
	int **c = new int*[120];
	for ( i = 0; i < 120; i++ )
		c[i] = new int[120];
	int **t;
	cin>>tcase;
	for ( it = 0; it < tcase; it++ )
	{
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
			t = a;
			a = c;
			c = t;
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