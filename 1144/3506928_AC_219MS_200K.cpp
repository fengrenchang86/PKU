#include <iostream>
using namespace std;
int n;
bool visit[110];
char ch[10000];
bool v[110][110];
void input ( )
{
	getchar();
	int x,y;
	int i,k=0;
	memset(v,false,sizeof(v));
	while ( gets(ch) )
	{
		if ( ch[0] == 0 )
			continue;
		else if (ch[0] == '0' )
			return;
		i = 0;
		while ( ch[i] == ' ' )
			i++;
		k = 0;
		while ( ch[i] >= '0' && ch[i] <= '9' )
		{
			k *= 10;
			k += (ch[i]-'0');
			i++;
		}
		x = k;
		while ( ch[i] != 0 )
		{
			while ( ch[i] == ' ' )
				i++;
			k = 0;
			while ( ch[i] >= '0' && ch[i] <= '9' )
			{
				k *= 10;
				k += (ch[i]-'0');
				i++;
			}
			y = k;
			v[x][y] = v[y][x] = true;
		}
	}
}
void dfs ( int node )
{
	visit[node] = true;
	int i;
	for ( i = 1; i <= n; i++ )
	{
		if ( !visit[i] && v[node][i] )
			dfs(i);
	}
}
void solve ( )
{
	int i,j,k=0;
	for ( i = 1; i <= n; i++ )
	{
		memset(visit,false,sizeof(visit));
		visit[i] = true;
		if ( i-1 >= 1 )
			dfs(i-1);
		else if ( i+1 <= n )
			dfs(i+1);
		for ( j = 1; j <= n; j++ )
		{
			if ( visit[j] == false )
				break;
		}
		if ( j <= n )
			k++;
	}
	printf("%d\n",k);
}
int main ()
{
	while ( scanf("%d",&n) && n )
	{
		if ( n == 1 )
		{
			printf("1\n");
			continue;
		}
		input();
		solve();
	}
	return 0;
}