#include <iostream>
using namespace std;
int main ()
{
	int i;
	int j;
	int x,y;
	int h[101][2];
	int front;
	int tail;
	short a[105][105];
	int n;
	bool yes;
	while ( scanf("%d",&n) && n!=0 )
	{
		yes = true;
		for ( i = 1; i <= n; i++ )
			for ( j = 1; j <= n; j++ )
				a[i][j] = n;
		for ( i = 1; i < n; i++ )
		{
			front = 0;
			tail = 0;
			for ( j = 0; j < n; j++ )
			{
				scanf("%d %d",&x,&y);
				a[x][y] = i;
			}
			if ( yes == false )
				continue;
			h[tail][0] = x;
			h[tail++][1] = y;
			while ( front < tail )
			{
				x = h[front][0];
				y = h[front++][1];
				if ( a[x+1][y] == i )
				{
					h[tail][0] = x+1;
					h[tail++][1] = y;
					a[x+1][y]*=-1;
				}
				if ( a[x][y+1] == i )
				{
					h[tail][0] = x;
					h[tail++][1] = y+1;
					a[x][y+1]*=-1;
				}
				if ( a[x-1][y] == i )
				{
					h[tail][0] = x-1;
					h[tail++][1] = y;
					a[x-1][y]*=-1;
				}
				if ( a[x][y-1] == i )
				{
					h[tail][0] = x;
					h[tail++][1] = y-1;
					a[x][y-1]*=-1;
				}
			}
			if ( front != n+1 )
				yes = false;
		}
		for ( i = 1; i <=n ; i++ )
		{
			for ( j = 1; j <= n; j++ )
			{
				if ( a[i][j] == n )
					break;
			}
			if ( a[i][j] == n )
				break;
		}
		front = tail = 0;
		h[tail][0] = i;
		h[tail++][1] = j;
		if ( yes == true )
		while ( front < tail )
		{
			x = h[front][0];
			y = h[front++][1];
			if ( a[x+1][y] == n )
			{
				h[tail][0] = x+1;
				h[tail++][1] = y;
				a[x+1][y]*=-1;
			}
			if ( a[x][y+1] == n )
			{
				h[tail][0] = x;
				h[tail++][1] = y+1;
				a[x][y+1]*=-1;
			}
			if ( a[x-1][y] == n )
			{
				h[tail][0] = x-1;
				h[tail++][1] = y;
				a[x-1][y]*=-1;
			}
			if ( a[x][y-1] == n )
			{
				h[tail][0] = x;
				h[tail++][1] = y-1;
				a[x][y-1]*=-1;
			}
		}
		if ( front != n+1 )
			yes = false;
		if ( yes == true )
			printf("good\n");
		else
			printf("wrong\n");
	}
	return 1;
}