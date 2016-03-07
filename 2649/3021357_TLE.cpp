#include <iostream>
using namespace std;
int p[10000];
int t[10000];
int make ()
{
	int i,j,k=2;
	p[0] = 2;
	p[1] = 3;
	for ( i = 5; i < 65536; i+=2 )
	{
		for ( j = 3; j*j <= i; j+=2 )
		{
			if ( i % j == 0 )
				break;
		}
		if ( i % j != 0 )
			p[k++] = i;
	}
	return k;
}
void f ( int n, int x )
{
	int i,j;
	for ( i = 0; i < n; i++ )
	{
		j = p[i];
		t[i] = 0;
		while ( x % j == 0 )
		{
			x/=j;
			t[i]++;
		}
		if ( x == 1 )
			break;
	}
}
bool g ( int x, int n )
{
	int i,j,k;
	for ( i = 0; i < n; i++ )
	{
		t[i] -= x/p[i];
		if ( t[i] > 0 )
			return false;
	}
	return true;
}
int main ()
{
	int n = make();
	int x,y;
	while ( scanf("%d%d",&x,&y) != EOF )
	{
		f(n,y);
		if ( g(x,n) == true )
			printf("%d divides %d!\n",x,y);
		else
			printf("%d does not divide %d!\n",x,y);
	}
	return 0;
}