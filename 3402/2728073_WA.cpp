#include <iostream>
#include <string>
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
bool little ( char *a, char *b )
{
	int i;
	for ( i = 0; a[i] != NULL && b[i] != NULL;i++ )
	{
		if ( a[i] < b[i] )
			return true;
		else if ( a[i] > b[i] )
			return false;
	}
	if ( a[i] == NULL )
		return true;
	else
		return false;
}
int main ()
{
	int k,i,j,min=2000000,x,y,t;
	char ch[10],p[10];
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
			p[0] = i+'a'-1;
			if ( j < 10 )
			{
				p[1] = j+'0';
				p[2] = NULL;
			}
			else
			{
				p[1] = j/10+'0';
				p[2] = j%10+'0';
				p[3] = NULL;
			}
			if ( t < min || t==min && little(p,ch)==true)
			{
				x = i;
				y = j;
				min = t;
				strcpy(ch,p);
			}
		}
	}
	printf("%s\n",ch);
	cout<<k-min<<endl;
	return 0;
}