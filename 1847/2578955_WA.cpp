#include <iostream>
using namespace std;
bool visit[120];
int w[120];
int c[120][120];
void init ( int n )
{
	int i,j;
	for ( i = 0; i <= n; i++ )
	{
		visit[i] = false;
		w[i] = 2000000000;
		for ( j = 0; j <= n; j++ )
			c[i][j] = 0;
	}
}
int dij ( int a, int b, int n )
{
	visit[a] = true;
	int i,j,k,min;
	for ( i = 1; i <= n; i++ )
	{
		if ( i != a && c[a][i] != 0 )
			w[i] = c[a][i];
	}
	for ( i = 1; i < n; i++ )
	{
		min = 2000000000;
		for ( j = 1; j<= n; j++ )
		{
			if ( visit[j] == false && w[j] < min )
			{
				min = w[j];
				k = j;
			}
		}
		if ( min == 2000000000 )
			return min;
		visit[k] = true;
		for ( j = 1; j <= n; j++ )
		{
			if ( visit[j] == false && w[j] > w[k]+c[k][j] )
				w[j] = w[k]+c[k][j];
		}
	}
	return w[b];
}
int main ()
{
	int n,a,b,k,i,j,d;
	scanf("%d%d%d",&n,&a,&b);
	for ( i = 1; i <= n; i++ )
	{
		scanf("%d",&k);
		for ( j = 0; j < k; j++ )
		{
			scanf("%d",&d);
			c[i][d] = c[d][i] =1;
		}
	}
	k = dij(a,b,n);
	if ( k == 2000000000 )
		cout<<-1<<endl;
	else
		cout<<k-1<<endl;
	return 0;
}