#include <iostream>
using namespace std;
int main ()
{
	double s;
	int i;
	int n;
	double w;
	while ( scanf("%lf",&w)!=EOF )
	{
		if ( w == 0.0 )
			break;
		s = 0.0;
		for ( i = 2; s < w; i++ )
		{
			s += 1.0/i;
		}
		printf("%d card(s)\n",i-2);
	}
	return 1;
}