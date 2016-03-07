#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int x,y,sum;
}plus[1000100],minu[1000100];
int a[1200];
int n,m;
int cmp ( const void *a , const void *b ) 
{ 
     return *(int *)a - *(int *)b; 
}
int cmpplus( const void*a, const void*b )
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	if ( c->sum != d->sum )
		return c->sum - d->sum;
	else
		return c->y - d->y;
}
int cmpminu( const void*a, const void*b )
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	if ( c->sum != d->sum )
		return c->sum - d->sum;
	else
		return c->x - d->x;
}
void input ()
{
	int i,j,k=0;
	for ( i = 0; i < n; i++ )
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(a[0]),cmp);
	for ( i = 0; i < n-1; i++ )
	{
		for ( j = i+1; j < n; j++ )
		{
			plus[k].x = i;
			plus[k].y = j;
			plus[k].sum = a[i]+a[j];
			minu[k].x = i;
			minu[k].y = j;
			minu[k].sum = a[j]-a[i];
			k++;
		}
	}
	m = k;
	qsort(plus,k,sizeof(plus[0]),cmpplus);
	qsort(minu,k,sizeof(minu[0]),cmpminu);
}
void solve ( )
{
	int i=0,j=0;
	int ans = -2147483647;
	while ( i < m && j < m )
	{
		if ( plus[i].sum < minu[j].sum )
			i++;
		else if ( plus[i].sum > minu[j].sum )
			j++;
		else
		{
			if ( plus[i].y < minu[j].x )
			{
				if ( ans < plus[i].sum+a[minu[j].x] )
					ans = plus[i].sum+a[minu[j].x];
			}
			j++;
		}
	}
	if ( ans == -2147483647 )
		printf("no solution\n");
	else
		printf("%d\n",ans);
}
int main ()
{
	while ( scanf("%d",&n) != EOF )
	{
		if ( n == 0 )
			break;
		input();
		solve();
	}
	return 0;
}