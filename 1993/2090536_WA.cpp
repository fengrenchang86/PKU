#include <iostream>
using namespace std;

int main ()
{
	int a[120][120]={0};
	int b[120][120]={0};
	int c[120][120]={0};
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
				scanf("%d",&a[i][j]);
		for ( ix = 1; ix < x; ix++ )
		{
			scanf("%d%d",&n,&p);
			for ( i = 0; i < n; i++ )
				for ( j = 0; j < p;j++ )
					scanf("%d",&b[i][j]);
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
			for ( j = 0; j < p-1; j++ )
				printf("%d ",a[i][j]);
			printf("%d\n",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
