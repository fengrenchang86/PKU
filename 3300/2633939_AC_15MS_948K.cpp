#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp( const void *a , const void *b ) 
{ 
    return *(double *)a > *(double *)b ? 1 : -1; 
}
int main ()
{
	int m,n,i,j,k;
	double t;
	int a[20],b[20];
	double c[100100];
	while ( cin>>m )
	{
		if ( m == 0 )
			break;
		cin>>n;
		for ( i = 0; i < m; i++ )
			cin>>a[i];
		for ( i = 0; i < n; i++ )
			cin>>b[i];
		k = 0;
		for ( i = 0; i < m; i++ )
		{
			for ( j = 0; j < n; j++ )
				c[k++] = double(b[j])/double(a[i]);
		}
		qsort(c,k,sizeof(c[0]),cmp);
		t = 0;
		for ( i = 1; i < k; i++ )
		{
			if ( c[i]/c[i-1] > t )
				t = double(c[i])/double(c[i-1]);
		}
		printf("%.2lf\n",t);
	}
	return 0;
}
