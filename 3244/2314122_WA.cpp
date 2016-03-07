#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp ( const void *a , const void *b ) 
{ 
     return *(int *)b - *(int *)a; 
} 
_int64 u[200100];
_int64 v[200100];
_int64 w[200100];
int main ()
{
	int n,i;
	int a,b,c;
	_int64 sum = 0;
	while ( scanf("%d",&n) && n!=0 )
	{
		sum = 0;
		for( i = 0; i < n; i++ )
		{
			scanf("%d%d%d",&a,&b,&c);
			u[i] = a-b;
			v[i] = b-c;
			w[i] = c-a;
		}
		qsort(u,n,sizeof(u[0]),cmp);
		qsort(v,n,sizeof(v[0]),cmp);
		qsort(w,n,sizeof(w[0]),cmp);
		for ( i = 0; i < n; i++ )
			sum += (n-1-2*i)*(u[i]+v[i]+w[i])/2;
		printf("%I64d\n",sum);
	}
	return 0;
}
