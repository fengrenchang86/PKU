#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	double x;
	double y;
}a[20010];
int cmp( const void *a , const void *b ) 
{ 
    if((*(ac *)a).x != (*(ac *)b).x )
		return (*(ac *)a).x > (*(ac *)b).x ? 1:-1;
	else
		return (*(ac *)a).y > (*(ac *)b).y ? 1:-1;
} 
int main ()
{
	int n,i;
	bool flag;
	double midx,midy;
	while ( scanf("%d",&n) && n != 0 )
	{
		flag = false;
		for ( i = 0; i < n; i++ )
			scanf("%lf%lf",&a[i].x,&a[i].y);
		qsort(a,n,sizeof(a[0]),cmp);
		midx = a[0].x+a[n-1].x;
		midy = a[0].y+a[n-1].y;
		for ( i = 2; n-1-i > i; i++ )
		{
			if ( a[i].x+a[n-i-1].x == midx && a[i].y+a[n-i-1].y == midy )
			{
				flag = true;
				break;
			}
		}
		if ( n%2==1 )
		{
			if ( a[(n-1)/2].x*2 != midx || a[(n-1)/2].y*2 != midy )
				flag = false;
		}
		if ( flag == true )
			printf("V.I.P. should stay at (%.1lf,%.1lf).\n",midx/2.0,midy/2.0);
		else
			printf("This is a dangerous situation!\n");
	}
	return 0;
}