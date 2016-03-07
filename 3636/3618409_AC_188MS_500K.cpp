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
int acSearch ( ac t, int begin, int end )
{
	if ( begin == end )
	{
		if ( t.x > b[begin].x && t.y > b[begin].y )
			return begin;
		else
			return begin+1;
	}
	int mid = (begin+end)/2;
	if ( t.x > b[mid].x && t.y > b[mid].y )
		return acSearch(t,begin,mid);
	else
		return acSearch(t,mid+1,end);
}
void input()
{
	int i,j,k=0;
	m = 0;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
		scanf("%d%d",&a[i].x,&a[i].y);
	qsort(a,n,sizeof(a[0]),acCmp);
//	cout<<"OK"<<endl;
//	for ( i = 0; i < n; i++ )
//		printf("%d %d\n",a[i].x,a[i].y);
//	cout<<"OK"<<endl;
	ac t;
	b[0] = a[0];
	for ( j = 1; j < n; j++ )
	{
		t = a[j];
		i = acSearch(t,0,m);
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