#include <iostream>
using namespace std;
int max ( int a, int b )
{
	return a>b?a:b;
}
int max ( int a, int b, int c )
{
	return max(max(a,b),max(b,c));
}
int main ()
{
	int x,t,w,i,j,n=1,pre=0,y;
	int a[1200];
	int c[1200][31];
	scanf("%d%d",&t,&w);
	pre = 1;
	a[1] = 0;
	for ( i = 1; i <= t; i++ )
	{
		scanf("%d",&x);
		if ( x != pre )
		{
			n++;
			a[n] = 1;
		}
		else
			a[n] ++;
		pre = x;
	}
	if ( n == 1 )
	{
		cout<<a[n]<<endl;
		return 0;
	}
	c[1][0] = a[1];
	c[2][1] = a[1]+a[2];
	y = a[1]+a[2];
	for ( i = 3; i <= n; i++ )
	{
		c[i][0] = c[i-2][0]+a[i];
		if ( c[i][0] > y )
			y = c[i][0];
		for ( j = 1; j <= w; j++ )
		{
			if ( i%2== j%2 )
				continue;
			c[i][j] = max(c[i-2][j],c[i-1][j-1])+a[i];
			if ( c[i][j] > y )
				y = c[i][j];
		}
	}
	cout<<y<<endl;
	return 0;
}