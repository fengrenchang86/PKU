#include <iostream>
using namespace std;
int main ()
{
	int m,n;
	int k;
	int i;
	int ans;
	int a1;
	int a2;
	while ( scanf("%d %d",&m,&n)!=EOF )
	{
		a1 = n%10;
		a2 = (n-a1)/10;
		a2 = a2%4;
		for ( ans = m, i = 1; i < a1; i++ )
		{
			ans *= (m-i);
			while( ans%10==0 )
				ans/=10;
			ans %= 10;
		}
		for ( i = 1; i <= a2; i++ )
		{
			ans *= 8;
			while ( ans%10 == 0 )
				ans/=10;
			ans %= 10;
		}
		printf("%d\n",ans);
	}
	return 1;
}