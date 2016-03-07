#include <iostream>
using namespace std;
char a[30][30];
int n,m;
void go ( int x, int y )
{
	int i,j;
	i = x;
	j = y;
	while ( i > 0 )
	{
		if ( a[i][j] != 'X' )
			a[i][j] = 'x';
		i--;
	}
	i = x;
	while ( i <= m )
	{
		if ( a[i][j] != 'X' )
			a[i][j] = 'x';
		i++;
	}
	i = x;
	while ( j > 0 )
	{
		if ( a[i][j] != 'X' )
			a[i][j] = 'x';
		j--;
	}
	j = y;
	while ( j <= n )
	{
		if ( a[i][j] != 'X' )
			a[i][j] = 'x';
		j++;
	}
	j = y;
	while ( i > 0 && j > 0 )
	{
		if ( a[i][j] != 'X' )
			a[i][j] = 'x';
		i--;
		j--;
	}
	i = x;
	j = y;
	while ( i <= m && j <= n )
	{
		if ( a[i][j] != 'X' )
			a[i][j] = 'x';
		i++;
		j++;
	}
	i = x;
	j = y;
	while ( i > 0 && j <= n )
	{
		if ( a[i][j] != 'X' )
			a[i][j] = 'x';
		i--;
		j++;
	}
	i = x;
	j = y;
	while ( i <= m && j > 0 )
	{
		if ( a[i][j] != 'X' )
			a[i][j] = 'x';
		i++;
		j--;
	}
}
int get ( int x, int y )
{
	int i,j,k=0;
	i = x-1;
	j = y;
	while ( i > 0 )
	{
		if ( a[i][j] == '.' )
			k++;
		i--;
	}
	i = x+1;
	while ( i <= m )
	{
		if ( a[i][j] == '.' )
			k++;
		i++;
	}
	i = x;
	j = y-1;
	while ( j > 0 )
	{
		if ( a[i][j] == '.' )
			k++;
		j--;
	}
	j = y+1;
	while ( j <= n )
	{
		if ( a[i][j] == '.' )
			k++;
		j++;
	}
	i = x-1;
	j = y-1;
	while ( i > 0 && j > 0 )
	{
		if ( a[i][j] == '.' )
			k++;
		i--;
		j--;
	}
	i = x+1;
	j = y+1;
	while ( i <= m && j <= n )
	{
		if ( a[i][j] == '.' )
			k++;
		i++;
		j++;
	}
	i = x-1;
	j = y+1;
	while ( i > 0 && j <= n )
	{
		if ( a[i][j] == '.' )
			k++;
		i--;
		j++;
	}
	i = x+1;
	j = y-1;
	while ( i <= m && j > 0 )
	{
		if ( a[i][j] == '.' )
			k++;
		i++;
		j--;
	}
	return k;
}
int main ()
{
	int k,i,j,min=2000000,x,y,t;
	char ch[10];
	scanf("%d%d%d",&m,&n,&k);
	for ( i = 0; i <= m; i++ )
	{
		for ( j = 0; j <= n; j++ )
			a[i][j] = '.';
	}
	while ( k-- > 0 )
	{
		scanf("%s",&ch);
		a[ch[0]-'a'+1][ch[1]-'0'] = 'X';
		go(ch[0]-'a'+1,ch[1]-'0');
	}
	k = 0;
	for ( i = 1; i <= m; i++ )
	{
		for ( j = 1; j <= n; j++ )
		{
			if ( a[i][j] == '.' )
				k++;
		}
	}
	for ( i = 1; i <= m; i++ )
	{
		for ( j = 1; j <= n; j++ )
		{
			if ( a[i][j] == 'X' )
				continue;
			t = get(i,j);
			if ( a[i][j] == '.' )
				t+=1;
			if ( t < min )
			{
				min = t;
				x = i;
				y = j;
			}
		}
	}
	cout<<char(x+'a'-1)<<y<<endl;
	cout<<k-min<<endl;
	return 0;
}