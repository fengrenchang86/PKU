#include <iostream>
#include <stdlib.h>
using namespace std;

struct ac
{
	int x,y,s;
}a[120],t1,t2;
int cmp( const void *a ,const void *b) 
{ 
     return (*(ac *)a).s - (*(ac *)b).s;
} 
int main ()
{
	int n,w,d;
	int id,count;
	int i,j,k,c;
	while ( scanf("%d%d%d",&n,&w,&d) && !(n==0&&w==0&&d==0) )
	{
		a[1].x = w;
		a[1].y = d;
		a[1].s = w*d;
		for ( i = 1; i <= n; i++ )
		{
			scanf("%d%d",&id,&count);
			count %= 2*(a[id].x+a[id].y);
			j = k = 1;
			c = 0;
			while ( c < count )
			{
				if ( k == 1 && j <= a[id].x )
					j++;
				else if ( j == a[id].x+1 && k <= a[id].y )
					k++;
				else if ( k == a[id].y+1 && j > 1 )
					j--;
				else
					k--;
				c++;
			}
			if ( k == 1 || k == a[id].y+1 )
			{
				t1.x = j-1;
				t1.y = a[id].y;
				t1.s = t1.x*t1.y;
				t2.x = a[id].x-j+1;
				t2.y = a[id].y;
				t2.s = t2.x*t2.y;
			}
			else
			{
				t1.x = a[id].x;
				t1.y = k-1;
				t1.s = t1.x*t1.y;
				t2.x = a[id].x;
				t2.y = a[id].y-k+1;
				t2.s = t2.x*t2.y;
			}
			for ( j = id; j <= i-1; j++ )
				a[j] = a[j+1];
			if ( t1.x*t1.y < t2.x*t2.y)
			{
				a[i] = t1;
				a[i+1] = t2;
			}
			else
			{
				a[i] = t2;
				a[i+1] = t1;
			}
		}
		a[0].s = 0;
		qsort(a,n+2,sizeof(a[0]),cmp);
		for ( i = 1; i <= n; i++ )
			printf("%d ",a[i].s);
		printf("%d\n",a[n+1].s);
	}
	return 0;
}