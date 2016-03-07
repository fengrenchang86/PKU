#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
const int max = 100100;
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
	if ( m < 0 )
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
double area ()
{
	double k,x,y,h,s;
	if ( p[2].x == p[1].x)
		h = abs(p[1].x-p[0].x);
	else
	{
		k = double(p[2].y-p[1].y)/(p[2].x-p[1].x);
		x = (p[0].y-p[1].y+k*p[1].x+p[0].x/k)/(k+1.0/k);
		y = k*(x-p[1].x)+p[1].y;
		h = sqrt((x-p[0].x)*(x-p[0].x)+(y-p[0].y)*(y-p[0].y));
	}
	s = sqrt((p[1].x-p[2].x)*(p[1].x-p[2].x)+(p[1].y-p[2].y)*(p[1].y-p[2].y));
	s *= (0.5*h);
	return s;
}
int main ()
{
	int n,i,j;
	double s;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].x+=1000;
		p[i].y+=1000;
	}
	if ( n <= 2 )
	{
		cout<<0<<endl;
		return 0;
	}
	qsort(p,n,sizeof(p[0]),cmp);
	if ( n == 3 )
	{
		s = area();
		s /= 50;
		printf("%d\n",int(s));
		return 0;
	}
	j = make_up(n);
	s = 0;
	for ( i = 0; i < j-1; i++ )
		s += double(up[i].y+up[i+1].y)*(up[i+1].x-up[i].x)/2.0;
	j = make_down(n);
	for ( i = 0; i < j-1; i++ )
		s -= double(down[i].y+down[i+1].y)*(down[i].x-down[i+1].x)/2.0;
	s /= 50;
	printf("%d\n",int(s));
	return 0;
}