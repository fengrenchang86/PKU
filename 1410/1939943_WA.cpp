#include <iostream>
using namespace std;
int main ()
{
	int xbegin,xend,ybegin,yend;
	int x1,x2,y1,y2;
	int temp;
	int n,i;
	double k;
	double x[2],y[2];
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d %d %d %d %d %d %d %d",&xbegin,&ybegin,&xend,&yend,&x1,&y1,&x2,&y2);
		if ( x1 > x2 )
		{
			temp = x1;
			x1 = x2;
			x2 = temp;
		}
		if ( y1 < y2 )
		{
			temp = y1;
			y1 = y2;
			y2 = temp;
		}
		if ( xbegin == xend )
		{
			if ( y1<=ybegin&&y1>=yend || y1>=ybegin&&y1<=yend)
				printf("T\n");
			else if ( y2 <=ybegin&&y2>=yend || y2 >=ybegin&&y2<=yend)
				printf("T\n");
			else
				printf("F\n");
			continue;
		}
		k = (yend-ybegin)/(xend-xbegin);
		y[0] = yend + k * ( x1 - xend );
		y[1] = yend + k * ( x2 - xend );
		x[0] = ( y1 - yend ) / k + xend;
		x[1] = ( y2 - yend ) / k + xend;
		if ( (x[0] < x1 || x[0] > x2) && (x[1] < x1 || x[1] > x2) && 
			(y[0] < y2 || y[0] > y1) && (y[1] < y2 || y[1] > y2))
			printf("F\n");
		else if ( x[0] >= x1 && x[0] <= x2 && (x[0]>=xbegin&&x[0]<=xend || x[0]>=xend&&x[0]<=xbegin) )
			printf("T\n");
		else if ( x[1] >= x1 && x[1] <= x2 && (x[1]>=xbegin&&x[1]<=xend || x[1]>=xend&&x[1]<=xbegin) )
			printf("T\n");
		else if ( y[0] >= y2 && y[0] <= y1 && (y[0]>=ybegin&&y[0]<=yend || y[0]>=yend&&y[0]<=ybegin) )
			printf("T\n");
		else if ( y[1] >= y2 && y[1] <= y1 && (y[1]>=ybegin&&y[1]<=yend || y[1]>=yend&&y[1]<=ybegin) )
			printf("T\n");
		else
			printf("F\n");
	}
	return 1;
}