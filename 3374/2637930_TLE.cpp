#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int up,down;
}v,a[6600000];
int cmp ( const void*a, const void*b )
{
	struct ac* c = (ac*)a;
	struct ac* d = (ac*)b;
	return c->up*d->down-c->down*d->up;
}
void SmallHeapInsert (int& CurrentSize, ac x )
{
	int i = CurrentSize;
	while ( i > 1 )
	{
		if ( a[i/2].up*x.down > x.up*a[i/2].down )
		{
			a[i] = a[i/2];
			i /= 2;
		}
		else
			break;
	}
	a[i] = x;
	CurrentSize++;
}
void SmallDel (int& CurrentSize )
{
	CurrentSize--;
	ac item = a[CurrentSize];
	int i = 2;
	while ( i <= CurrentSize )
	{
		if ( i < CurrentSize && a[i].up*a[i+1].down > a[i+1].up*a[i].down )
			i++;
		if ( item.up*a[i].down <= a[i].up*item.down )
			break;
		a[i/2] = a[i];
		i *= 2;
	}
	a[i/2] = item;
}
int gcd(int m,int n)
{
	int p;
	while(n)
	{
		p=m%n;
		m=n;
		n=p;
	}
	return m;
}
int main ()
{
	int n,c,i,j,CurrentSize = 0;
	int t;
	scanf("%d%d",&n,&c);
	v.up = 0;
	v.down = 1;
	a[CurrentSize++] = v;
	v.up = 1;
	v.down = 1;
	a[CurrentSize++] = v;
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j < i; j++ )
		{
			v.up = j;
			v.down = i;
			if ( gcd(i,j) == 1 )
				a[CurrentSize++] = v;
		}
	}
	v.up = 0;
	v.down = 0;
	qsort(a,CurrentSize,sizeof(a[0]),cmp);
	t = CurrentSize;
	for ( i = 0; i < c; i++ )
	{
 		scanf("%d",&j);
		if ( j > t )
		{
			cout<<"No Solution"<<endl;
			continue;
		}
		printf("%d/%d\n",a[j-1].up,a[j-1].down);
	}
	return 0;
}