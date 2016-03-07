#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int x,y;
}a[21000],b[21000];
int n,m;
int acCmp (const void*a, const void*b )
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	if ( c->x != d->x )
		return c->x - d->x;
	else
		return d->y - c->y;
}
int acSearch ( ac t, int k )
{
	int begin=0,end=k,mid;
	do
	{
		mid = (begin+end)/2;
		if ( b[mid].x < t.x && b[mid].y < t.y )
			end = mid;
		else
			begin = mid+1;
	}while ( begin<end);
	if ( b[begin].x < t.x && b[begin].y < t.y )
		return begin;
	else
		return begin+1;
}
void input()
{
	int i,j,k=0;
	m = 0;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
		scanf("%d%d",&a[i].x,&a[i].y);
	qsort(a,n,sizeof(a[0]),acCmp);
	ac t;
	b[0] = a[0];
	for ( j = 1; j < n; j++ )
	{
		t = a[j];
		i = acSearch(t,m);
	//	printf("%d\n",i);
		b[i] = t;
		if ( i > m )
			m++;
	}
	printf("%d\n",m+1);
}
int main ()
{
	int tc;
	scanf("%d",&tc);
	while ( tc-- )
		input();
	return 0;
}