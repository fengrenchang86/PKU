#include<iostream>
using namespace std;
char a[10][10];
char b[10][10];
char c[10][10];
int ans;
void f ( int x, int y )
{
	if ( a[x][y] == 'w' )
		a[x][y] = 'b';
	else
		a[x][y] = 'w';
}
void change ( int x, int y )
{
	if ( x-1 >= 0 )
		f(x-1,y);
	if ( x+1 < 4 )
		f(x+1,y);
	if ( y-1 >= 0 )
		f(x,y-1);
	if ( y+1 < 4 )
		f(x,y+1);
	f(x,y);
}
bool check ()
{
	int i,j;
	for ( i = 0; i < 4; i++ )
		for ( j =0 ; j < 4; j++ )
			if ( a[i][j] != a[0][0] )
				return false;
	return true;
}
void dfs ( int lay, int num )
{
	if ( lay == 4 )
	{
		int i,j,k;
		for ( i = 0; i < 4; i++ )
		{
			b[0][i] = a[0][i];
			b[1][i] = a[1][i];
		}
		for ( i = 2; i < 4; i++ )
		{
			for ( j = 0; j < 4; j++ )
				a[i][j] = c[i][j];
		}
		k = 0;
		for ( i = 1; i < 4; i++ )
		{
			for ( j = 0; j < 4; j++ )
			{
				if ( a[i-1][j] != a[0][0] )
				{
					change(i,j);
					k++;
				}
			}
		}
		if ( check() == true )
		{
			if ( num+k < ans )
				ans = num+k;
		}
		for ( i = 0; i < 4; i++ )
		{
			a[0][i] = b[0][i];
			a[1][i] = b[1][i];
		}
		for ( i = 2; i < 4; i++ )
		{
			for ( j = 0; j < 4; j++ )
				a[i][j] = c[i][j];
		}
		k = 0;
		for ( i = 1; i < 4; i++ )
		{
			for ( j = 0; j < 4; j++ )
			{
				if ( a[i-1][j] == a[0][0] )
				{
					change(i,j);
					k++;
				}
			}
		}
		if ( check() == true )
		{
			if ( num +k < ans )
				ans = num+k;
		}
		for ( i = 0; i < 4; i++ )
		{
			a[0][i] = b[0][i];
			a[1][i] = b[1][i];
		}
		return ;
	}
	int x,y;
	x = lay/4;
	y = lay%4;
	dfs(lay+1,num);
	change(x,y);
	dfs(lay+1,num+1);
	change(x,y);
}
int main ()
{
	int i,j;
	for ( i = 0; i < 4; i++ )
		scanf(" %s",a[i]);
	for ( i = 0; i < 4; i++ )
	{
		for ( j = 0; j < 4; j++ )
			c[i][j] = a[i][j];
	}
	ans = 2000000000;
	dfs(0,0);
	if ( ans != 2000000000 )
		printf("%d\n",ans);
	else
		printf("Impossible\n");
	return 0;

}