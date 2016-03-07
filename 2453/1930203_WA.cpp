#include <iostream>
using namespace std;
void f( int n, int c[], int a[] )
{
	int i;
	printf("%d: \n",n);
	for ( i = 22; i >= 0; i-- )
	{
		c[i] = n/a[i];
		n = n - c[i]*a[i];
		printf("%d",c[i]);
	}
	printf("\n");
}
void change ( int c[] )
{
	int i;
	for ( i = 0; i < 23; i++ )
	{
		if ( c[i] == 1 && c[i+1] == 0 )
		{
			c[i] = 0;
			c[i+1] = 1;
			break;
		}
	}
	i--;
	int h = 0;
	while ( c[i] == 1 )
	{
		c[i] = 0;
		h++;
		i--;
		if ( i == -1 )
			break;
	}
	for ( i = 0; i < h; i++ )
		c[i] = 1;
	for ( i = 22; i>=0; i-- )
		printf("%d",c[i]);
	printf("\n");
}
int g ( int c[], int a[] )
{
	int n = 0;
	int i;
	for ( i = 0; i < 23; i++ )
		n+= c[i]*a[i];
	return n;
}
int main ()
{
	int a[30];
	int c[30];
	int i;
	a[0] = 1;
	for ( i = 1; i <= 22; i++ )
		a[i] = a[i-1]*2;
	int n;
	while ( scanf("%d",&n) && n!=0 )
	{
		f( n, c, a );
		change( c );
		n = g(c,a);
		printf("%d\n",n);
	}
	return 1;
}