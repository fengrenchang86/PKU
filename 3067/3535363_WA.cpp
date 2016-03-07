#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int x,y;
}c[1000100];
int a[1000100];
int b[1000100];
int ans,n,m;
int cmp ( const void*a, const void*b )
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	if ( c->x != d->x )
		return c->x - d->x;
	else
		return c->y - d->y;
}
void Merg( int begin, int end )
{
	if ( begin == end )
		return;
	int mid = (begin+end)/2;
	Merg(begin,mid);
	Merg(mid+1,end);
	int num = mid-begin+1;
	int i = begin,j=mid+1,k=begin;
	while ( i <= mid && j <= end )
	{
		if ( a[i] <= a[j] )
		{
			b[k++] = a[i++];
			num--;
		}
		else
		{
			b[k++] = a[j++];
			ans += num;
		}
	}
	while ( i <= mid )
		b[k++] = a[i++];
	while ( j <= end )
		b[k++] = a[j++];
	for ( i = begin; i <= end; i++ )
		a[i] = b[i];
}
void input ()
{
	int t,i;
	scanf("%d%d%d",&n,&m,&t);
	for ( i = 0; i < t; i++ )
	{
		scanf("%d%d",&c[i].x,&c[i].y);
	}
	qsort(c,t,sizeof(c[0]),cmp);
	for ( i = 0; i < t; i++ )
		a[i] = c[i].y;
	ans = 0;
	Merg(0,t-1);
//	for ( i = 0; i < t; i++ )
//		printf("%d\n",a[i]);
}
int main ()
{
	int i,tc;
	cin>>tc;
	for ( i = 1; i <= tc; i++ )
	{
		input();
		printf("Test case %d: %d\n",i,ans);
	}
	return 0;
}