#include <iostream>
#include <stdlib.h>
using namespace std;
int s[110];
int c[120][120];
bool v[110];
int n;
struct ac
{
	int a,b,len;
}side[12000];
int cmp ( const void*a, const void*b )
{
	struct ac *c = (ac*)a;
	struct ac *d = (ac*)b;
	return c->len - d->len;
}
int find ( int x )
{
	while ( s[x] != x )
		x = s[x];
	return x;
}
void join ( int x, int y )
{
	s[find(x)] = find(y);
}
void init ( )
{
	int i;
	for ( i =0 ; i <= n; i++ )
	{
		v[i] = false;
		s[i] = i;
	}
}
int main ()
{
	int i,j,m,x=0,sum=0;
	int a,b;
	scanf("%d",&n);
	for ( i = 1; i <= n ;i++ )
	{
		for ( j = 1; j <= n; j++ )
		{
			scanf("%d",&c[i][j]);
			if ( i < j )
			{
				side[x].a = i;
				side[x].b = j;
				side[x].len = c[i][j];
				x++;
			}
		}
	}
	qsort(side,x,sizeof(side[0]),cmp);
	scanf("%d",&m);
	init();
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d",&a,&b);
		v[a] = true;
		v[b] = true;
		if ( c[a][b] > 0 )
		{
			c[a][b] *= -1;
			c[b][a] *= -1;
			join(a,b);
		}
	}
	for ( i = 0; i < x; i++ )
	{
		a = side[i].a;
		b = side[i].b;
		if ( find(a) != find(b) )
		{
			sum += side[i].len;
			join(a,b);
		}
	}
	cout<<sum<<endl;
	return 0;
}