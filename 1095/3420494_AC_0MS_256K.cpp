#include <iostream>
using namespace std;
__int64 t[30];
__int64 sum[30];
void init ()
{
	t[0] = 1;
	sum[0] = 0;
	t[1] = 1;
	sum[1] = 1;
	int i,j,k;
	for ( k = 2; k <= 18 ;k++ )
	{
		t[k] = 0;
		for ( i = 0; i < k; i++ )
		{
			j = k-i-1;
			t[k] += t[i]*t[j];
		}
		sum[k] = sum[k-1]+t[k];
	}
/*	for ( i = 1; i <= 18; i++ )
	{
		printf("t[%2d]=%d  ",i,t[i]);
		printf("sum[%2d]=%d\n",i,sum[i]);
	}*/
}
int findn ( int key )
{
	int i=1;
	for ( i = 1; i <= 18; i++ )
	{
		if ( sum[i] >= key )
			break;
	}
	return i;
}
void print ( int n, int k )
{
	if ( k == 0 )
		return;
	if ( n == 1 )
	{
		printf("X");
		return;
	}
	int m = k;
	int i,j;
	for ( i = 0; i < n; i++ )
	{
		j = n-i-1;
		if ( m > t[i]*t[j] )
			m-=t[i]*t[j];
		else
			break;
	}
	if ( i != 0 && m != 0 )
	{
		if ( m != 0 )
			k = (m-1)/t[j]+1;
		else
			k = 0;
		printf("(");
		print(i,k);
		printf(")");
		
	}
	printf("X");
	if ( j != 0 )
	{
		printf("(");
		k = m%t[j];
		if ( k == 0 )
			k += t[j];
		print(j,k);
		printf(")");
	}
}
int main ()
{
	init();
	int n,k;
	while ( cin>>n && n )
	{
		k = findn(n);
		print(k,n-sum[k-1]);
		printf("\n");
	}
	return 0;
}