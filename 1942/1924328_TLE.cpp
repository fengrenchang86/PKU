#include <iostream>
using namespace std;
double c( unsigned int m, unsigned int n )
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
	int m,n;
	while ( scanf("%d %d",&m,&n) && !(m==0&&n==0) )
	{
		printf("%.0lf\n",c(m+n,m));
	}
	return 1;
}