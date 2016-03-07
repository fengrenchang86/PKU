#include <iostream>
using namespace std;
int a[10][10];
int save[100][2];
int flag = 0;
int squ ( int x,int y, int key )
{
	int i,j;
	int t;
	if ( x<=3)
	{
		if ( y<=3 )
			t =1;
		else if ( y <= 6 )
			t = 2;
		else
			t = 3;
	}
	else if ( x <= 6 )
	{
		if ( y <= 3 )
			t = 4;
		else if ( y <= 6 )
			t = 5;
		else
			t = 6;
	}
	else
	{
		if ( y <= 3 )
			t = 7;
		else if ( y <= 6 )
			t = 8;
		else
			t = 9;
	}
	if ( t == 1 )
	{
		for ( i = 1; i <= 3; i++ )
			for ( j = 1; j <= 3; j++ )
				if ( a[i][j] == key )
					return 0;
	}
	else if ( t ==2 )
	{
		for ( i = 1; i <= 3; i++ )
			for ( j=4; j<= 6; j++ )
				if ( a[i][j] == key )
					return 0;
	}
	else if ( t == 3 )
	{
		for ( i =1; i <= 3; i++ )
			for ( j =7; j<=9; j++ )
				if ( a[i][j] == key )
					return 0;
	}
	else if ( t == 4 )
	{
		for ( i = 4; i <= 6; i++ )
			for ( j = 1; j <= 3; j++ )
				if ( a[i][j] == key )
					return 0;
	}
	else if ( t==5 )
	{
		for ( i = 4; i<= 6;i++ )
			for ( j =4; j<=6;j++ )
				if ( a[i][j] == key )
					return 0;
	}
	else if ( t == 6 )
	{
		for ( i = 4; i<=6;i++ )
			for ( j=7;j<=9;j++ )
				if ( a[i][j] == key )
					return 0;
	}
	else if ( t == 7 )
	{
		for ( i = 7; i<=9;i++ )
			for ( j=1; j<=3;j++ )
				if ( a[i][j] == key )
					return 0;
	}
	else if ( t ==8 )
	{
		for ( i = 7; i<=9; i++ )
			for ( j=4;j<=6;j++)
				if ( a[i][j] == key )
					return 0;
	}
	else
	{
		for ( i = 7; i<=9;i++ )
			for ( j=7;j<=9;j++ )
				if ( a[i][j] == key )
					return 0;
	}
	return 1;
}
int row ( int r, int key )
{
	int i;
	for ( i = 1; i <= 9; i++ )
	{
		if ( a[r][i] == key )
			return 0;
	}
	return 1;
}
int col ( int c, int key )
{
	int i;
	for ( i = 1; i <= 9; i++ )
	{
		if ( a[i][c] == key )
			return 0;
	}
	return 1;
}
int dfs ( int position, int end)
{
	if ( position == end )
	{
		flag = 1;
		return 1;
	}
	if ( flag == 1 )
		return 1;
	int i;
	for ( i = 1; i <= 9; i++ )
	{
		if ( row(save[position][0],i) == 1 )
		{
			if ( col(save[position][1],i) == 1 )
			{
				if ( squ(save[position][0],save[position][1],i) == 1 )
				{
					a[save[position][0]][save[position][1]] = i;
					dfs(position+1,end);
					if ( flag == 1 )
						return 1;
					a[save[position][0]][save[position][1]] = 0;
				}
			}
		}
	}
	return 0;
}
int main ()
{
	int tcase,it;
	int i,j;
	char ch;
	int end = 0;
	cin>>tcase;
	for ( it = 0; it < tcase; it++ )
	{
		end = 0;
		for ( i = 1; i <= 9; i++ )
		{
			for ( j = 1; j <= 9; j++ )
			{
				cin>>ch;
				a[i][j] = ch-'0';
//				if ( a[i][j] == 0 )
//				{
//					save[end][0] = i;
//					save[end][1] = j;
//					end++;
//				}
			}
		}
		for ( j = 1; j<=9; j++ )
			for ( i = 1; i <= 9; i++ )
			{
				if ( a[i][j] == 0 )
				{
					save[end][0] = i;
					save[end][1] = j;
					end++;
				}
			}
		dfs(0,end);
		for ( i = 1; i <= 9; i++ )
		{
			for ( j = 1; j <= 9; j++ )
			{
				cout<<a[i][j];
			}
			cout<<endl;
		}
		flag = 0;
	}
	return 0;
}