#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp ( const void *a , const void *b ) 
{ 
     return *(int *)b - *(int *)a; 
} 
int u[200100];
int v[200100];
int w[200100];
int main ()
{
	int n,i;
	int a,b,c;
	_int64 sumu,sumv,sumw;
	_int64 sum = 0;
	while ( scanf("%d",&n) && n!=0 )
	{
		sum = 0;
		sumu = sumv = sumw = 0;
		for( i = 0; i < n; i++ )
		{
			scanf("%d%d%d",&a,&b,&c);
			u[i] = a-b;
			v[i] = b-c;
			w[i] = c-a;
			sumu += u[i];
			sumv += v[i];
			sumw += w[i];
		}
		if ( n == 1 )
		{
			if( a > b )
			{
				if ( b > c )
					sum = a+c;
				else if ( a > c )
					sum = a+b;
				else
					sum = c+b;
			}
			else
			{
				if ( c > b )
					sum = c+a;
				else if ( a > c )
					sum = b+c;
				else
					sum = a+b;
			}
			printf("%I64d\n",sum);
			continue;
		}
		qsort(u,n,sizeof(u[0]),cmp);
		for ( i = 0; i < n-1; i++ )
		{
			sum += ((n-i)*u[i]-sumu);
			sumu -= u[i];
		}
		qsort(v,n,sizeof(v[0]),cmp);
		for ( i = 0; i < n-1; i++ )
		{
			sum += ((n-i)*v[i]-sumv);
			sumv -= v[i];
		}
		qsort(w,n,sizeof(w[0]),cmp);
		for ( i = 0; i < n-1; i++ )
		{
			sum += ((n-i)*w[i]-sumw);
			sumw -= w[i];
		}
		sum /=2;
		printf("%I64d\n",sum);
	}
	return 0;
}
