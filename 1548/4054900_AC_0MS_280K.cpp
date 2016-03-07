#include <iostream>
using namespace std;
struct point
{
	int x,y;
};
int v[30][30];
int n,m;
point findnext ( point t )
{
	if ( t.x == n+1 )
	{
		t.y = m+1;
		return t;
	}
	int x = t.x;
	int y = t.y;
	while ( y <= m )
	{
		if ( v[x][y] == 1 )
			break;
		y++;
	}
	if ( y <= m )
	{
		t.y = y;
		return t;
	}
	else
	{
		t.x++;
		return findnext(t);
	}
}
void init ()
{
	memset(v,0,sizeof(v));
	n = m = 0;
}
int main ()
{
	point t,p;
	int x,y,i,j;
	init();
	while ( scanf("%d%d",&x,&y) != EOF )
	{
		if ( x==-1 && y==-1 )
			break;
		if ( x!=0 || y!=0 )
		{
			v[x][y] = 1;
			if ( x > n )
				n = x;
			if ( y > m )
				m = y;
		}
		else
		{
			x = 0;
			t.x = 1;
			t.y = 1;
			for ( i = 1; i <= n; i++ )
			{
				for ( j = 1; j <= m; j++ )
				{
					if ( v[i][j] == 0 )
						continue;
					x++;
					v[i][j] = 0;
					t.x = i;
					t.y = j;
					while ( 1 )
					{
						p = findnext(t);
						if ( v[p.x][p.y] == 1 )
						{
							v[p.x][p.y] = 0;
							t = p;
						}
						else
							break;
					}
				}
			}
			cout<<x<<endl;
			init();
		}
	}
	return 0;
}