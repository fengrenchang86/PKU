#include <iostream>
using namespace std;
int main ()
{
	int wide,i,x,y;
	int high,maxh,sum,maxw;
	while ( scanf("%d",&wide) != EOF )
	{
		if ( wide == 0 )
			break;
		maxw = 0;
		high = 0;
		maxh = 0;
		sum = 0;
		while ( scanf("%d%d",&x,&y) )
		{
			if ( x== -1 && y== -1 )
				break;
			if ( maxw < sum )
				maxw = sum;
			if ( sum + x > wide )
			{
				high += maxh;
				sum = x;
				maxh = y;
				continue;
			}
			sum += x;
			if ( maxw < sum )
				maxw = sum;
			if ( maxh < y )
				maxh = y;
		}
		high += maxh;
		printf("%d x %d\n",maxw,high);
	}
	return 0;
}