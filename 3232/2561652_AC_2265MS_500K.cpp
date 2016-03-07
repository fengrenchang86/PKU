#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp ( const void *a, const void *b )
{
	return *(int *)b - *(int *)a; 
}
int a[100200];
int m,n,k;
int f ( int begin, int end )
{
	if( begin >= end )
		return end;
	int mid = (begin+end)/2;
	__int64 t = __int64(m)*__int64(mid);
	int v;
	for ( int i = 0; i < n; i++ )
	{
		if ( a[i] > mid )
		{
			if ( (a[i]-mid)%k==0 )
				v = (a[i]-mid)/k;
			else
				v = (a[i]-mid)/k+1;
			if ( v > mid || v > t )
			{
				t = -1;
				break;
			}
			t -=v;
		}
		else
			break;
	}
	if ( t < 0 )
		return f( mid+1, end );
	else
		return f( begin, mid);
}
int main ()
{
	int tcase,i;
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		scanf("%d",&n);
		for ( i = 0; i < n; i++ )
//			a[i] = (rand()*rand())%100000000;
			scanf("%d",&a[i]);
		qsort(a,n,sizeof(a[0]),cmp);
		scanf("%d%d",&m,&k);
//		m = rand();
//		k = rand();
		if ( k == 1 )
			printf("%d\n",a[0]);
		else
		{
			k--;
			printf("%d\n",f(1,a[0]));
		}
	}
	return 0;
}