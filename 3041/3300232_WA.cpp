#include <iostream>
using namespace std;
bool c[510][510];
int row[510];
int col[510];
int bx,by,z;
bool f ( int n )
{
	int i,j,k=0;
	for ( i = 1; i <= n; i++ )
		row[i] = col[i] = 0;
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= n; j++ )
		{
			if ( c[i][j] == true )
			{
				row[i]++;
				col[j]++;
				if ( row[i] > k )
				{
					k = row[i];
					bx = i;
					by = j;
					z = 1;
				}
				if ( col[j] > k )
				{
					k = row[i];
					bx = i;
					by = j;
					z = 2;
				}
			}
		}
	}
	if ( k == 0 )
		return false;
	else
		return true;
}
int main ()
{
	memset(c,false,sizeof(c));
	int n,k,i,j,m;
	int x,y;
	bool flag;
	scanf("%d%d",&n,&m);
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d",&x,&y);
		c[x][y] = true;
	}
	flag = f(n);
	x = 0;
	while ( flag )
	{
		if ( z == 1 )
		{
			for ( i = 1; i <= n; i++ )
				c[bx][i] = false;
			x++;
		}
		else
		{
			for ( i = 1; i <= n; i++ )
				c[i][by] = false;
			x++;
		}
		flag = f(n);
	}
	cout<<x<<endl;
	return 0;
}