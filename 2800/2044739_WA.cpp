#include <iostream>
using namespace std;
_int64 f ( int k, int n )
{
	_int64 mod =0;
	if ( n >= k )
	{
		int t = k/2;
		int i;
		for ( i = 1; i<=k ; i++ )
		{
			mod += k%i;
		}
		mod += (n-k)*k;
	}
	else
	{
		int i;
		for ( i =1; i <= n; i++ )
			mod += k%i;
	}
	return mod;
}

int main ()
{
	int sum;
	_int64 t;
	int n,k;
	while ( scanf("%d%d",&n,&k) !=EOF )
	{
		if ( k%2 == 0 )
			sum = k/2*(k+1);
		else
			sum = (k+1)/2*k;
		t = f(k,n);
		printf("%I64d\n",t );
	}
	return 1;
}