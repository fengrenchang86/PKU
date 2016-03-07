#include <iostream>
using namespace std;
int a[11][11];
int f ( int sum, int max, int lay )
{
	if ( sum > 10 || lay > 10 )
		return 1;
	a[lay][sum]++;
	if ( sum == 10 || lay == 10 )
		return 1;
	for ( int i = max; i <= 10; i++ )
		f(sum+i,i,lay+1);
	return 1;
}
int main ()
{
	int tcase, it;
	int i,j;
	int m,n;
	for ( i = 0; i <= 10; i++ )
		for ( j = 0; j <= 10; j++ )
			a[i][j] = 0;
	f(0,0,0);
	scanf("%d",&tcase);
	for ( it = 0; it < tcase; it++ )
	{
		scanf("%d%d",&m,&n);
		printf("%d\n",a[n][m]);
	}
	return 0;
}