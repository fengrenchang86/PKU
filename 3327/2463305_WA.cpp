#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp ( const void *a , const void *b ) 
{ 
     return *(int *)a - *(int *)b; 
} 
struct ac
{
	int x1,y1,x2,y2;
}a[120];
int b[120];
int main ()
{
	int n,w,d;
	int i,j,k;
	int id,count,c;
//	int x,y;
	while ( scanf("%d%d%d",&n,&w,&d)&&!(n==0&&w==0&&d==0) )
	{
		a[1].x1 = 1;
		a[1].y1 = 1;
		a[1].x2 = w+1;
		a[1].y2 = d+1;
		for ( i = 1; i <= n; i++ )
		{
			scanf("%d%d",&id,&count);
			j = a[id].x1;
			k = a[id].y1;
			c = 0;
			while ( c < count )
			{
				if ( j < a[id].x2 && k == a[id].y1)
					j++;
				else if ( k < a[id].y2 && j == a[id].x2)
					k++;
				else if ( j > 1 && k == a[id].y2 )
					j--;
				else
					k--;
				c++;
			}
			if ( j == a[id].x1 || j == a[id].x2 )
			{
				if ( k - a[id].y1 < a[id].y2-k )
				{
					a[i+1].x1 = a[id].x1;
					a[i+1].y1 = k;
					a[i+1].x2 = a[id].x2;
					a[i+1].y2 = a[id].y2;
					a[id].y2 = k;
				}
				else
				{
					a[i+1].x1 = a[id].x1;
					a[i+1].y1 = a[id].y1;
					a[i+1].x2 = a[id].x2;
					a[i+1].y2 = k;
					a[id].y1 = k;
				}
			}
			else
			{
				if ( j-a[id].x1 > a[id].x2 -j )
				{
					a[i+1].x1 = a[id].x1;
					a[i+1].y1 = a[id].y1;
					a[i+1].x2 = j;
					a[i+1].y2 = a[id].y2;
					a[id].x1 = j;
				}
				else
				{
					a[i+1].x1 = j;
					a[i+1].y1 = a[id].y1;
					a[i+1].x2 = a[id].x2;
					a[i+1].y2 = a[id].y2;
					a[id].x2 = j;
				}
			}
		}
		for ( i = 1; i <= n+1; i++ )
			b[i] = (a[i].x2-a[i].x1)*(a[i].y2-a[i].y1);
		b[0] = 0;
		qsort(b,n+2,sizeof(b[0]),cmp);
		for ( i = 1; i <= n+1; i++ )
			printf("%d ",b[i]);
		printf("\n");
	}
	return 0;
}