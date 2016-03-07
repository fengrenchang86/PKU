#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
	_int64 x;
	int y;
	int i;
	char ch[30];
	while ( scanf("%s",ch) )
	{
		x = _atoi64(ch);
		if ( x == 0 )
			break;
		if ( x < 0 )
		{
			printf("1\n");
			continue;
		}
		for ( i = 32; i > 1; i-- )
		{
			y = pow(x,1.0/i);
			if ( pow(y,i) == x )
				break;
		}
		printf("%d\n",i);
	}
	return 1;
}