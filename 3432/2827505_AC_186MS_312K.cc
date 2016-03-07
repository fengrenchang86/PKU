#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int x,y;
}v[2100];
int cmp ( const void*a, const void*b )
{
	struct ac*c = (ac*) a;
	struct ac*d = (ac*) b;
	if ( c->x != d->x )
		return c->x-d->x;
	else
		return c->y-d->y;
}
int find( int x, int y, int n)
{
	int begin = 0;
	int end = n-1;
	int mid;
	while ( begin < end )
	{
		mid = (begin+end)/2;
		if ( v[mid].x > x || v[mid].x==x && v[mid].y > y )
			end = mid;
		else if ( v[mid].x < x || v[mid].x == x && v[mid].y < y )
			begin = mid+1;
		else
			return 1;
	}
	if ( v[end].x == x && v[end].y == y )
		return 1;
	else
		return 0;
}
int main ()
{
	int n,i,j,c=0;
	int dx,dy;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
		scanf("%d%d",&v[i].x,&v[i].y);
	qsort(v,n,sizeof(v[0]),cmp);
	for ( i = 0; i < n-1; i++ )
	{
		for ( j = i+1; j < n; j++ )
		{
			if ( v[i].y >= v[j].y )
				continue;
			dx = abs(v[i].x-v[j].x);
			dy = abs(v[i].y-v[j].y);
			if ( find(dy+v[i].x,v[i].y-dx,n)==1 )
			{
				if ( find(v[j].x+dy,v[j].y-dx,n) == 1 )
					c++;
			}
		}
	}
	cout<<c<<endl;
	return 0;
}