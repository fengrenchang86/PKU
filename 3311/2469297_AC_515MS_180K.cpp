#include <iostream>
using namespace std;
int v[12][12];
int t[12][12];
int n;
bool visit[12];
bool a[12][12];
int va[12];
bool b[12][12];
int vb[12];
int min;
void dfs ( int node, int dis, int count )
{
	int i;
	if ( dis >= min )
		return;
	if ( count == n )
	{
		if ( dis+v[node][0] < min)
			min = dis+v[node][0];
		return;
	}
	for ( i = 1; i <= n; i++ )
	{
		if ( visit[i] == false )
		{
			visit[i] =true;
			dfs(i,dis+v[node][i],count+1);
			visit[i] = false;
		}
	}
}
int main ()
{
	int i,j,k;
	int x,y;
	while ( scanf("%d",&n) && n!=0 )
	{
		for ( i = 0; i <= n; i++ )
		{
			for ( j = 0; j <=n; j++ )
			{
				scanf("%d",&v[i][j]);
				t[i][j] = 2000000000;
			}
		}
		for ( i = 0; i <= n; i++ )
		{
			for ( j = 0; j <= n; j++ )
				visit[j] = false;
			visit[i] = true;
			for ( j = 1; j <= n; j++ )
			{
				x = 2000000000;
				for ( k = 0; k <= n; k++ )
				{
					if ( visit[k] == false && v[i][k] < x  )
					{
						x = v[i][k];
						y = k;
					}
				}
				visit[y] = true;
				for ( k = 0; k <= n; k++ )
				{
					if ( v[i][y] + v[y][k] < v[i][k] )
						v[i][k] = v[i][y]+v[y][k];
				}
			}
		}
		min = 2000000000;
		memset(visit,0,sizeof(visit));
		dfs(0,0,0);
		cout<<min<<endl;
	}
	return 0;
}