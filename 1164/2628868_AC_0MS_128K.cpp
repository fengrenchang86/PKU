#include <iostream>
using namespace std;
struct ac
{
	bool up,down,left,right,visit;
	ac(){up=down=left=right=true;visit = false;}
}a[60][60];
int max = 0;
int count;
void dfs ( int x, int y )
{
	count++;
	if ( count > max )
		max = count;
	a[x][y].visit = true;
	if ( a[x][y].down == true && a[x+1][y].visit == false )
		dfs(x+1,y);
	if ( a[x][y].left == true && a[x][y-1].visit == false )
		dfs(x,y-1);
	if ( a[x][y].up == true && a[x-1][y].visit == false )
		dfs(x-1,y);
	if ( a[x][y].right == true && a[x][y+1].visit == false )
		dfs(x,y+1);
}
int main ()
{
	int n,m,i,j,d;
	scanf("%d%d",&n,&m);
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= m; j++ )
		{
			scanf("%d",&d);
			if ( d/8==1 )
				a[i][j].down = false;
			d %= 8;
			if ( d/4==1 )
				a[i][j].right = false;
			d %= 4;
			if ( d/2==1 )
				a[i][j].up = false;
			d %= 2;
			if ( d != 0 )
				a[i][j].left = false;
		}
	}
	d = 0;
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= m; j++ )
		{
			if ( a[i][j].visit == false )
			{
				count = 0;
				dfs(i,j);
				d++;
			}
		}
	}
	printf("%d\n%d\n",d,max);
	return 0;
}