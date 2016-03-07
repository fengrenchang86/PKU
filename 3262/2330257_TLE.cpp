#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int t;
	int d;
	int v;
	ac(){v=0;}
}a[100100];
int cmp( const void *a , const void *b ) 
{ 
    struct ac *c = (ac *)a; 
    struct ac *d = (ac *)b; 
    if(c->t != d->t) return c->t - d->t; 
    else return d->d - c->d; 
} 
int main ()
{
	int n,i,j,k=0,sum=0,pos;
	int min;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d%d",&a[i].t,&a[i].d);
		sum += a[i].d;
	}
	qsort(a,n,sizeof(a[0]),cmp);
	i = 0;
	int max,ans=0;
	while ( k < n )
	{
		i = 0;
		while ( a[i].v == 1 )
			i++;
		min = (sum-a[i].d)*a[i].t;
		pos = i;
		max = a[i].d;
		j = i+1;
		while ( j < n )
		{
			if ( a[j].v == 1 )
				continue;
			if ( a[i].t != a[j].t )
			{
				if ( max >= a[j].d )
					break;
				else if ( (sum-a[j].d)*a[j].t < min )
				{
					min = (sum-a[j].d)*a[j].t;
					pos = j;
				}
			}
			j++;
		}
		a[pos].v = 1;
		sum-=a[pos].d;
		ans+=min;
		k++;
	}
	printf("%d\n",ans*2);
	return 0;
}