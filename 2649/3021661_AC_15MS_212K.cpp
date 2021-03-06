#include <iostream>
using namespace std;
int p[66000];
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
bool f ( int n, int y, int x )
{
	int i,j,k=x;
	int t;
	for ( i = 0; i < n; i++ )
	{
		j = p[i];
		t = 0;
		while ( y % j == 0 )
		{
			y/=j;
			t++;
		}
		x = k;
		while ( x >= p[i] )
		{
			t -= x/p[i];
			x/=p[i];
		}
		if ( t > 0 )
			return false;
		if ( y == 1 )
			break;
	}
	if ( k <= y )
		return false;
	else
		return true;
}

int main ()
{
	int n = make();
	int x,y;
	while ( scanf("%d%d",&x,&y) != EOF )
	{
		if(y==0)
			printf("0 does not divide %d!\n",x);
		else if ( x >= y )
			printf("%d divides %d!\n",y,x);
		else if ( f(n,y,x) == true )
			printf("%d divides %d!\n",y,x);
		else
			printf("%d does not divide %d!\n",y,x);
	}
	return 0;
}