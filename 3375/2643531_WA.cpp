#include <iostream>
#include <stdlib.h>
using namespace std;
int a[110000];
int b[2100];
int f[2100];
int c[2][110000];
int min ( int x, int y )
{
	return x<y?x:y;
}
int max ( int x, int y )
{
	return x>y?x:y;
}
int cmp ( const void*a, const void*b )
{
	return *(int*)a-*(int*)b;
}
int find ( int begin, int end, int x )
{
	if ( begin == end )
		return begin;
	if ( x > a[(begin+end)/2] )
		return find((begin+end)/2+1,end,x);
	else
		return find(begin,(begin+end)/2,x);
}
int main ()
{
	int m,n,i,j;
	scanf("%d%d",&m,&n);
	for ( i = 0; i < m; i++ )
		scanf("%d",&a[i]);
	for ( i = 0; i < n; i++ )
		scanf("%d",&b[i]);
	qsort(a,m,sizeof(a[0]),cmp);
	qsort(b,n,sizeof(b[0]),cmp);
	for ( i = 0; i < n; i++ )
		f[i] = find(0,m-1,b[i]);
	c[0][0] = abs(a[0]-b[0]);
	for ( i = 1; i < min(m,f[0]+n+1); i++ )
		c[0][i] = min(c[0][i-1],abs(b[0]-a[i]));
	j = 1;
	for ( i = 1; i < n; i++ )
	{
		c[i%2][i] = c[(i-1)%2][i-1]+abs(a[i]-b[i]);
		if ( f[i]-n-1 > i+1 )
		{
			j = f[i]-n-1;
			c[i%2][j-1] = c[i%2][i];
		}
		else
			j = i+1;
		for (; j < min(m,f[i]+n+1);j++ )
		{
			c[i%2][j] = min(c[i%2][j-1],c[(i-1)%2][j-1]+abs(b[i]-a[j]));
		}
	}
	printf("%d\n",c[(i-1)%2][j-1]);
	return 0;
}