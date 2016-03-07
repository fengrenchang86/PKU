#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int price,dist,fit;
}a[10010];
int main ()
{
	int cmp1 ( const void*a, const void*b );
	int cmp2 ( const void*a, const void*b );
	int n,i,x,y,min;
	while ( scanf("%d",&n) && n!=0 )
	{
		for ( i = 0; i < n; i++ )
		{
			scanf("%d%d",&a[i].dist,&a[i].price);
			a[i].fit = 0;
		}
		qsort(a,n,sizeof(a[0]),cmp1);
		min = 2000000;
		x = a[0].dist;
		i = 0;
		while ( i < n && a[i].dist == x )
		{
			a[i].fit++;
			if ( a[i].price < min )
				min = a[i].price;
			i++;
		}
		while ( i < n )
		{
			x = a[i].dist;
			y = min;
			if ( a[i].price < min )
			{
				a[i].fit++;
				min = a[i].price;
			}
			i++;
			while ( i < n && a[i].dist == x )
			{
				if ( a[i].price < y )
					a[i].fit++;
				if ( a[i].price < min )
					min = a[i].price;
				i++;
			}
		}
		qsort(a,n,sizeof(a[0]),cmp2);
		min = 2000000000;
		x = a[0].price;
		i = 0;
		while ( i < n && a[i].price == x )
		{
			a[i].fit++;
			if ( a[i].dist < min )
				min = a[i].dist;
			i++;
		}
		while ( i < n )
		{
			x = a[i].price;
			y = min;
			if ( a[i].dist < min )
			{
				a[i].fit++;
				min = a[i].dist;
			}
			i++;
			while ( i < n && a[i].price == x )
			{
				if ( a[i].dist < y )
					a[i].fit++;
				if ( a[i].dist < min )
					min = a[i].dist;
				i++;
			}
		}
		x = 0;
		for ( i = 0; i < n; i++ )
		{
			if ( a[i].fit == 2 )
				x++;
		}
		cout<<x<<endl;
	}
	return 0;
}
int cmp1 ( const void*a, const void*b )
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return c->dist-d->dist;
}
int cmp2 ( const void*a, const void*b )
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return c->price-d->price;
}