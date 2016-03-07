#include <iostream>
using namespace std;

long double f( unsigned int a[][4] )
{
	long double d = a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1])
		-a[0][1]*(a[1][0]*a[2][2]-a[1][2]*a[2][0])
		+a[0][2]*(a[1][0]*a[2][1]-a[1][1]*a[2][0]);
	return d;
}
long double change ( unsigned int a[][4], unsigned int b[], int k,bool q )
{
	unsigned int c[3];
	int i;
	for ( i = 0; i < 3; i++ )
	{
		c[i] = a[i][k];
		if ( q == true)
			a[i][k] = b[i];
	}
	double g = f(a);
	for ( i = 0; i < 3; i++ )
		a[i][k] = c[i];
	return g;
}
int main ()
{
	int n;
	unsigned int a[3][4];
	unsigned int b[3];
	long double ans[4];
	scanf("%d",&n);
	int i;
	int j , k;
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j< 3; j++ )
		{
			for ( k = 0; k < 4; k++ )
				scanf("%d",&a[j][k]);
		}
		b[0] = a[0][3];
		b[1] = a[1][3];
		b[2] = a[2][3];
		for ( j = 0; j < 3; j++ )
		{
			ans[j] = change(a,b,j,true);
			printf("%.0lf ",ans[j]);
		}
		ans[3] = change(a,b,j,false);
		printf("%.0lf",ans[3]);
		printf("\n");
		if ( ans[3] == 0 )
			printf("No unique solution\n");
		else
		{
			for ( j = 0; j < 3; j++ )
			{
				ans[j] = ans[j]/ans[3];
				if ( ans[j] < 0.0005 && ans[j] > -0.0005  )
					ans[j] = 0;
			}
			printf("Unique solution:");
			for ( j = 0; j < 3; j++ )
				printf(" %0.3lf",ans[j]);
			printf("\n");
		}
		if ( i != n-1 )
		printf("\n");
	}
	return 1;
}