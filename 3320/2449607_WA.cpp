#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int key;
	int id;
}a[1000010];
int visit[1000010];
int g[1000010],t[1000010];
int cmp( const void *a , const void *b ) 
{ 
    struct ac *c = (ac *)a; 
    struct ac *d = (ac *)b; 
    if(c->key != d->key) return c->key - d->key; 
    else return c->id - d->id; 
}
int find ( int n, int end, int mode )
{
	int begin = 0;
	int mid;
	while ( begin <= end )
	{
		mid = (begin+end)/2;
		if ( n < t[mid] )
			end = mid;
		else if ( n > t[mid] )
			begin = mid+1;
		else
			break;
	}
	if ( visit[mid] == 0 )
	{
		visit[mid] = mode+1;
		return 1;
	}
	else
		return 0;
}
int main ()
{
	int n,i,j=0,k,c;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d",&a[i].key);
		g[i] = a[i].key;
		a[i].id = i;
	}
	qsort(a,n,sizeof(a[0]),cmp);
	int x,y,min,max;
	x = a[0].id;
	y = a[0].id;
	min = 0;
	max = n-1;
	visit[0] = false;
	_int64 h = -9000000000;
	t[j++] = a[0].key;
	for ( i = 1; i < n; i++ )
	{
		if ( a[i].key == a[i-1].key )
			y = a[i].id;
		else
		{
			if ( min < x )
				min = x;
			if ( max > y )
				max = y;
			if ( x == y )
			{
				t[j] = a[i].key;
				j++;
				x = a[i].id;
				y = x;
				h = a[i-1].id;
			}
			else
			{
				x = a[i].id;
				y = x;
				t[j] = a[i].key;
				j++;
			}
		}
	}
	if ( x == y )
		h = a[i-1].id;
	if ( min < x )
		min = x;
	if ( max > y )
		max = y;
	int m = j;
	if ( h == -9000000000 )
		h = min;
	c = 0;
	y = n;
	c+=find(g[h],j-1,1);
	j-=c;
	x = j;
	while ( j >= 0 )
	{
		for ( i = 0; i < m; i++ )
		{
			if ( visit[i] != 2 )
				visit[i] = 0;
		}
		c = 0;
		for ( i = h; i >= 0; i-- )
		{
			c += find(g[i],m-1,0);
			if ( c == j )
				break;
		}
		if ( c == j )
			c = i;
		else
		{
			j--;
			continue;
		}
		k = 0;
		for ( i = 0; i < m; i++ )
		{
			if ( visit[i] != 2 )
				visit[i] = 0;
		}
		for ( i = h; i < n; i++ )
		{
			k += find(g[i],m-1,0);
			if ( k == x-j )
				break;
		}
		if ( k == x-j )
			k = i;
		else
		{
			j--;
			continue;
		}
		if ( k-c+1 < y )
			y = k-c+1;
		j--;
	}
	cout<<y<<endl;
	return 0;
}