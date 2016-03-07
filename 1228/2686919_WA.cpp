#include <iostream>
#include <stdlib.h>
using namespace std;
const int max = 1200;
struct point
{
	int x;
	int y;
}p[max],up[max],down[max];//分别保存：所有的点，上凸包，下凸包
int cmp( const void *a , const void *b ) 
{ 
    struct point *c = (point *)a; 
    struct point *d = (point *)b; 
    if(c->x != d->x) return c->x - d->x; 
    else return d->y - c->y; 
}
int right ( point t[], int a, int b, int c )//判断t[a],t[b],t[c]是否右拐
{
	int m = (t[b].x-t[a].x)*(t[c].y-t[a].y)-(t[c].x-t[a].x)*(t[b].y-t[a].y);
	if ( m <= 0 )
		return 1;
	else
		return 0;
	return 0;
}
int make_up ( int n )
{
	int k,i;
	up[0] = p[0];
	up[1] = p[1];
	i = 2;
	k = 2;
	while ( i < n )
	{
		up[k] = p[i];
		while ( k > 1 && right(up,k-2,k-1,k) == 0 )
		{
			up[k-1] = up[k];
			k--;
		}
		k++;
		i++;
	}
	return k;
}
int make_down ( int n )
{
	int k,i;
	down[0] = p[n-1];
	down[1] = p[n-2];
	k = 2;
	i = n-3;
	while ( i >= 0 )
	{
		down[k] = p[i];
		while ( k > 1 && right(down,k-2,k-1,k) == 0 )
		{
			down[k-1] = down[k];
			k--;
		}
		k++;
		i--;
	}
	return k;
}

int main ()
{
	int i,j,n,tcase;
	int u,d;
	scanf("%d",&tcase);
	while ( tcase-- )
	{
		scanf("%d",&n);
		for ( i = 0; i < n; i++ )
			scanf("%d%d",&p[i].x,&p[i].y);
		qsort(p,n,sizeof(p[0]),cmp);
		if ( n == 1 )
		{
			cout<<"NO"<<endl;
			continue;
		}
		else if ( n == 2 )
		{
			cout<<"YES"<<endl;
			continue;
		}
		u = make_up(n);
		d = make_down(n);
		j = u;
		for ( i = 0; i < d; i++ )
		{
			if ( up[j-1].x != down[i].x || up[j-1].y != down[i].y )
				up[j++] = down[i];
		}
		j--;
		if ( up[j].x == up[0].x && up[j].y == up[0].y )
		{
			while ( up[j].x==up[0].x && up[j].y==up[0].y  )
				j--;
			j++;
		}
		up[j++] = up[0];
		up[j++] = up[1];
		n = j;
		for ( i = 1; i < n-1; i++ )
		{
			if ( up[i].x == up[i-1].x && up[i].x == up[i+1].x )
				break;
			else if ( (up[i].y-up[i-1].y)*(up[i+1].x-up[i].x) == (up[i+1].y-up[i].y)*(up[i].x-up[i-1].x) )
				break;
		}
		if ( i == n-1 )
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}