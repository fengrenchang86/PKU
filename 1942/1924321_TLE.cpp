#include <iostream>
using namespace std;
unsigned int c( unsigned int m, unsigned int n )
{
	unsigned int ans = 1;
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
		printf("%d\n",c(m+n,m));
	}
	return 1;
}