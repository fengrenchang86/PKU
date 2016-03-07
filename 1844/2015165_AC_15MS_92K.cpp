#include <iostream>
#include <math.h>
using namespace std;
int f ( int x )
{
	return x*(x+1)/2;
}
int main ()
{
	int n;
	int x;
	int sum;
	while ( scanf("%d",&n)!=EOF )
	{
		x = (sqrt(1+8*n)-1)/2;
		while ( f(x) < n )
			x++;
		if ( f(x) == n )
			printf("%d\n",x);
		else
		{
			while ( (f(x)-n)%2 != 0 )
				x++;
			printf("%d\n",x);
		}
	}
	return 1;
}