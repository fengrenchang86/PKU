#include <iostream>
using namespace std;
int w[510];
int station[510];
bool visit[510];
int max[510];
int n,m,end;
int c[510][510];
void init ()
{
	int i;
	for ( i = 1; i <= n; i++ )
	{
		visit[i] =false;
		if ( station[i] == 0 )
			w[i] = 2000000000;
		else
			w[i] = 0;
	}
}
int dij ( bool ok )
{
	int i,j,k,min,MAX=0;
	int sum = 0;
	for ( i = 1; i <= n; i++ )
	{
		min = 2000000000;
		k = 0;
		for ( j = 1; j <= n; j++ )
		{
			if ( visit[j] == false && w[j] < min )
			{
				min = w[j];
				k = j;
			}
		}
		visit[k] = true;
		sum += w[k];
		if ( ok == true )
		{
			if ( w[k] > MAX )
			{
				MAX = w[k];
				max[0] = k;
				end = 1;
			}
			else if ( w[k] == MAX )
				max[end++] = k;
		}
		for ( j = 1; j <= n; j++ )
		{
			if ( visit[j] == false && w[j] > w[k]+c[j][k] )
				w[j] = w[k]+c[j][k];
		}
	}
	return sum;
}
int main ()
{
	int i,j,k,d,x,y,len,sum,ans=2000000000;
	scanf("%d%d",&m,&n);
	for ( i = 1; i <= n; i++ )
	{
		station[i] = 0;
		for ( j = 1; j <= n; j++ )
			c[i][j] = 2000000000;
	}
	for ( i = 0; i < m; i++ )
	{
		scanf("%d",&d);
		station[d] = 1;
	}
	while ( scanf("%d%d%d",&x,&y,&len) == 3 )
	{
		if ( c[x][y] > len )
		{
			c[x][y] = len;
			c[y][x] = len;
		}
	}
	init();
	ans = dij(true);
	len = w[max[0]];
	d = 1;
	for ( i = 1; i <= n; i++ )
	{
		if ( station[i] == 1 )
			continue;
		init();
		w[i] = 0;
		sum = dij(false);
		if ( sum > ans )
			continue;
		{
			ans = sum;
			d = i;
		}
	}
	cout<<d<<endl;
	return 0;
}