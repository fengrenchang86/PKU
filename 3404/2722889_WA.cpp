#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp ( const void*a, const void*b )
{
	return *(int*)a-*(int*)b;
}
int min ( int x, int y )
{
	return x<y?x:y;
}
int main ()
{
	int n,i;
	int a[60],c[60];
	cin>>n;
	for ( i =0; i < n; i++ )
		cin>>a[i];
	qsort(a,n,sizeof(a[0]),cmp);
	c[0] = a[0];
	c[1] = a[0]>a[1]?a[0]:a[1];
	c[2] = a[0]+a[1]+a[2];
	c[3] = min(2*a[0]+a[1]+a[2]+a[3],a[0]+3*a[1]+a[3]);
	for ( i = 4; i < n; i++ )
	{
		c[i] = min(c[i-2]+a[0]*2+a[i-1]+a[i],c[i-1]+a[i]+a[0]);
	}
	printf("%d\n",c[n-1]);
	return 0;
}