#pragma warning (disable:4786 )
#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;
char a[8][8];
int ans;
map<string,int>ma;
void input ()
{
	int i,j,k=0;
	char in[10];
	for ( i = 0; i <= 6; i++ )
	{
		for ( j = 0; j <= 6; j++ )
			a[i][j] = '#';
	}
	for ( i = 1; i <= 5; i++ )
	{
		cin>>in;
		for ( j = 1; j <= 5; j++ )
		{
			a[i][j] = in[j-1];
			if ( a[i][j] == 'o' )
				k++;
		}
	}
	ans = k;
	ma.clear();
}
bool visit()
{
	int i,j,k=0;
	char ch[30];
	for ( i = 1; i <= 5; i++ )
	{
		for ( j = 1; j <= 5; j++ )
			ch[k++] = a[i][j];
	}
	ch[k] = 0;
	if ( ma[ch] == 0 )
	{
		ma[ch] = 1;
		return true;
	}
	else
		return false;
}
void dfs ( int rest )
{
	if ( ans == 1 )
		return;
	int i,j;
	if ( rest < ans )
		ans = rest;
	if ( visit() == false )
		return;
	bool flag = false;
	for ( i = 1; i <= 5; i++ )
	{
		for ( j = 1; j <= 5; j++ )
		{
			if ( a[i][j] != 'o' )
				continue;
			if ( i >= 3 && a[i][j] == a[i-1][j] && a[i-2][j] == '.' )
			{
				flag = true;
				a[i][j] = '.';
				a[i-1][j] = '.';
				a[i-2][j] = 'o';
				dfs(rest-1);
				a[i][j] = a[i-1][j] = 'o';
				a[i-2][j] = '.';
			}
			if ( i <= 3 && a[i][j] == a[i+1][j] && a[i+2][j] == '.' )
			{
				flag = true;
				a[i][j] = a[i+1][j] = '.';
				a[i+2][j] = 'o';
				dfs(rest-1);
				a[i][j] = a[i+1][j] = 'o';
				a[i+2][j] = '.';
			}
			if ( j >= 3 && a[i][j] == a[i][j-1] && a[i][j-2] == '.' )
			{
				flag = true;
				a[i][j] = a[i][j-1] = '.';
				a[i][j-2] = 'o';
				dfs(rest-1);
				a[i][j] = a[i][j-1] = 'o';
				a[i][j-2] = '.';
			}
			if ( j <= 3 && a[i][j] == a[i][j+1] && a[i][j+2] == '.' )
			{
				flag = true;
				a[i][j] = a[i][j+1] = '.';
				a[i][j+2] = 'o';
				dfs(rest-1);
				a[i][j] = a[i][j+1] = 'o';
				a[i][j+2] = '.';
			}
		}
	}
}
void solve ( )
{
	dfs(ans);
	printf("The best case ends with %d pegs.\n",ans);
}
int main ()
{
	int tc;
	cin>>tc;
	while ( tc-- )
	{
		input();
		solve();
	}
	return 0;
}