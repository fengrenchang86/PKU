#include <iostream>
using namespace std;
struct ac
{
	int x;
	int y;
}a[50010];
int cmp( const void *a , const void *b ) 
{ 
    struct ac *c = (ac *)a; 
    struct ac *d = (ac *)b; 
    if(c->x != d->x) return c->x - d->x; 
    else return c->y - d->y; 
} 
int main ()
{
	int i,n;
	int va,vb;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
		scanf("%d%d",&a[i].x,&a[i].y);
	qsort(a,n,sizeof(a[0]),cmp);
	va = a[0].x;
	vb = a[0].y;
	int t;
	for ( i = 1; i < n; i++ )
	{
		if ( a[i].x > vb )
		{
			printf("%d %d\n",va,vb);
			va = a[i].x;
			vb = a[i].y;
		}
		else
		{
			vb = a[i].y;
		}
	}
	printf("%d %d\n",va,vb);
	return 0;
}