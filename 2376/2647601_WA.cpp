#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int begin,end;
}a[26000];
int cmp ( const void*a, const void*b )
{
	struct ac* c = (ac*)a;
	struct ac* d = (ac*)b;
	if ( c->begin != d->begin )
		return c->begin - d->begin;
	else
		return d->end - c->end;
}
int main ()
{
	int t,n,i,x,y,c=1;
	scanf("%d%d",&n,&t);
	for ( i = 0; i < n; i++ )
		scanf("%d%d",&a[i].begin,&a[i].end);
	qsort(a,n,sizeof(a[0]),cmp);
	if ( a[0].begin != 1 )
	{
		cout<<-1<<endl;
		return 0;
	}
	y = a[0].end;
	x = y;
	i = 1;
	while ( i < n )
	{
		if ( a[i].begin <= y )
		{
			if ( a[i].end > x )
				x = a[i].end;
			i++;
		}
		else
		{
			if ( a[i].begin > x )
			{
				cout<<-1<<endl;
				return 0;
			}
			y = x;
			c ++;
		}
	}
	if ( x < 10 )
	{
		cout<<-1<<endl;
		return 0;
	}
	if ( y != x )
		c++;
	cout<<c<<endl;
	return 0;
}