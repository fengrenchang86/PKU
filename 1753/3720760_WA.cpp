#include<iostream>
using namespace std;
char a[10][10];
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
	if ( lay == 16 )
	{
		if ( check() == true )
		{
			if ( num < ans )
				ans = num;
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
	ans = 2000000000;
	dfs(0,0);
	printf("%d\n",ans);
	return 0;

}