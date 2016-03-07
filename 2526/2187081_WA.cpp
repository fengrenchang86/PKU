#include <iostream>
#include <stdlib.h>
using namespace std;
struct point
{
	int x;
	int y;
}a[11000];
int cmp( const void *a , const void *b ) 
{ 
    struct point *c = (point *)a; 
    struct point *d = (point *)b; 
    if(int(c->x) != int(d->x)) return int(c->x) - int(d->x); 
    else return int(d->y) - int(c->y); 
} 
int main ()
{
	bool yes;
	int tcase,it;
	int x,y;
	int n,i;
	cin>>tcase;
	for ( it = 0; it < tcase; it++ )
	{
		yes = true;
		cin>>n;
		for ( i = 0; i < n; i++ )
			scanf("%d%d",&a[i].x,&a[i].y);
		qsort(a,n,sizeof(a[0]),cmp);
		x = a[0].x+a[n-1].x;
		y = a[0].y+a[n-1].y;
		for ( i = 1; i <= n/2-1; i++ )
		{
			if ( a[i].x+a[n-1-i].x != x || a[i].y+a[n-1-i].y != y )
			{
				yes = false;
				break;
			}
		}
		if ( yes == true )
		{
			if ( n%2==1 && x==a[n/2].x && y==a[n/2].y || n%2==0 )
				cout<<"yes"<<endl;
		}
		else
			cout<<"no"<<endl;
	}
	return 0;
}