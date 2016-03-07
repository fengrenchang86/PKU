#include <iostream>
using namespace std;
int T[32][32];
int A[32][32];
int B[32][32];
int C[32][32];
int M[32][32];
int n,m,k;
void plus ( int a[][32], int b[][32], int c[][32] )
{
	int i,j;
	for ( i = 0; i < n; i++ )
		for ( j = 0; j <n; j++ )
		{
			c[i][j] = a[i][j]+b[i][j];
			c[i][j] %= m;
		}
}
void cheng ( int a[][32], int b[][32], int c[][32] )
{
	int i,j,k;
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			c[i][j] = 0;
			for ( k = 0; k < n; k++ )
			{
				c[i][j] += ( a[i][k]*b[k][j] );
				c[i][j] %= m;
			}
		}
	}
}
void pf ( int a[][32], int b[][32] )
{
	int i,j,k;
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			b[i][j] = 0;
			for ( k = 0; k < n; k++ )
			{
				b[i][j] += ( a[i][k]*a[k][j] );
				b[i][j] %= m;
			}
		}
	}
}
void mi ( int x, int a[][32] )
{
	int i,j;
	if ( x == 1 )
	{
		for ( i = 0; i < n; i++ )
			for ( j = 0; j < n; j++ )
				a[i][j] = T[i][j];
		return;
	}
	int b[32][32];
	int c[32][32];
	if ( x % 2 == 0 )
	{
		mi(x/2,c);
		pf(c,a);
	}
	else
	{
		mi(x-1,c);
		cheng(c,T,a);
	}
}
void f ( int x, int a[][32] )
{
	int i,j;
	if ( x == 1 )
	{
		for ( i = 0; i < n; i++ )
		{
			for ( j = 0; j < n; j++ )
				a[i][j] = T[i][j];
		}
		return;
	}
	int b[32][32];
	int c[32][32];
	if ( x % 2 == 0 )
	{
		f(x/2,b);
		mi(x/2,a);
		cheng(a,b,c);
		plus(c,b,a);
	}
	else
	{
		f(x-1,b);
		mi(x,c);
		plus(c,b,a);
	}
}
int main ()
{
	int i,j;
	scanf("%d%d%d",&n,&k,&m);
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j< n; j++ )
			scanf("%d",&T[i][j]);
	}
	f(k,A);
	for ( i = 0; i <n ;i++ )
	{
		for ( j = 0; j < n-1;j ++ )
			printf("%d ",A[i][j]);
		printf("%d\n",A[i][j]);
	}
	return 0;
}