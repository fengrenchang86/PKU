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
int que[20000];
int main ()
{
	int t;
//	fstream cin("in.txt");
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
	int begin = 0;
	int end = 0;
	que[end++] = 1;
	int cur;
	visit[1] = 1;
	a[1] = price[1];
	int min = MAX;
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= n; j++ )
		{
			if ( i == j || abs(degree[i]-degree[j])>m || v[i][j] < 0)
				continue;
			if ( v[i][j] + a[i] - price[i] + price[j] < a[j] )
			{
				a[j] = v[i][j] + a[i] - price[i] + price[j];
				if ( a[j] < min )
					min = a[j];
			}
		}
	}
/*	while ( begin < end )
	{
		cur = que[begin%20000];
		begin++;
		for ( i = 1; i <= n; i++ )
		{
			if (  abs(degree[i]-degree[1])<=m && v[cur][i] > 0 )
			{
				que[end%20000] = i;
				end++;
				visit[i] = 1;
				if( v[cur][i] + a[cur] - price[cur] + price[i] < a[i] )
					a[i] = v[cur][i] + a[cur] - price[cur] + price[i];
			}
		}
	}
	j = 1;
	for ( i = 2; i <= n; i++ )
		if ( a[i] < a[j] )
			j = i;
	cout<<a[j]<<endl;*/
	cout<<min<<endl;
	return 0;
}