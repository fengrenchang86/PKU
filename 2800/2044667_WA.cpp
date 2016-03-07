#include <iostream>
using namespace std;

int f ( int k, int n )
{
	int t = k/2;
	int mod = 0;
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
	return mod;
}
int main ()
{
	int sum;
	int mod;
	int p,t;
	int n,k;
	while ( scanf("%d%d",&n,&k) !=EOF )
	{
		if ( k%2 == 0 )
			sum = k/2*(k+1);
		else
			sum = (k+1)/2*k;
		t = f(k,n);
		printf("%d\n",t );
	}
	return 1;
}