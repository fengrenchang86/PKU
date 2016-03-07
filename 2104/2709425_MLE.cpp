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
void search ( int i, int begin, int end, int x, int y, int k, int t[] )
{
	if ( begin == x && end == y )
	{
		int j;
		for ( j = 1; j <= end-begin+1; j++ )
			t[j] = c[i].t[j];
		return;
	}
	if ( y <= (begin+end)/2 )
		search(i*2,begin,(begin+end)/2,x,y,k,t);
	else if ( x > (begin+end)/2 )
		search(i*2+1,(begin+end)/2+1,end,x,y,k,t);
	else
	{
		int *t1 = new int[(end-begin)/2+2];
		int *t2 = new int[(end-begin)/2+2];
		search(i*2,begin,(begin+end)/2,x,(begin+end)/2,k,t1);
		search(i*2+1,(begin+end)/2+1,end,(begin+end)/2+1,y,k,t2);
		int len1=(begin+end)/2-x+1,len2=y-(begin+end)/2;
		x = 1;y=1;int z=1;
		while ( x <= len1 && y <= len2 )
		{
			if ( t1[x] < t2[y] )
				t[z++] = t1[x++];
			else
				t[z++] = t2[y++];
		}
		while ( x <= len1 )
			t[z++] = t1[x++];
		while ( y <= len2 )
			t[z++] = t2[y++];
	}
}
int t[100100];
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
		search(1,1,n,x,y,k,t);
		printf("%d\n",t[k]);
	}
	return 0;
}