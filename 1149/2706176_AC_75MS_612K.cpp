#include <iostream>
using namespace std;
const int max = 1101;
int f[max][max];
int w[max];
bool visit[max];
int PigFarm[1010];
int Guest[max];
int pre[max];
void init ( int n )
{
	int i,j;
	for ( i = 0; i <= n; i++ )
	{
		for ( j = 0; j <= n; j++ )
			f[i][j] = 0;
		pre[i] = 0;
	}
}
void init_dij ( int n )
{
	int i;
	for ( i = 0; i <= n+1; i++ )
	{
		w[i] = 500000;
		visit[i] = false;
	}
	pre[0] = -1;
}
int Min ( int n )
{
	int j = n;
	int min = 500000;
	while ( pre[j] != -1 )
	{
		if ( f[pre[j]][j] < min )
			min = f[pre[j]][j];
		j = pre[j];
	}
	j = n;
	while ( pre[j] != -1 )
	{
		f[pre[j]][j] -= min;
		f[j][pre[j]] += min;
		j = pre[j];
	}
	return min;
}
int dij ( int n )
{
	int i,j,k,min;
	init_dij(n);
	for ( i = 1; i <= n; i++ )
	{
		if ( f[0][i] > 0 )
		{
			w[i] = 1;
			pre[i] = 0;
		}
	}
	visit[0] = true;
	for ( i = 1; i <= n; i++ )
	{
		min = 500000;
		for ( j = 1; j <= n+1; j++ )
		{
			if ( visit[j] == false && w[j] < min  )
			{
				min = w[j];
				k = j;
			}
		}
		if ( w[k] == 500000 )
			return 0;
		visit[k] = true;
		for ( j = 1; j <= n+1; j++ )
		{
			if ( visit[j] == false && f[k][j] > 0 && w[j] > w[k]+1 )
			{
				w[j] = w[k]+1;
				pre[j] = k;
			}
		}
	}
	return Min(n+1);
}
int main ()
{
	int i,m,n,j,d,k;
	scanf("%d%d",&m,&n);
	for ( i = 1; i <= m; i++ )
		scanf("%d",&PigFarm[i]);
	init(n);
	for ( i = 1; i <= n; i++ )
	{
		scanf("%d",&d);
		for ( j = 0; j < d; j++ )
		{
			scanf("%d",&k);
			f[0][i] += PigFarm[k];
			if ( pre[k] != 0 )
			{
				f[pre[k]][i] = 500000;
				f[0][i] -= PigFarm[k];
			}
			pre[k] = i;
		}
		scanf("%d",&f[i][n+1]);
	}
	k = 0;
	while ( 1 )
	{
		j = dij(n);
		k += j;
		if ( j == 0 )
			break;
	}
	cout<<k<<endl;
	return 0;
}
