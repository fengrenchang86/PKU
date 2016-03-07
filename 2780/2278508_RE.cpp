#include <iostream>
#include <stdlib.h>
using namespace std;
int a[1200][2];
double k[1000100];
int x[1200];
double fabs(double a)
{
	if( a > 0 )
		return a;
	else
		return -a;
}
int cmp ( const void *a , const void *b ) 
{ 
     return *(double *)a - *(double *)b; 
} 
int main ()
{
	int i,j,n;
	int end,e;
	int max;
	int c;
	while ( scanf("%d",&n) != EOF )
	{
		max = 1;
		end = 0;
		e = 0;
		for ( i = 0; i < n; i++ )
			scanf("%d%d",&a[i][0],&a[i][1]);
		for ( i = 0; i < n-1; i++ )
		{
			for ( j = i+1; j < n; j++ )
			{
				if ( a[i][0] == a[j][0] )
				{
					x[e++] = a[i][0];
				}
				else
				{
					k[end] = double(a[i][1]-a[j][1])/double(a[i][0]-a[j][0]);
					end++;
				}
			}
		}
		qsort(k,end-1,sizeof(k[0]),cmp);
		if ( e > 0 )
			qsort(x,e-1,sizeof(x[0]),cmp);
		c = 2;
		for ( i = 0; i < end-1; i++ )
		{
			if ( fabs(k[i]-k[i+1]) <= 0.0000000001 )
			{
				c++;
				if ( c > max )
					max = c;
			}
			else
				c = 1;
		}
		c = 2;
		for ( i = 0; i < e-1; i++ )
		{
			if ( fabs(x[i]-x[i+1]) <= 0.0000000001 )
			{
				c++;
				if ( c > max )
					max = c;
			}
			else
				c = 1;
		}
		printf("%d\n",max);
	}
	return 0;
}