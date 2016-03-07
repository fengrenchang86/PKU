#include <iostream>
using namespace std;
int a[100100];
struct ac
{
	int *t;
}c[800000];
void Merge(int i, int begin, int end )
{
	if ( begin == end )
	{
		c[i].t = new int[2];
		c[i].t[1] = a[begin];
		return;
	}
	Merge(i*2,begin,(begin+end)/2);
	Merge(i*2+1,(begin+end)/2+1,end);
	c[i].t = new int[end-begin+2];
	int len1 = (begin+end)/2-begin+1;
	int len2 = end-(begin+end)/2;
	int x=1,y=1,z=1;
	while ( x <= len1 && y <= len2 )
	{
		if ( c[i*2].t[x] < c[i*2+1].t[y] )
			c[i].t[z++] = c[i*2].t[x++];
		else
			c[i].t[z++] = c[i*2+1].t[y++];
	}
	while ( x <= len1 )
		c[i].t[z++] = c[i*2].t[x++];
	while ( y <= len2 )
		c[i].t[z++] = c[i*2+1].t[y++];
}
int search ( int i, int begin, int end, int x, int y, int k )
{
	if ( begin == x && end == y )
		return c[i].t[k];
	if ( y <= (begin+end)/2 )
		return search(i*2,begin,(begin+end)/2,x,y,k);
	else if ( x > (begin+end)/2 )
		return search(i*2+1,(begin+end)/2+1,end,x,y,k);
	else
	{
		if ( (begin+end)/2-x+1 >= k )
			return search(i*2,begin,(begin+end)/2,x,(begin+end)/2,k);
		else
			return search(i*2+1,(begin+end)/2+1,end,(begin+end)/2+1,y,k-(begin+end)/2+x-1);
	}
}
int main ()
{
	int n,m,i;
	int x,y,k;
	scanf("%d%d",&n,&m);
	for ( i = 1; i <= n; i++ )
		scanf("%d",&a[i]);
	Merge(1,1,n);
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d%d",&x,&y,&k);
		printf("%d\n",search(1,1,n,x,y,k));
	}
	return 0;
}