#include <iostream>
using namespace std;
int prime[400];
int x,y;
int makePrime ()
{
	int i,j,k=2;
	prime[0] = 2;
	prime[1] = 3;
	for ( i = 3; i <= 431; i+=2 )
	{
		for ( j = 3; j*j<=i; j+=2 )
		{
			if ( i % j == 0 )
				break;
		}
		if ( i % j != 0 )
			prime[k++] = i;
	}
	return k;
}
int f ( int n, int p )//return the numbers of number (<=n) that div p
{
	int k = 0,j=1,i=p;
	while ( j != 0 )
	{
		j = n/i;
		k+=j;
		i*=p;
	}
	return k;
}
void solve ()
{
	int n = makePrime();
	int i,j;
	__int64 ans;
	while ( cin>>x>>y )
	{
		ans = 1;
		for ( i = 0; i < n; i++ )
		{
			j = f(x,prime[i])-f(x-y,prime[i])-f(y,prime[i]);
			if ( j != 0 )
				ans *= (j+1);
		}
		printf("%I64d\n",ans);
	}
}
int main ()
{
	solve();
	return 0;
}