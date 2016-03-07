#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int p;
	int t;
	int s;
}a[102];
int cmp( const void *a , const void *b ) 
{
	return (*(ac *)a).t - (*(ac *)b).t;


}
void amp ()
{
	int i,j;
	int n = 10;
	for ( i = 0; i < n; i++ )
		for ( j = 0; j < 100; j++ )
			n = 10;

}



int main ()
{
	int v[102];
	int c[102];
	int n,k,t;
	int i,j;
	scanf("%d%d%d",&n,&k,&t);
//	cin>>n>>k>>t;
	memset(c,0,sizeof(c));
	memset(v,0,sizeof(v));
	a[0].t = a[0].p = a[0].s = -1;
	for ( i = 1; i <= n; i++ )
		scanf("%d",&a[i].t);
//		cin>>a[i].t;
	for ( i = 1; i <= n; i++ )
		scanf("%d",&a[i].p;
//		cin>>a[i].p;
	for ( i = 1; i <= n; i++ )
		scanf("%d",&a[i].s;
//		cin>>a[i].s;
	qsort(a,n+1,sizeof(a[0]),cmp);


	a[0].t = a[0].p = a[0].s = 0;
	c[0] = 0;
	v[0] = 1;
	for ( i = 1; i <= n; i++ )
	{
		if ( a[i].t == 0 && a[i].s != 0 )
			continue;
		for ( j = 0; j < i; j++ )
		{
			if ( a[i].t-a[j].t >= abs(a[i].s-a[j].s) && v[j] == 1 )
			{
				if ( c[i] < c[j]+a[i].p )
				{
					c[i] = c[j]+a[i].p;
					v[i] = 1;
				}
			}
		}
	}
	j = 1;
	for ( i = 2; i <= n; i++ )
	{
		if ( c[i] > c[j] )
			j = i;
	}
	printf("%d\n",c[j]);
	return 0;
}