#include <iostream>
using namespace std;
struct wa
{
	int x,y,type,len;
}c[120][120];
int a,b,t;
int type[20000];
int ans[20000];
struct ac
{
	int x,y,len;
}stack[200000];
void p ( int x, int y )
{
	if ( x != 0 || y != 0 )
	{
		p(c[x][y].x,c[x][y].y );
		if ( c[x][y].type == 1 )
			cout<<"FILL(1)"<<endl;
		else if ( c[x][y].type == 2 )
			cout<<"FILL(2)"<<endl;
		else if ( c[x][y].type == 3 )
			cout<<"DROP(1)"<<endl;
		else if ( c[x][y].type == 4 )
			cout<<"DROP(2)"<<endl;
		else if ( c[x][y].type == 5 )
			cout<<"POUR(1,2)"<<endl;
		else
			cout<<"POUR(2,1)"<<endl;
	}
}
void dfs ( )
{
	int begin,end;
	begin = 0;
	end = 1;
	stack[0].x = 0;
	stack[0].y = 0;
	stack[0].len = 0;
	c[0][0].len = 0;
	int x,y,z;
	while ( begin < end )
	{
		x = stack[begin].x;
		y = stack[begin].y;
		if ( x == t || y == t )
			break;
		z = stack[begin++].len;
		if ( c[x][y].len != z )
			continue;
		if ( c[a][y].len > z+1 )
		{
			c[a][y].len = z+1;
			c[a][y].x = x;
			c[a][y].y = y;
			c[a][y].type = 1;
			stack[end].x = a;
			stack[end].y = y;
			stack[end++].len = z+1;
		}
		if ( c[x][b].len > z+1 )
		{
			c[x][b].len = z+1;
			c[x][b].x = x;
			c[x][b].y = y;
			c[x][b].type = 2;
			stack[end].x = x;
			stack[end].y = b;
			stack[end++].len = z+1;
		}
		if ( c[0][y].len > z+1 )
		{
			c[0][y].len = z+1;
			c[0][y].x = x;
			c[0][y].y = y;
			c[0][y].type = 3;
			stack[end].x = 0;
			stack[end].y = y;
			stack[end++].len = z+1;
		}
		if ( c[x][0].len > z+1 )
		{
			c[x][0].len = z+1;
			c[x][0].x = x;
			c[x][0].y = y;
			c[x][0].type = 4;
			stack[end].x = x;
			stack[end].y = 0;
			stack[end++].len = z+1;
		}
		if ( x+y <= b && c[0][x+y].len > z+1 )
		{
			c[0][x+y].len = z+1;
			c[0][x+y].x = x;
			c[0][x+y].y = y;
			c[0][x+y].type = 5;
			stack[end].x = 0;
			stack[end].y = x+y;
			stack[end++].len = z+1;
		}
		if ( x+y > b && c[x+y-b][b].len > z+1 )
		{
			c[x+y-b][b].len = z+1;
			c[x+y-b][b].x = x;
			c[x+y-b][b].y = y;
			c[x+y-b][b].type = 5;
			stack[end].x = x+y-b;
			stack[end].y = b;
			stack[end++].len = z+1;
		}
		if ( x+y <=a && c[x+y][0].len > z+1 )
		{
			c[x+y][0].len = z+1;
			c[x+y][0].x = x;
			c[x+y][0].y = y;
			c[x+y][0].type = 6;
			stack[end].x = x+y;
			stack[end].y = 0;
			stack[end++].len = z+1;
		}
		if ( x+y > a && c[a][x+y-a].len > z+1 )
		{
			c[a][x+y-a].len = z+1;
			c[a][x+y-a].x = x;
			c[a][x+y-a].y = y;
			c[a][x+y-a].type = 6;
			stack[end].x = a;
			stack[end].y = x+y-a;
			stack[end++].len = z+1;
		}
	}
	if ( begin == end && x != t && y != t )
		cout<<"impossible"<<endl;
	else
	{
		cout<<c[x][y].len<<endl;
		p(x,y);
	}
}
int main ()
{
	cin>>a>>b>>t;
	int i,j;
	for ( i = 0; i<=100;i++)
	{
		for ( j = 0; j<=100;j++ )
		{
			c[i][j].len = 2000000;
//			c[i][j].x = 0;
//			c[i][j].y = 0;
		}
	}
	dfs();
	return 0;
}
