#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int node;
	int first;
	int last;
}v[30];
int n,m;
bool c[30][30];
bool visit[30];
bool in[30];
char ans[30];
int flag,result,pos;
int main ()
{
	void dfs(int,int);
	int next(int);
	int i,j,x,y;
	char ch[10];
	while ( cin>>n>>m && !(m==0&&n==0) )
	{
		memset(c,false,sizeof(c));
		memset(in,false,sizeof(in));
		result = 0;
		for ( i = 1; i <= m; i++ )
		{
			cin>>ch;
			x = ch[0]-'A';
			y = ch[2]-'A';
			if ( c[x][y] == true || result != 0 )
				continue;
			if ( x == y )
			{
				result = -1;
				pos = i;
				continue;
			}
			c[x][y] = true;
			in[y] = true;
			memset(visit,false,sizeof(visit));
			dfs(y,x);
			if ( visit[x] == true )
			{
				result = -1;
				pos = i;
				continue;
			}
			x = 0;
			for ( j = 0; j < n; j++ )
			{
				if ( in[j] == false )
				{
					x++;
					y = j;
				}
			}
			if ( x != 1 )
				continue;
			memset(visit,false,sizeof(visit));
			for ( j = 0; j < n; j++ )
			{
				visit[y] = true;
				ans[j] = y+'A';
				y = next(y);
				if ( y == -1 )
					break;
			}
			if ( j == n-1 )
			{
				pos = i;
				result = 1;
				ans[n] = NULL;
			}
		}
		if ( result == -1 )
			printf("Inconsistency found after %d relations.\n",pos);
		else if ( result == 0 )
			printf("Sorted sequence cannot be determined.\n");
		else
			printf("Sorted sequence determined after %d relations: %s.\n",pos,ans);
	}
	return 0;
}
int next ( int y )
{
	int i,j,k=0,p;
	for ( i = 0; i < n; i++ )
	{
		if ( visit[i] == false && c[y][i] == true )
		{
			for ( j = 0; j < n; j++ )
			{
				if ( visit[j] == false && c[j][i] == true )
					break;
			}
			if ( j == n )
			{
				p = i;
				k++;
			}
		}
	}
	if ( k == 1 )
		return p;
	else
		return -1;
}
void dfs ( int node, int end )
{
	visit[node] = true;
	if ( visit[end] == true )
		return;
	for ( int i = 0; i < n; i++ )
	{
		if ( c[node][i] == true && visit[i] == false )
			dfs(i,end);
		if ( visit[end]==true )
			return;
	}
}
