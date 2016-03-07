#include <iostream>
using namespace std;
char v[20][20];
int count[10];
int len;
bool flag;
void input ()
{
	int i,j;
	for ( i = 1; i <= 10; i++ )
		for ( j = 1; j <= 10; j++ )
			cin>>v[i][j];
	for ( i = 1; i <= 4; i++ )
		count[i] = 0;
	flag = true;
}
bool border ()
{
	int i;
	for ( i = 1; i <= 10; i++ )
	{
		if ( v[1][i] == '1' )
			return false;
		if ( v[i][1] == '1' )
			return false;
		if ( v[10][i] == '1' )
			return false;
		if ( v[i][10] == '1' )
			return false;
	}
	return true;
}
void dfs ( int x, int y, int &dir )
{
	if ( x>1 && y>1 && v[x-1][y-1]=='1' )
	{
		flag = false;
		return;
	}
	if ( x>1 && y<10 && v[x-1][y+1]=='1' )
	{
		flag = false;
		return;
	}
	if ( x<10 && y >1 && v[x+1][y-1]=='1' )
	{
		flag = false;
		return;
	}
	if ( x<10 && y<10 && v[x+1][y+1] == '1' )
	{
		flag = false;
		return;
	}
	if ( x > 1 && v[x-1][y] == '1' )
	{
		if ( dir == 2 )
		{
			flag = false;
			return;
		}
		dir = 1;
		v[x-1][y] = '.';
		len++;
		dfs(x-1,y,dir);
	}
	if ( x < 10 && v[x+1][y] == '1' )
	{
		if ( dir == 2 )
		{
			flag = false;
			return;
		}
		dir = 1;
		v[x+1][y] = '.';
		len++;
		dfs(x+1,y,dir);
	}
	if ( y > 1 && v[x][y-1] == '1'  )
	{
		if ( dir == 1 )
		{
			flag = false;
			return;
		}
		dir = 2;
		v[x][y-1] =  '.';
		len++;
		dfs(x,y-1,dir);
	}
	if ( y < 10 && v[x][y+1] == '1')
	{
		if ( dir == 1 )
		{
			flag = false;
			return;
		}
		dir = 2;
		v[x][y+1] = '.';
		len++;
		dfs(x,y+1,dir);
	}
}
void run ()
{
	int i,j,dir;
	for ( i = 2; i <= 9; i++ )
	{
		for ( j =2; j <= 9; j++ )
		{
			if ( v[i][j] == '1' )
			{
				len = 1;
				v[i][j] = '.';
				dir = 0;
				dfs(i,j,dir);
				if ( flag == false )
					return;
				count[len]++;
			}
		}
	}
	if (!( count[1] == 4 && count[2] == 3 && count[3] == 2 && count[4] == 1 ))
		flag = false;
}
int main ()
{
	input();
	run();
	if ( flag == false )
		cout<<"incorrect"<<endl;
	else
		cout<<"correct"<<endl;
	return 0;
}