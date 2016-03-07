#include <iostream>
using namespace std;
int main ()
{
	double a[101][101]={0};
	double b[101][101]={0};
	double c[101][101]={0};
	int x,ix;
	int m,n,p;
	int tcase,it;
	int i,j,k;
	scanf("%d",&tcase);
	for ( it = 0; it < tcase; it++ )
	{
		scanf("%d",&x);
		scanf("%d%d",&m,&n);
			for ( i = 0; i < m; i++ )
				for ( j = 0; j < n;j++ )
					scanf("%lf",&a[i][j]);
		for ( ix = 1; ix < x; ix++ )
		{
			scanf("%d%d",&n,&p);
			for ( i = 0; i < n; i++ )
				for ( j = 0; j < p;j++ )
					scanf("%lf",&b[i][j]);
			for ( i = 0; i < m; i++ )
			{
				for ( j = 0;j < p; j++ )
				{
					for ( k = 0; k < n; k++ )
						c[i][j] += a[i][k]*b[k][j];
				}
			}
			for ( i = 0; i < m; i++ )
				for ( j = 0; j < p; j++ )
					a[i][j] = c[i][j];
			memset(c,0,sizeof(c));		
		}
		for ( i = 0; i < m; i++ )
		{
			for ( j = 0; j < p; j++ )
				printf("%.0lf ",a[i][j]);
			printf("\n");
		}
		printf("\n");

	}
	return 0;
}