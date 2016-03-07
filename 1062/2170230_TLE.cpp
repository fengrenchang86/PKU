#include <iostream>
#include <fstream>
using namespace std;
int m,//等级差距限制
	n;//物品总数
const int MAX = 2147483647;
int v[120][120];//v[i][j]表示可以用第j个物品＋v[i][j]的价钱换物品i
int degree[12];
double price[12];
double a[12];
int min = MAX;
int main ()
{
	int t;
//	fstream cin("in.txt");
	int i,j,k,x;
	for ( i = 0; i < 120; i++ )
	{
		a[i] = MAX;
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
	a[1] = price[1];
	min = a[1];
	x = degree[1] + m;
	while ( x >= degree[1] && x >= 0 )
	{
		for ( i = 1; i <= n; i++ )
		{
			for ( j = 1; j <= n; j++ )
			{
				if ( degree[j] <= x && x-degree[j]<=m && v[i][j] > 0 )
				{
					if ( v[i][j]  - price[i] + a[i] + price[j] < a[j] )
					{
						a[j] = v[i][j] - price[i] + a[i] + price[j];
						if ( a[j] < min )
							min = a[j];
					}
				}
			}
		}
		x--;
	}
	cout<<min<<endl;
	return 0;
}