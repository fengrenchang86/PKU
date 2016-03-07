#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
int a[1200][2];
double k[1000100];
int x[1200];
int f ( int x )
{
	int y = sqrt(1+8*x);
	return (1+y)/2;
}
int cmp ( const void *a , const void *b ) 
{ 
	return *(double *)a > *(double *)b ? 1:-1; 
} 
int vvv ( const void *a , const void *b ) 
{ 
     return *(int *)a - *(int *)b; 
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
		if( end > 1 )
			qsort(k,end,sizeof(k[0]),cmp);
		if ( e > 1 )
			qsort(x,e,sizeof(x[0]),vvv);
		c = 1;
		for ( i = 0; i < end-1; i++ )
		{
			if ( f(k[i+1]-k[i]) <= 0.000001 )
			{
				c++;
				if ( c > max )
					max = c;
			}
			else
				c = 1;
		}
		c = 1;
		for ( i = 0; i < e-1; i++ )
		{
			if ( x[i]==x[i+1] )
			{
				c++;
				if ( c > max )
					max = c;
			}
			else
				c = 1;
		}
		max = f(max);
		printf("%d\n",max);
	}
	return 0;
}