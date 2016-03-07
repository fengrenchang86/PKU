#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
struct ac
{
	int x,y;
	double dis;
}a[1000100];;
struct point
{
	int x,y;
}b[1100];
int father[1100];
bool visit[1100];
int n,m,k;
int cmp ( const void*a, const void *b )
{
	ac *c = (ac*)a;
	ac *d = (ac*)b;
	return c->dis - d->dis >= 0.000 ? 1: -1;
}
void init ()
{
	int i;
	for ( i = 0; i <= n; i++ )
	{
		father[i] = i;
		visit[i] = false;
	}
}
int getFather( int x )
{
	while ( x != father[x] )
		x = father[x];
	return x;
}
void input ()
{	
	int i,j,x,y;
	k = 0;
	scanf("%d%d",&n,&m);
	init();
	for ( i = 0; i < n; i++ )
		scanf("%d%d",&b[i].x, &b[i].y);
	for ( i = 0; i < n-1; i++ )
	{
		for ( j = i+1; j < n; j++ )
		{
			a[k].x = i;
			a[k].y = j;
			a[k].dis = (b[i].x-b[j].x)*(b[i].x-b[j].x)+(b[i].y-b[j].y)*(b[i].y-b[j].y);
			a[k].dis = sqrt(a[k].dis);
			k++;
		}
	}
	qsort(a,k,sizeof(a[0]),cmp);
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		visit[x] = visit[y] = true;
		x = getFather(x);
		y = getFather(y);
		father[x] = y;
	}
}
void solve ()
{
	double ans = 0.0;
	int i,j=0;
	int x,y,fx,fy;
	for ( i = 0; i < n; i++ )
	{
		if ( visit[i] == false )
			j++;
	}
	i = 0;
	while ( i < k && j < n )
	{
		x = a[i].x;
		y = a[i].y;
		if ( visit[x] == false )
			fx = -1;
		else
			fx = getFather(x);
		if ( visit[y] == false )
			fy = -1;
		else
			fy = getFather(y);
		if ( fx == -1 && fy == -1 )
		{
			visit[x] = visit[y] = true;
			father[x] = y;
			j += 2;
			ans += a[i].dis;
		}
		else if ( fx == -1 )
		{
			visit[x] = true;
			father[x] = fy;
			j ++;
			ans += a[i].dis;
		}
		else if ( fy == -1 )
		{
			visit[y] = true;
			father[y] = fx;
			ans += a[i].dis;
		}
		else if ( fx != fy )
		{
			father[fx] = fy;
			ans += a[i].dis;
		}
		i++;
	}
	printf("%.2lf\n",ans);
}
int main ()
{
	input();
	solve();
	return 0;
}