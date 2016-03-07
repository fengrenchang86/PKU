#include <iostream>
#include <math.h>
using namespace std;
double a[2200],b[2200];
int main ()
{
	int n,m,i,j;
	double s,tmin;
//	while (	scanf("%d%d",&n,&m) )
	scanf("%d%d",&n,&m);
	{
		m += n;
		s = 10000.0/double(n);
		a[0] = b[0] = 0.0;
		for ( i = 1; i < n; i++ )
			a[i] = a[i-1]+s;
		s = 10000.0/double(m);
		for ( i = 1; i < m; i++ )
			b[i] = b[i-1]+s;
		s = 0.0;
		i = 1;
		j = 1;
		tmin = 2000000.0;
		while ( i < n && j < m )
		{
			if ( fabs(a[i]-b[j]) < tmin )
			{
				tmin = fabs(a[i]-b[j]);
				j++;
			}
			else
			{
				s += tmin;
				tmin = 2000000.0;
				i++;
			}
		}
		if ( tmin < 2000000 )
			s += tmin;
		printf("%.4lf\n",s);
	}
	return 0;
}