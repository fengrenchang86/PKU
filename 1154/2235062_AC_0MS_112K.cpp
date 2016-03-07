#include <iostream>
using namespace std;
int list[30];
char a[25][25];
int max = 1;
int r,s;
void dfs ( int x, int y, int lay )
{
	
	if ( y > 0 && list[a[x][y-1]-'A'] == 0 )
	{
		if ( lay+1 > max )
			max = lay+1;
		list[a[x][y-1]-'A'] = 1;
		dfs(x,y-1,lay+1);
		list[a[x][y-1]-'A'] = 0;
	}
	if ( y < s-1 && list[a[x][y+1]-'A'] == 0 )
	{
		if ( lay+1 > max )
			max = lay+1;
		list[a[x][y+1]-'A'] = 1;
		dfs(x,y+1,lay+1);
		list[a[x][y+1]-'A'] = 0;
	}
	if ( x > 0 && list[a[x-1][y]-'A'] == 0 )
	{
		if ( lay+1 > max )
			max = lay+1;
		list[a[x-1][y]-'A'] = 1;
		dfs(x-1,y,lay+1);
		list[a[x-1][y]-'A'] = 0;
	}
	if ( x < r-1 && list[a[x+1][y]-'A'] == 0 )
	{
		if ( lay+1 > max )
			max = lay+1;
		list[a[x+1][y]-'A'] = 1;
		dfs(x+1,y,lay+1);
		list[a[x+1][y]-'A'] = 0;
	}
}
int main ()
{
	
	memset(list,0,sizeof(list));
	int i;
	cin>>r>>s;
	for ( i = 0; i < r; i++ )
		cin>>a[i];
	list[a[0][0]-'A'] = 1;
	dfs(0,0,1);
	cout<<max<<endl;
	return 0;
}