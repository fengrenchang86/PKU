#include <iostream>
#include <stdlib.h>
using namespace std;
int powe[40];
struct ac
{
	int num;
	int a[20];
	int visit;
}t[66000];
int b[20];
int A,B,C,S;
int cmp ( const void *a, const void*b )
{
	struct ac *c = (ac*)a;
	struct ac *d = (ac*)b;
	return c->num - d->num;
}
int comp ( const void*a, const void*b )
{
	struct ac *c = (ac*)a;
	struct ac *d = (ac*)b;
	return d->visit - c->visit;
}
void init ()
{
	int i;
	powe[0] = 1;
	for ( i = 1; i <= 30; i++ )
		powe[i] = powe[i-1]*2;
}
void change ( int n, int a[] )
{
	int i;
	for ( i = 15; i >= 0; i-- )
	{
		a[i] = n/powe[i];
		n %= powe[i];
	}
}
void initTwo()
{
	int i;
	for ( i = 0; i <= 65536; i++ )
	{
		if ( t[i].visit != -1 )
			change(i,t[i].a);
	}
}
void solve ( )
{
	int i,j,k=2;
	int n = 65536;
	for ( i = 0; i <= 65536; i++ )
	{
		t[i].num = i;
		t[i].visit = -1;
	}
	int x = S;
	t[x].visit = 1;
	while ( 1 )
	{
		x = (A*x+B)%C;
		if ( t[x].visit == -1 )
			t[x].visit = k++;
		else
			break;
	}
	initTwo();
	qsort(t,65536,sizeof(t[0]),comp);
	memset(b,0,sizeof(b));
	k--;
	for ( i = 0; i < k; i++ )
	{
		for ( j = 0; j < 16; j++ )
		{
			if ( t[i].a[j] == t[0].a[j] )
				b[j]++;
		}
	}
	for ( i = 15; i >= 0; i-- )
	{
		if ( b[i] == k )
			printf("%d",t[0].a[i]);
		else
			printf("?");
	}
	printf("\n");
}
int main ()
{
	init();
	while ( scanf("%d",&A) != EOF )
	{
		if ( A == 0 )
			break;
		scanf("%d%d%d",&B,&C,&S);
		solve();
	}
	return 0;
}
