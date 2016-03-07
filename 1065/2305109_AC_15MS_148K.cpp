#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int x;
	int y;
}a[5010];
int cmp ( const void *a, const void *b )
{ 
    struct ac *c = (ac *)a; 
    struct ac *d = (ac *)b; 
    if(c->x != d->x) return c->x - d->x; 
    else return c->y - d->y; 
}
int main ()
{
	int tcase;
	bool v[5010];
	int i,n;
	int t,c;
	int va,vb;
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		scanf("%d",&n);
		for ( i = 0; i < n;i++ )
		{
			scanf("%d%d",&a[i].x,&a[i].y);
			v[i] = false;
		}
		t = 0;
		c = 0;
		qsort(a,n,sizeof(a[0]),cmp);
		while ( t < n )
		{
			i = 0;
			while ( v[i] == true && i < n )
				i++;
			va = a[i].x;
			vb = a[i].y;
			v[i] = true;
			t++;
			c++;
			i++;
			while ( i < n )
			{
				if ( a[i].y >= vb && a[i].x >= va )
					if ( v[i] == false )
					{
						va = a[i].x;
						vb = a[i].y;
						t++;
						v[i] = true;
					}
				i++;
			}
		}
		cout<<c<<endl;
	}
	return 0;
}