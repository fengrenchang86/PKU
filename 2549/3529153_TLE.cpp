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
int tmax ( int x, int y )
{
	return x>y?x:y;
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
		return d->x - c->x;
}
void input ()
{
	int i,j,k=0;
	for ( i = 0; i < n; i++ )
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(a[0]),cmp);
	for ( i = 0; i < n-1; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			if ( i == j )
				continue;
			plus[k].x = a[i];
			plus[k].y = a[j];
			plus[k].sum = a[i]+a[j];
			minu[k].x = a[i];
			minu[k].y = a[j];
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
	int i=0,j=0,k;
	int ans = -2147483647;
	while ( i < m && j < m )
	{
		if ( plus[i].sum < minu[j].sum )
			i++;
		else if ( plus[i].sum > minu[j].sum )
			j++;
		else
		{
			k = j;
			while ( plus[i].sum == minu[k].sum && i < m )
			{
				while (plus[i].sum == minu[k].sum && j < m )
				{
					if ( plus[i].x != minu[k].y && plus[i].x != minu[k].x &&
						plus[i].y != minu[k].x && plus[i].y != minu[k].y )
					{
						if ( ans < minu[k].y)
							ans = minu[k].y;
					}
					k++;
				}
				i++;
				k = j;
			}
			j = k;
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