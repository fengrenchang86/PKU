/*#include <iostream>
using namespace std;
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
int n;
int main ()
{
	int i,j,k;
	while ( cin>>n && n)
	{
		k = 0;
		for ( i = 1; i < n; i++ )
		{
			for ( j = i+1; j <= n; j++ )
				k += gcd(i,j);
		}
		cout<<k<<endl;
	}
	return 0;
}
*/
#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
const int tmax = 1010;
const double pi = 3.1415926535897932384626433832795;
struct point
{
	int x;
	int y;
}p[tmax],up[tmax],down[tmax];//分别保存：所有的点，上凸包，下凸包
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
int main ()
{
	double t;
	int i,n,l;
	int k,s1,s2;
	scanf("%d%d",&n,&l);
	for ( i = 0; i < n; i++ )
		scanf("%d%d",&p[i].x,&p[i].y);
	qsort(p,n,sizeof(p[0]),cmp);
	s1 = make_up(n);
	s2 = make_down(n);
	k = s2;
	for ( i = 1; i < s1-1; i++ )
		down[k++] = up[i];
	t = 0;
	for ( i = 1; i < k; i++ )
		t += sqrt(double(down[i].x-down[i-1].x)*double(down[i].x-down[i-1].x)+double(down[i].y-down[i-1].y)*double(down[i].y-down[i-1].y));
	t += sqrt(double(down[k-1].x-down[0].x)*double(down[k-1].x-down[0].x)+double(down[k-1].y-down[0].y)*double(down[k-1].y-down[0].y));
	t += 2*l*pi;
	printf("%.0lf\n",t);
	return 0;
}
