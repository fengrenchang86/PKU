#include <iostream>
using namespace std;
struct ac
{
	int x,y;
}Q[120],K[120],P[120];
int b[1010][1010];
int a[1010][1010];
int n,m,q,k,p;
int it=1;
void init ()
{
	int i,j;
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= m; j++ )
		{
			a[i][j] = b[i][j] = 0;
		}
	}
}
void input ()
{
	int i,x,y;
	scanf("%d",&q);
	for ( i = 0; i < q; i++ )
	{
		scanf("%d%d",&x,&y);
		Q[i].x = x;
		Q[i].y = y;
		b[x][y] = 1;
	}
	scanf("%d",&k);
	for ( i = 0; i < k; i++ )
	{
		scanf("%d%d",&x,&y);
		K[i].x = x;
		K[i].y = y;
		b[x][y] = 2;
	}
	scanf("%d",&p);
	for ( i = 0; i < p; i++ )
	{
		scanf("%d%d",&x,&y);
		P[i].x = x;
		P[i].y = y;
		b[x][y] = 3;
	}
}
void solve () 
{
	int cni,i,j;
	int x,y;
	for ( cni = 0; cni < q; cni++ )
	{
		x = Q[cni].x-1;
		y = Q[cni].y;
		while ( x >= 1 && b[x][y] == 0 )
		{
			a[x][y] = 1;
			x--;
		}
		x = Q[cni].x+1;
		while ( x <= n && b[x][y] == 0 )
		{
			a[x][y] = 1;
			x++;
		}
		x = Q[cni].x;
		y = Q[cni].y+1;
		while ( y <= m && b[x][y] == 0 )
		{
			a[x][y] = 1;
			y++;
		}
		y = Q[cni].y-1;
		while ( y >= 1 && b[x][y] == 0 )
		{
			a[x][y] = 1;
			y--;
		}
		x = Q[cni].x-1;
		y = Q[cni].y-1;
		while ( x >= 1 && y >=1 && b[x][y] == 0 )
		{
			a[x][y] = 1;
			x--;
			y--;
		}
		x = Q[cni].x-1;
		y = Q[cni].y+1;
		while ( x >= 1 && y <= m && b[x][y] == 0 )
		{
			a[x][y] = 1;
			x--;
			y++;
		}
		x = Q[cni].x+1;
		y = Q[cni].y-1;
		while ( x <= n && y >= 1 && b[x][y] == 0 )
		{
			a[x][y] = 1;
			x++;
			y--;
		}
		x = Q[cni].x+1;
		y = Q[cni].y+1;
		while ( x <= n && y <= m && b[x][y] == 0 )
		{
			a[x][y] = 1;
			x++;
			y++;
		}
	}
	for ( cni = 0; cni < k; cni++ )
	{
		x = K[cni].x;
		y = K[cni].y;
		if ( x-1 >= 1 && y-2 >= 1 && b[x-1][y-2] == 0 )
			a[x-1][y-2] = 1;
		if ( x-1 >= 1 && y+2 <= m && b[x-1][y+2] == 0 )
			a[x-1][y+2] = 1;
		if ( x+1 <= n && y-2 >= 1 && b[x+1][y-2] == 0 )
			a[x+1][y-2] = 1;
		if ( x+1 <= n && y+2 <= m && b[x+1][y+2] == 0 )
			a[x+1][y+2] = 1;
		if ( x-2 >= 1 && y-1 >= 1 && b[x-2][y-1] == 0 )
			a[x-2][y-1] = 1;
		if ( x-2 >= 1 && y+1 <= m && b[x-2][y+1] == 0 )
			a[x-2][y+1] = 1;
		if ( x+2 <= n && y-1 >= 1 && b[x+2][y-1] == 0 )
			a[x+2][y-1] = 1;
		if ( x+2 <= n && y+1 <= m && b[x+2][y+1] == 0 )
			a[x+2][y+1] = 1;
	}
	int ans = 0;
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= m; j++ )
		{
			if ( b[i][j] == 0 && a[i][j] == 0 )
				ans++;
		}
	}
	printf("Board %d has %d safe squares.\n",it++,ans);
}
int main ()
{
	while ( scanf("%d%d",&n,&m) != EOF )
	{
		if ( n == 0 && m == 0 )
			break;
		init();
		input();
		solve();
	}
	return 0;
}