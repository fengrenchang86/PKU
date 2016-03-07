#include <iostream>
using namespace std;
int a[500];
int n;
int b[500];
int c[500];
int factor(int);
int prime[5000000];
int pm;
void makeprime ( )
{
	int i,j,k=2;
	prime[0] = 2;
	prime[1] = 3;
	for ( i = 5; i*i < 5000000; i+=2 )
	{
		for ( j = 3; j*j <= i; j+=2 )
		{
			if ( i % j == 0 )
				break;
		}
		if ( i % j != 0 )
			prime[k++] = i;
	}
	pm = k;
}
void init ()
{
	int i;
	for ( i = 0; i < 500; i++ )
		c[i] = -1;
	for ( i = 1; i <= 100; i++ )
		b[i] = i*i*i;
}
void make ( int m )
{
	int i;
	n = 0;
	for ( i = 1; i*i < m; i++ )
	{
		if ( m % i == 0 )
		{
			a[n++] = i;
			a[n++] = m/i;
		}
	}
	if ( i*i == m )
		a[n++] = i;
//	printf(" the num %d has %d factor\n",m,n);
}
int factor( int m )
{
	if ( m == 1 )
		return 1;
	else if ( m < 500 && c[m] != -1 )
		return c[m];
	int i,k = 0,sum=1;
	for ( i = 0; i < pm; i++ )
	{
		k = 0;
		while ( m % prime[i] == 0 )
		{
			k++;
			m/=prime[i];
		}
		if ( k > 0 )
		{
			k++;
			sum *= k;
		}
	}
	return sum;
}
void solve ( )
{
	int m,i,k;
	scanf("%d",&m);
	make(m);
	int x=0;
	for ( i = 0; i < n; i++ )
	{
		k = factor(a[i]);
		x += b[k];
	}
	printf("%d\n",x);
}
int main ()
{
	init();
	makeprime();
	int tc;
	scanf("%d",&tc);
	while ( tc-- )
		solve();
	return 0;
}