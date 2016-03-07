#include <iostream>
using namespace std;
_int64 f ( int k, int n )
{
	_int64 mod =0;
	if ( n >= k )
	{
		int i;
		for ( i = 1; i<=k ; i++ )
		{
			mod += k%i;
		}
		mod += _int64((n-k)*k);
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
	_int64 t;
	int n,k;
	while ( scanf("%d%d",&n,&k) !=EOF )
	{
		t = f(k,n);
		printf("%I64d\n",t );
	}
	return 1;
}