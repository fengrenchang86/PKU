#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	long double n,m;
//	while (scanf("%ld %ld",&n,&m) != EOF)
//	{
//		n = pow(m,1/n);
//		printf("%ld\n",n);
//	}
	while(scanf("%lf%lf",&n,&m) && !(n==0&&m==0))
		printf("%.0lf\n",pow(n,m));
	return 1;
}