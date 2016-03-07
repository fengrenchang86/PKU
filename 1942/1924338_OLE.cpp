#include <iostream>
using namespace std;
double c( double m, double n )
{
	double ans = 1;
	int i;
	
	for ( i = 1; i <= n; i++ )
	{
		ans = ans*(m+1-i)/i;
	}
	return ans;
}
int main ()
{
	double m,n;
	while ( scanf("%f %f",&m,&n) && !(m==0&&n==0) )
	{
		printf("%.0lf\n",c(m+n,m<n?m:n));
	}
	return 1;
}