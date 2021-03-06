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
int min( int x, int y, int z )
{
	return min(min(x,y),min(y,z));
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
	int m,n,i,j,k;
	while ( scanf("%d%d",&m,&n) )
	{
	for ( i = 0; i < m; i++ )
	{
		scanf("%d",&a[i]);
//		a[i] = rand()%200;
	}
	for ( i = 0; i < n; i++ )
	{
			scanf("%d",&b[i]);
//		b[i] = rand()%200;
	}
	qsort(a,m,sizeof(a[0]),cmp);
	qsort(b,n,sizeof(b[0]),cmp);
	printf("after sorting:\n");
//	for ( i = 0; i < m; i++ )
//		printf("%4d ",a[i]);
//	printf("\n");
//	for ( i = 0; i < n; i++ )
//		printf("%4d ",b[i]);
//	printf("\n");
	for ( i = 0; i < n; i++ )
		f[i] = find(0,m-1,b[i]);
	c[0][0] = abs(a[0]-b[0]);
	i = 1;
	for ( i = 1; i < m; i++ )
		c[0][i] = min(c[0][i-1],abs(b[0]-a[i]));
	j = i;
	for ( i = 1; i < n; i++ )
	{
		c[i%2][i] = c[(i-1)%2][i-1]+abs(a[i]-b[i]);
		if ( f[i]-n-3 > i+1 )
		{
			j = f[i]-n-3;
			c[i%2][j-1] = c[(i-1)%2][j-2]+abs(b[i]-a[j-1]);
		}
		else
			j = i+1;
		if ( i == n-1 )
			k = min(m,f[i]+n+3);
		else
			k = min(m,f[i+1]+n+3);
		for (; j < f[i]+n+3;j++ )
		{
			c[i%2][j] = min(c[i%2][j-1],c[(i-1)%2][j-1]+abs(b[i]-a[j]));
		}
		while ( j < k )
		{
			c[i%2][j] = c[i%2][j-1];
			j++;
		}
	}
	printf("%d\n",c[(i-1)%2][j-1]);
	}
	return 0;
}