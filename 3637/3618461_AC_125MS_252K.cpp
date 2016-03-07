#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp ( const void*a, const void*b )
{
	return *(int*)b-*(int*)a;
}
int a[21000];
void solve ()
{
	int i,n,k=0;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(a[0]),cmp);
	for ( i = 2; i < n; i+=3 )
	{
		k+=a[i];
	}
	printf("%d\n",k);
}
int main ()
{
	int tc;
	scanf("%d",&tc);
	while ( tc-- )
		solve();
	return 0;
}