#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int x,y,len;
}a[12000];
bool visit[120];
int f[120];
int n,m;
int cmp ( const void*a, const void*b )
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return c->len-d->len;
}
int father ( int x )
{
	int i=x;
	while ( f[i] != -1 )
		i = f[i];
	return i;
}
void join ( int x, int y )
{
	f[father(x)] = y;
}
void input ()
{
	int i;
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].len);
	}
	qsort(a,m,sizeof(a[0]),cmp);
}
int slim ( int k )
{
	int i,j=0;
	int fx,fy;
	for ( i = 0; i <= n; i++ )
	{
		f[i] = -1;
		visit[i] = false;
	}
	i = k;
	while ( j < n-1 && i < m )
	{
		if ( visit[a[i].x] == false )
		{
			visit[a[i].x] = true;
			fx = -1;
		}
		else
			fx = father(a[i].x);
		if ( visit[a[i].y] == false )
		{
			visit[a[i].y] = true;
			fy = -1;
		}
		else
			fy = father(a[i].y);
		if ( fx == -1 && fy == -1 )
		{
			f[a[i].x] = a[i].y;
			j ++;
		}
		else if ( fx == -1 )
		{
			f[a[i].x] = fy;
			j++;
		}
		else if ( fy == -1 )
		{
			f[a[i].y] = fx;
			j++;
		}
		else if ( fx != fy )
		{
			f[a[i].x] = fy;
			j++;
		}
		i++;
	}
	if ( j == n-1 )
		i--;
	if ( j < n-1 )
		return 2000000000;
	else
		return a[i].len-a[k].len;
}
int solve ()
{
	int i,j,min=2000000000;
	for ( i = 0; i < m; i++ )
	{
		j = slim(i);
		if ( j < min )
			min = j;
	}
	if ( min == 2000000000 )
		return -1;
	else
		return min;
}
int main ()
{
	while ( scanf("%d%d",&n,&m) && (n + m) )
	{
		input();
		printf("%d\n",solve());
	}
	return 0;
}