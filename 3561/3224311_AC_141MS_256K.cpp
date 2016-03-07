#include <iostream>
using namespace std;
char v[20][20];
int type,n,m;
void dfs ( int x, int y )
{
	if ( type == 1 )
	{
		int i;
		for ( i = y; i >= 0; i-- )
		{
			if ( v[x][i] == '-' )
				v[x][i] = '.';
			else
				break;
		}
		for ( i = y+1; i < m; i++ )
		{
			if ( v[x][i] == '-' )
				v[x][i] = '.';
			else
				break;
		}
	}
	else if ( type == 2 )
	{
		int i;
		for ( i = x; i >= 0; i-- )
		{
			if ( v[i][y] == '|' )
				v[i][y] = '.';
			else
				break;
		}
		for ( i = x+1; i < n; i++ )
		{
			if (v[i][y] == '|' )
				v[i][y] = '.';
			else
				break;
		}
	}
	else if ( type == 3 )
	{
		int i;
		for ( i = 0; x-i>=0 && y-i >= 0; i++ )
		{
			if ( v[x-i][y-i] == '\\' )
				v[x-i][y-i] = '.';
			else
				break;
		}
		for ( i = 1; x+i < n && y+i < m; i++ )
		{
			if ( v[x+i][y+i] == '\\')
				v[x+i][y+i] = '.';
			else
				break;
		}
	}
	else
	{
		int i;
		for ( i = 0; x-i>=0 && y+i < m; i++ )
		{
			if ( v[x-i][y+i] == '/' )
				v[x-i][y+i] = '.';
			else
				break;
		}
		for ( i = 1; x+i<n && y-i >= 0; i++ )
		{
			if ( v[x+i][y-i] == '/' )
				v[x+i][y-i] = '.';
			else
				break;
		}
	}
}
int main ()
{
	int tc;
	cin>>tc;
	int i,j,k=0;
	while ( tc-- )
	{
		k = 0;
		cin>>n>>m;
		for ( i = 0; i < n; i++ )
			cin>>v[i];
		for ( i = 0; i < n; i++ )
		{
			for ( j = 0; j < m; j++ )
			{
				if ( v[i][j] == '.' )
					continue;
				if ( v[i][j] == '-' )
					type = 1;
				else if ( v[i][j] == '|' )
					type = 2;
				else if ( v[i][j] == '\\' )
					type = 3;
				else
					type= 4;
				dfs(i,j);
				k = 1;
				break;
			}
			if ( k == 1 )
				break;
		}
		for ( i = 0; i < n; i++ )
		{
			for ( j =0 ; j < m; j++ )
			{
				if ( v[i][j] != '.' )
				{
					k = 2;
					break;
				}
			}
			if ( k == 2 )
				break;
		}
		if ( k == 1 )
			cout<<"CORRECT"<<endl;
		else
			cout<<"INCORRECT"<<endl;
	}
	return 0;
}