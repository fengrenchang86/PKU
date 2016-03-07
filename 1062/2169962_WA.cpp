#include <iostream>
#include <fstream>
using namespace std;
int m,//等级差距限制
	n;//物品总数
const int MAX = 2147483647;
int v[120][120];//v[i][j]表示可以用第j个物品＋v[i][j]的价钱换物品i
int degree[120];
int price[120];
int visit[120];
int a[120];
int min = MAX;
void dfs ( int x )
{
	int i;
	for ( i = 2; i <= n; i++ )
	{
		if ( abs(degree[i]-degree[1]) > m )
			continue;
		if ( i == x )
			continue;
		if ( v[x][i] < 0 )
			continue;
		if ( v[x][i] + a[x] - price[x] + price[i] < a[i] )
		{
			a[i] = v[x][i] + a[x] - price[x] + price[i];
			if ( a[i] < min )
				min = a[i];
			visit[i] = 1;
			dfs(i);
			visit[i] = 0;
		}
	}
}
int main ()
{
	int t;
// 	fstream cin("in.txt");
	int i,j,k,x;
	for ( i = 0; i < 120; i++ )
	{
		a[i] = MAX;
		visit[i] = 0;
		for ( j = 0; j < 120; j++ )
			v[i][j] = -1;
	}
	cin>>m>>n;
	for ( i = 1; i <= n; i++ )
	{
		cin>>price[i]>>degree[i]>>x;
		for ( j = 0; j < x; j++ )
		{
			cin>>k>>t;
			v[i][k] = t;
		}
	}
	visit[1] = 1;
	a[1] = price[1];
	x = degree[1] - m;
	while ( x <= 0 )
		x++;
	while ( x <= degree[1]+m )
	{
		for ( k=1 ; k <= n; k++ )
		{
			for ( i = 1; i <= n; i++ )
			{
				for ( j = 1; j <= n; j++ )
				{
					if ( i == j || degree[j]-x>m || v[i][j] < 0)
						continue;
					if ( v[i][j] + a[i] - price[i] + price[j] < a[j] )
					{
						a[j] = v[i][j] + a[i] - price[i] + price[j];
						if ( a[j] < min )
							min = a[j];
					}
				}
			}
		}
		x++;
	}
//	dfs(1);
	cout<<min<<endl;
	return 0;
}