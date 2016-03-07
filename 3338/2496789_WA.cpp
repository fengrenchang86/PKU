#include <iostream>
using namespace std;
int v[23][23];
struct ac
{
	int x1,y1,x2,y2;
}a[60];
int c=1;
void dfs ( int x, int y, int key, int l )
{
	if ( x-1 > a[l].x1 && v[x-1][y]==key )
	{
		v[x-1][y] = c;
		dfs(x-1,y,key,l);
	}
	if ( x+1 < a[l].x2 && v[x+1][y] == key )
	{
		v[x+1][y] = c;
		dfs(x+1,y,key,l);
	}
	if ( y-1 > a[l].y1 && v[x][y-1] == key )
	{
		v[x][y-1] = c;
		dfs(x,y-1,key,l);
	}
	if( y+1 < a[l].y2 && v[x][y+1] == key )
	{
		v[x][y+1] = c;
		dfs(x,y+1,key,l);
	}
}
int main ()
{
	int n,m,k;
	int i,j,l,t,max;
	while ( scanf("%d%d",&n,&m) && !(m==0&&n==0) )
	{
		c = 1;
		for ( i = 0; i <= n; i++ )
			for ( j = 0; j <= m; j++ )
				v[i][j] = 0;
		scanf("%d",&k);
		for ( l = 0; l < k; l++ )
		{
			scanf("%d%d%d%d",&a[l].x1,&a[l].y1,&a[l].x2,&a[l].y2);
			if ( a[l].x1 > a[l].x2 )
				swap(a[l].x1,a[l].x2);
			if ( a[l].y1 > a[l].y2 )
				swap(a[l].y1,a[l].y2);
			max = c;
			for ( i = a[l].x1; i < a[l].x2; i++ )
			{
				for ( j = a[l].y1; j < a[l].y2 ; j++ )
				{
					if ( v[i][j] < max )
					{
						t = v[i][j];
						dfs(i,j,t,l);
						c++;
					}
				}
			}
		}
		cout<<c<<endl;
	}
	return 0;
}