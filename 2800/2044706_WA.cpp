#include <iostream>
using namespace std;
double f ( int k, int n )
{
	double mod =0;
	if ( n >= k )
	{
		int t = k/2;
		int i;
		for ( i = 1; i<=t; i++ )
		{
			mod += k%i;
		}
		i = (k-1)/2;
		if ( i%2==0 )
			t = i/2*(i+1);
		else
			t =(i+1)/2*i;
		mod += t;
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
	double t;
	int n,k;
	while ( scanf("%d%d",&n,&k) !=EOF )
	{
		if ( k%2 == 0 )
			sum = k/2*(k+1);
		else
			sum = (k+1)/2*k;
		t = f(k,n);
		printf("%.0lf\n",t );
	}
	return 1;
}