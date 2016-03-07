#include <iostream>
using namespace std;
int v[110][110];
int vis[110];
int go[110];
int flag;
int n,tcase=1;;
int count;
void dfs ( int node )
{
	int i,j,x=0,y=0;
	for ( i = 1; i <= n; i++ )
	{
		if ( vis[i] <= 1 || v[node][i] == 0 )
			continue;
		if ( go[i] == 0 )
		{
			go[i] = 1;
			count--;
			x++;
			j = i;
		}
		else
			y++;
	}
	if ( x > 1 || y > 1 )
	{
		flag = -1;
		return;
	}
	if ( x == 1 )
		dfs(j);
}
	int main ()
	{
		int m,i,j,x,y;
		while ( cin>>n && n!= 0 )
		{
			flag = 0;
			cin>>m;
			for ( i = 0; i <=n; i++ )
			{
				vis[i] = 0;
				go[i] = 0;
				for ( j = 0; j<=n; j++ )
					v[i][j]=0;
			}
			for ( i = 0; i < m; i++ )
			{
				cin>>x>>y;
				v[x][y] = v[y][x] = 1;
				vis[x]++;
				vis[y]++;
			}
			for ( i = 1; i <= n; i++ )
			{
				if ( vis[i]>1 )
					count++;
				else if ( vis[i] == 0 )
				{
					flag = -1;
					break;
				}
			}
			if ( flag == -1 )
			{
				printf("Graph %d is not a caterpillar.\n",tcase);
				tcase++;
				continue;
			}
			i = 1;
			while ( vis[i] == 1 && i <= n )
				i++;
			if ( i > n )
			{
				printf("Graph %d is not a caterpillar.\n",tcase);
				tcase++;
				continue;
			}
			count--;
			go[i] = 1;
			for ( j = 1; j <= n; j++ )
			{
				if ( vis[j] <= 1 || go[j] == 1 )
					continue;
				count--;
				go[j] = 1;
				dfs(j);
				break;
			}
			while ( j <= n )
			{
				if ( vis[j] <= 1 || go[j] == 1 )
				{
					j++;
					continue;
				}
				count--;
				go[j] = 1;
				dfs(j);
				j++;
			}
			if ( flag == -1 )
				printf("Graph %d is not a caterpillar.\n",tcase);
			else if ( count != 0 )
				printf("Graph %d is not a caterpillar.\n",tcase);
			else
				printf("Graph %d is a caterpillar.\n",tcase);
			tcase++;
		}
		return 0;
	}