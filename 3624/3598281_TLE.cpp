#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int w,d;
}a[4000];
int sum[4000];
int wei[4000];
int rec[20000];
int n,m,ans=0;
int cmp ( const void*a, const void*b )
{
	struct ac*c = (ac*)a;
	struct ac*e = (ac*)b;
	return e->w - c->w;
}
void dfs ( int lay ,int weight, int k )
{
	rec[weight] = k;
	if ( k > ans )
		ans = k;
	if ( lay == n )
		return;
	if ( k + sum[lay] <= ans )
		return;
	else if ( weight+wei[lay] <= m )
	{
		ans = k+sum[lay];
		return;
	}
	if ( weight+a[lay].w <= m /*&& rec[weight+a[lay].w] <= k+a[lay].d*/ )
		dfs(lay+1,weight+a[lay].w,k+a[lay].d);
	dfs(lay+1,weight,k);
}
int main ()
{
	int i;
	for ( i = 0; i < 13000; i++ )
		rec[i] = -1;
	scanf("%d%d",&n,&m);
	for ( i = 0; i < n; i++ )
		scanf("%d%d",&a[i].w,&a[i].d);
	qsort(a,n,sizeof(a[0]),cmp);
	sum[n] = 0;
	wei[n] = 0;
	for ( i = n-1; i >= 0; i-- )
	{
		sum[i] = sum[i+1]+a[i].d;
		wei[i] = wei[i+1]+a[i].w;
	}
	dfs(0,0,0);
	printf("%d\n",ans);
	return 0;
}