#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
	_int64 x;
	double y;
	int i;
	int d;
	char ch[30];
	while ( scanf("%s",ch) )
	{
		x = _atoi64(ch);
		if ( x == 0 )
			break;
		if ( x < 0 )
		{
			x *= -1;
			for ( i = 31; i > 1; i-=2 )
			{
				y = pow(x,1.0/i);
				d = int (y );
				if ( y-d<1e-12 || d+1-y < 1e-12 )
					break;
				
			}
			printf("%d\n",i);
			continue;
		}
		for ( i = 32; i > 1; i-- )
		{
			y = pow(x,1.0/i);
			d = int ( y );
			if ( y - d < 1e-12|| d+1-y < 1e-12 )
			{
				break;}
		}
		printf("%d\n",i);
	}
	return 1;
}