#include <iostream>
#include <stdlib.h>
using namespace std;
const int M=1000100;//1000100
struct ac
{
	int x,y,sum;
	int tmin,tmax;
}tplus[M],minu[M];
int a[1200];
int n,m,k;
int cmp ( const void *a , const void *b ) 
{ 
     return *(int *)a - *(int *)b; 
}
int cmptplus1( const void*a, const void*b )// min vale from big
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	if ( c->sum != d->sum )
		return c->sum - d->sum;
	else
		return d->x - c->x;
}
int cmptplus2( const void*a, const void*b )// max value from small
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
		return d->y - c->y;
}
void input ()
{
	int i,j;
	m=0;k=0;
	for ( i = 0; i < n; i++ )
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(a[0]),cmp);
	for ( i = 0; i < n-1; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			if ( i == j )
				continue;
			if ( i < j )
			{
				tplus[k].x = a[i];
				tplus[k].y = a[j];
				tplus[k].sum = a[i]+a[j];
				k++;
				minu[m].tmin = a[i];
				minu[m].tmax = a[j];
			}
			else
			{
				minu[m].tmin = a[j];
				minu[m].tmax = a[i];
			}
//			minu[m].x = a[i];
			minu[m].y = a[j];
			minu[m].sum = a[j]-a[i];
			m++;
		}
	}
	qsort(minu,m,sizeof(minu[0]),cmpminu);
}
void solve ( )
{
	int i=0,j=0;
	int ans = -2147483647;
	qsort(tplus,k,sizeof(tplus[0]),cmptplus1);
	while ( i < k && j < m )
	{
		if ( tplus[i].sum < minu[j].sum )
			i++;
		else if ( tplus[i].sum > minu[j].sum )
			j++;
		else
		{
			if ( i == 0 || tplus[i].sum != tplus[i-1].sum )
			{
				while ( tplus[i].sum == minu[j].sum )
				{
					if ( tplus[i].x > minu[j].tmax && minu[j].y > ans )
						ans = minu[j].y;
					j++;
				}
			}
			else
				i++;
		}
	}
	qsort(tplus,k,sizeof(tplus[0]),cmptplus2);
	i = j = 0;
	while ( i < k && j < m )
	{
		if ( tplus[i].sum < minu[j].sum )
			i++;
		else if ( tplus[i].sum > minu[j].sum )
			j++;
		else
		{
			if ( i == 0 || tplus[i].sum != tplus[i-1].sum )
			{
				while ( tplus[i].sum == minu[j].sum )
				{
					if ( tplus[i].y < minu[j].tmin && minu[j].y > ans )
						ans = minu[j].y;
					j++;
				}
			}
			else
				i++;
		}
	}
	if ( ans == -2147483647 )
		printf("no solution\n");
	else
		printf("%d\n",ans);
}
int main ()
{
	while ( scanf("%d",&n) && n )
	{
		input();
		solve();
	}
	return 0;
}