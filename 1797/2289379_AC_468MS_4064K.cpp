#include <iostream>
using namespace std;
int a[1002][1002];
int v[1002];
int c[1002];
int que[11000000];
void init ( int n )
{
	int i,j;
	for ( i = 0; i <= n; i++ )
	{
		for ( j = 0; j <= n; j++ )
			a[i][j] = 11000000;
		v[i] = 0;
		c[i] = 0;
	}
	v[1] = 1;
	c[1] = 0;
}
int min ( int a, int b )
{
	return a < b ? a : b;
}
int main ()
{
	int m,n,i,j;
	int begin,end;
	int tcase,it;
	int x,y,d;
	cin>>tcase;
	for ( it = 1; it <= tcase; it++ )
	{
		scanf("%d%d",&n,&m);
		init(n);
		for ( i = 0; i < m; i++ )
		{
			scanf("%d%d%d",&x,&y,&d);
			a[x][y] = d;
			a[y][x] = d;
		}
		printf("Scenario #%d:\n",it);
		begin = 0;
		end = 0;
		x = 1;
		for ( i = 2; i <= n; i++ )
		{
			if ( a[i][1] != 11000000 )
				c[i] = a[i][1];
		}
		for ( i = 1; i < n; i++ )
		{
			y = 0;
			for ( j = 2; j <= n; j++ )
			{
				if ( v[j] != 1 && c[j] > y )
				{
					y = c[j];
					x = j;
				}
			}
			v[x] = 1;
			for ( j = 2; j <= n; j++ )
			{
				if ( v[j] == 0 && a[x][j] != 11000000 )
				{
					d = min ( c[x], a[j][x] );
					if ( d > c[j] )
						c[j] = d;
				}
			}
		}
		cout<<c[n]<<endl;
		cout<<endl;
	}
	return 0;
}