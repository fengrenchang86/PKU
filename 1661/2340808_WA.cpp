#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int left,right,high;
	bool visit;
	_int64 goleft,goright;
	ac(){goleft=goright=300000000000;visit=false;}
}a[1002];
int n,x,y,max;
int cmp ( const void *a, const void *b )
{
	struct ac *c = (ac*)a;
	struct ac *d = (ac*)b;
	if ( c->high != d->high )
		return d->right-c->high;
	else
		return c->left-d->left;
}
int findleft ( int k )
{
	int i;
	for ( i = k+1; i <= n; i++ )
	{
		if ( a[k].high-a[i].high > max )
			return 0;
		if ( a[i].left <= a[k].left && a[k].left <= a[i].right )
			return i;
	}
	return 0;
}
int findright ( int k )
{
	int i;
	for ( i = k+1; i <= n; i++ )
	{
		if ( a[k].high-a[i].high > max )
			return 0;
		if ( a[i].left <= a[k].right && a[k].right <= a[i].right ) 
			return i;
	}
	return 0;
}
int main ()
{
	int tcase;
	int i;
	_int64 j;
	int l = 599999,r = 0;
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		scanf("%d%d%d%d",&n,&x,&y,&max);
		for ( i = 0; i < n; i++ )
		{
			scanf("%d%d%d",&a[i].left,&a[i].right,&a[i].high);
			if ( a[i].left < l )
				l = a[i].left;
			if ( a[i].right > r )
				r = a[i].right;
		}
		a[n].left = l;
		a[n].right = r;
		a[n].high = 0;
		qsort(a,n+1,sizeof(a[0]),cmp);
		for ( i = 0; i <= n; i++ )
		{
			if ( a[i].left <= x && x <= a[i].right)
				break;
		}
		a[i].goleft = x-a[i].left;
		a[i].goright = a[i].right-x;
		j = 3000000000;
		while ( i < n )
		{
			l = findleft(i);
			if ( l == n )
			{
				if ( a[i].goleft < j )
					j = a[i].goleft;
			}
			else if ( l != 0 )
			{
				if ( a[l].goleft > a[i].goleft+a[i].left-a[l].left )
					a[l].goleft = a[i].goleft + a[i].left - a[l].left;
				if ( a[l].goright > a[i].goleft + a[l].right-a[l].left )
					a[l].goright = a[i].goleft + a[l].right-a[l].left;
			}
			r = findright(i);
			if ( r == n )
			{
				if ( a[i].goright < j )
					j = a[i].goright;
			}
			else if ( r != 0 )
			{
				if ( a[r].goleft > a[i].goright + a[i].right - a[r].left )
					a[r].goleft = a[i].goright + a[i].right - a[r].left;
				if ( a[r].goright > a[i].goright + a[r].right - a[i].right )
					a[r].goright = a[i].goright + a[r].right - a[i].right;
			}
			i++;
		}
		printf("%I64d\n",j+y);
	}
	return 0;
}