#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int key;
	int id;
}a[1000010],b[1000010];
bool visit[1000010];
int g[1000010],t[1000010];
int cmp( const void *a , const void *b ) 
{ 
    struct ac *c = (ac *)a; 
    struct ac *d = (ac *)b; 
    if(c->key != d->key) return c->key - d->key; 
    else return c->id - d->id; 
}
int find ( int n, int end )
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
	if ( visit[mid] == false )
	{
		visit[mid] = true;
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
				visit[j] = false;
				j++;
				x = a[i].id;
				y = x;
			}
			else
			{
				x = a[i].id;
				y = x;
				t[j] = a[i].key;
				visit[j] = false;
				j++;
			}
		}
	}
	if ( min < x )
		min = x;
	if ( max > y )
		max = y;
	if ( x == y )
	{
		t[j] = a[i].key;
		visit[j] = false;
		j++;
	}
	else
	{
		x = a[i].id;
		y = x;
		t[j] = a[i].key;
		visit[j] = false;
	//	j++;
	}
	c = 0;
	for ( i = min; i >= 0; i-- )
	{
		c += find(g[i],j-1);
		if ( c == j )
		{
			c = min-i+1;
			break;
		}
	}
	k = 0;
	for ( i = 0; i < j; i++ )
		visit[i] = false;
	for ( i = max; i < n; i++ )
	{
		k += find(g[i],j-1);
		if ( k == j )
		{
			k = i-max+1;
			break;
		}
	}
	if ( k < c )
		cout<<k<<endl;
	else
		cout<<c<<endl;
	return 0;
}