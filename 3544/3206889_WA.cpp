#include <iostream>
#include <math.h>
using namespace std;
int c[1100][1100];
int n,t;
int w[1100];
int d[1100];
int p[1100];
int max[1100];
int money;
int city[1100];
int ans[1100];
bool pig[1100];
void init ()
{
	int i,j;
	money = 0;
	scanf("%d%d",&n,&t);
	memset(pig,false,sizeof(pig));
	for ( i = 0; i < n; i++ )
		scanf("%d",&w[i]);
	for ( i = 0; i < n; i++ )
		scanf("%d",&d[i]);
	for ( i = 0; i < n; i++ )
		scanf("%d",&p[i]);
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			c[i][j] = w[i]*p[j]-t*w[i]*d[j];
		}
	}
	for ( j = 0; j < n; j++ )
	{
		max[j] = 0;
		for ( i = 0; i < n; i++ )
		{
			if ( c[i][j] > max[j] )
				max[j] = c[i][j];
		}
	}
	max[n] = 0;
	for ( j = n-2; j >= 0; j-- )
		max[j] += max[j+1];
}
void dfs ( int k, int val )
{
	if ( k == n )
	{
		if ( val > money )
		{
			money = val;
			int i;
			for ( i = 0; i < n; i++ )
				ans[i] = city[i];
		}
		return;
	}
	int i;
	for ( i = 0; i < n; i++ )
	{
		if ( pig[i] == true )
			continue;
		if ( val+c[i][k]+max[k+1] >= money )
		{
			pig[i] = true;
			city[k] = i;
			dfs(k+1,val+c[i][k]);
			pig[i] = false;
		}
	}
}
int main ()
{
	init();
	dfs(0,0);
	int i;
	for ( i = 0; i < n; i++ )
		printf("%d ",ans[i]+1);
	printf("\n");
	return 0;
}