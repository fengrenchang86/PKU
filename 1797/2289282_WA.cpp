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
	int m,n,i;
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
		for ( i = 2; i <= n; i++ )
		{
			if ( a[i][1] != 11000000 )
			{
				que[end++] = i;
				c[i] = a[i][1];
			}
		}
		while ( begin < end )
		{
			x = que[begin];
			begin++;
			for ( i = 2; i < n; i++ )
			{
				if ( a[i][x] == 11000000 )
					continue;
				d = min(a[i][x],c[i]);
				if ( d > c[i] )
				{
					c[i] = d;
					que[end++] = i;
				}
			}
		}
		cout<<c[n]<<endl;
	}
	return 0;
}