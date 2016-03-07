#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	double exa,pre,fmin;
	int tc=0,x,y,i,j,k;
	while ( cin>>x>>y )
	{
		exa = double(x)/double(y);
//		if (tc!=0)
//			printf("\n");
		tc++;
		k = 1;
		fmin = fabs(exa-1.0);
		for ( i = 2; i <= 5000; i++ )
		{
			if ( fabs(exa-double(i)) < fmin )
			{
				k = i;
				fmin = fabs(exa-double(i));
			}
		}
		printf("%d/%d\n",k,1);
		for ( i = 2; i <= y; i++ )
		{
			k = -1;
			j = x*i/y-1;
			if ( j <= 0 )
				j = 1;
			if ( fabs(double(double(j)/double(i)-exa)) < fmin )
			{
				k = j;
				fmin = fabs(double(double(j)/double(i)-exa));
			}
			j++;
			if ( fabs(double(double(j)/double(i)-exa)) < fmin )
			{
				k = j;
				fmin = fabs(double(double(j)/double(i)-exa));
			}
			j++;
			if ( fabs(double(double(j)/double(i)-exa)) < fmin )
			{
				k = j;
				fmin = fabs(double(double(j)/double(i)-exa));
			}
			j++;
			if ( k != -1 )
				printf("%d/%d\n",k,i);
		}
		printf("\n");
	}
	return 0;
}