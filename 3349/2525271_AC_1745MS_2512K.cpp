#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
const int max = 100010;
struct ac
{
	int v[6];
}t[max];
int comp ( int a[], int b[] )
{
	int i;
	for ( i = 0; i < 6; i++ )
	{
		if ( a[i] > b[i] )
			return 1;
		else if ( a[i] < b[i] )
			return -1;
	}
	return 0;
}
int cmp ( const void *a, const void *b )
{
	struct ac *c = (ac*)a;
	struct ac *d = (ac*)b;
	return comp(c->v,d->v);
}
void f ( int v[] )
{
	int a[6],b[6],t[6];
	int i,j,k,min=2000000000;
	for ( i = 0; i < 6; i++ )
	{
		t[i] = v[i];
		if ( t[i] < min )
			min = t[i];
	}
	for ( j = 0; j < 6; j++ )
	{
		if ( v[j] != min )
			continue;
		i = 0;
		for ( k = j; k >= 0; k-- )
			a[i++] = v[k];
		for ( k = 5; k > j; k-- )
			a[i++] = v[k];
		i = 0;
		for ( k = j; k < 6; k++ )
			b[i++] = v[k];
		for ( k = 0; k < j; k++ )
			b[i++] = v[k];
		k = comp(a,b);
		if ( k == 1 && comp(t,b) == 1)
		{
			for ( i = 0; i < 6; i++ )
				t[i] = b[i];
		}
		else if ( k != 1 && comp(t,a) == 1 )
			for ( i = 0; i < 6; i++ )
				t[i] = a[i];
	}
	for ( i = 0; i < 6; i++ )
		v[i] = t[i];
}
int main ()
{
	int i,n,j;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < 6; j++ )
			scanf("%d",&t[i].v[j]);
		f(t[i].v);
	}
	qsort(t,n,sizeof(t[0]),cmp);
	j = 0;
	for ( i = 1; i < n; i++ )
	{
		if ( comp(t[i].v,t[i-1].v ) == 0 )
		{
			j = 1;
			break;
		}
	}
	if ( j == 0 )
		printf("No two snowflakes are alike.\n");
	else
		printf("Twin snowflakes found.\n");
	return 0;
}