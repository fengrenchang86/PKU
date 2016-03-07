#include <iostream>
#include <stdlib.h>
int a[110000];
int cmp ( const void*a, const void*b )
{
	return (int*)a-(int*)b;
}
int min ( int x, int y )
{
	return x<y?x:y;
}
int main ()
{
	int b[3000];
	int c[2][110000];
	int m,n,i,j,x,sum = 0;
	memset(a,0,sizeof(a));
	scanf("%d%d",&m,&n);
	for ( i = 0; i < m; i++ )
		scanf("%d",&a[i]);
	for ( i = 0; i < n; i++ )
		scanf("%d",&b[i]);
	qsort(a,m,sizeof(b[0]),cmp);
	qsort(b,n,sizeof(b[0]),cmp);
	c[0][0] = abs(b[0]-a[0]);
	for ( j =1; j < m; j++ )
		c[0][j] = min(c[0][j-1],abs(b[0]-a[j]));
	for ( i = 1; i < n; i++ )
	{
		c[i%2][i] = c[(i-1)%2][i-1] + abs(b[i]-a[i]);
		for ( j = i+1; j < m; j++ )
		{
			c[i%2][j] = min(c[i%2][j-1],c[(i-1)%2][j-1]+abs(b[i]-a[j]));
		}
	}
	sum = c[(n-1)%2][m-1];
	printf("%d\n",sum);
	return 0;
}