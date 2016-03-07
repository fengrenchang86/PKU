#include <iostream>
#include <stdlib.h>
int a[5000000];
int cmp ( const void*a, const void*b )
{
	return (int*)a-(int*)b;
}
void insert ( int i, int begin, int end, int x )
{
	a[i]++;
	if ( begin == end )
		return;
	if ( x <= (begin+end)/2 )
		insert(i*2,begin,(begin+end)/2,x);
	else
		insert(i*2+1,(begin+end)/2+1,end,x);
}
void del ( int i, int begin, int end, int x )
{
	a[i]--;
	if ( begin == end )
		return;
	if ( x <= (begin+end)/2 )
		del(i*2,begin,(begin+end)/2,x);
	else
		del(i*2+1,(begin+end)/2+1,end,x);
}
int go ( int i, int begin, int end, int key, int& x )
{
	if ( begin == end )
	{
		x = begin;
		return abs(x-key);
	}
	if ( a[i*2] == 0 )
		return go ( i*2+1, (begin+end)/2+1,end,key,x);
	else if ( a[i*2+1] == 0 )
		return go ( i*2, begin,(begin+end)/2,key,x);
	else
	{
		int x1,x2;
		int j = go(i*2,begin,(begin+end)/2,key,x1);
		int k = go(i*2+1,(begin+end)/2+1,end,key,x2);
		if ( j <= k )
		{
			x = x1;
			return j;
		}
		else
		{
			x = x2;
			return k;
		}
	}
}
int main ()
{
	int b[3000];
	int m,n,i,j,k,x,sum = 0;
	memset(a,0,sizeof(a));
	scanf("%d%d",&m,&n);
	for ( i = 0; i < m; i++ )
	{
		scanf("%d",&x);
		insert(1,1,1000000,x);
	}
	for ( i = 0; i < n; i++ )
		scanf("%d",&b[i]);
	qsort(b,n,sizeof(b[0]),cmp);
	for ( i = 0; i < n; i++ )
	{
		k = go(1,1,1000000,b[i],j);
//		printf("abs(%d-%d) = %d\n",b[i],j,abs(b[i]-j));
		sum += k;
		del(1,1,1000000,j);
	}
	printf("%d\n",sum);
	return 0;
}