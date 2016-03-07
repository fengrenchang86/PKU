#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
char ans[10000][40];
bool visit[40],exist[40];
char a[40][40];
char t[40];
int n,m,end,len;
struct ac
{
	int x1,x2,y1,y2;
}v[40];
void checkword ( char ch, int &x1, int &x2, int &y1, int &y2 )
{
	int i,j;
	x2 = y2 = -1;
	x1 = y1 = 2000000;
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < m; j++ )
		{
			if ( a[i][j] == ch )
			{
				if ( i > x2 )
					x2 = i;
				if ( i < x1 )
					x1 = i;
				if ( j > y2 )
					y2 = j;
				if ( j < y1 )
					y1 = j;
			}
		}
	}
}
bool checkLetter ( char ch, int x1, int x2, int y1, int y2 )
{
	int i,j;
	for ( i = x1; i <= x2; i++ )
	{
		if ( a[i][y1] != ch && a[i][y1] != '.' && visit[a[i][y1]-'A'] == false )
			return false;
		if ( a[i][y2] != ch && a[i][y2] != '.' && visit[a[i][y2]-'A'] == false )
			return false;
	}
	for ( j = y1; j <= y2; j++ )
	{
		if ( a[x1][j] != ch && a[x1][j] != '.' && visit[a[x1][j]-'A'] == false )
			return false;
		if ( a[x2][j] != ch && a[x2][j] != '.' && visit[a[x2][j]-'A'] == false )
			return false;
	}
	return true;
}
void dfs ( int lay )
{
	if ( lay == -1 )
	{
		t[len] = NULL;
		strcpy(ans[end],t);
		end++;
		return;
	}
	int i;
	for ( i = 0; i < 26; i++ )
	{
		if ( visit[i] == true || exist[i] == false )
			continue;
		if ( checkLetter(char(i+'A'),v[i].x1,v[i].x2,v[i].y1,v[i].y2)==true )
		{
			t[lay] = char(i+'A');
			visit[i] = true;
			dfs(lay-1);
			visit[i] = false;
		}
	}
}
int cmp ( const void*a, const void*b )
{
	return strcmp((char*)a,(char*)b);
}
int main ()
{
	int i,j;
	while ( scanf("%d%d",&n,&m)!=EOF )
	{
		for ( i = 0; i < n; i++ )
			scanf("%s",&a[i]);
		memset(visit,false,sizeof(visit));
		memset(exist,false,sizeof(exist));
		end = len = 0;
		for ( i = 0; i < n; i++ )
		{
			for ( j = 0; j < m; j++ )
			{
				if ( a[i][j] >= 'A' && a[i][j] <= 'Z' )
					exist[a[i][j]-'A'] = true;
			}
		}
		for ( i = 0; i < 26; i++ )
		{
			if ( exist[i] == true )
			{
				len++;
				checkword(char(i+'A'),v[i].x1,v[i].x2,v[i].y1,v[i].y2);
			}
		}
		dfs(len-1);
		qsort(ans,end,sizeof(ans[0]),cmp);
		for ( i = 0; i < end; i++ )
			printf("%s\n",ans[i]);
	}
	return 0;
}
