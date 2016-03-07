#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int t;
	int d;
	int v;
	double g;
	ac(){v=0;}
}a[100100];
int cmp( const void *a , const void *b ) 
{ 
   return (*(ac *)a).g > (*(ac *)b).g ? -1 : 1; 
}
int main ()
{
	int n,i,j,k=0,sum=0;
	_int64 ans = 0;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d%d",&a[i].t,&a[i].d);
		a[i].g = double(a[i].d)/double(a[i].t);
		sum += a[i].d;
	}
	qsort(a,n,sizeof(a[0]),cmp);
	for ( i = 0; i < n; i++ )
	{
		ans += (sum-a[i].d)*2*a[i].t;
		sum -= a[i].d;
	}
	printf("%I64d\n",ans);
	return 0;
}