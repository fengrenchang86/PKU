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
int que[9000000];
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
	while ( begin < end )
	{
		cur = que[begin];
		begin++;
		for ( i = 1; i <= n; i++ )
		{
			if (  abs(degree[i]-degree[1])<=m && v[cur][i] > 0 )
			{
				que[end] = i;
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
	cout<<a[j]<<endl;
	return 0;
}