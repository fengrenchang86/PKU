#include <iostream>
using namespace std;
const int MAX = 2000000000;
int cost[12][12][1100];
int sum[12][1100];
int n,m;
int tc=1;
void init ()
{
	int i,j,d,k,x;
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			if ( i == j )
				continue;
			scanf("%d",&d);
			for ( k = 1; k <= d; k++ )
			{
				scanf("%d",&x);
				if ( x != 0 )
					cost[i][j][k] = x;
				else
					cost[i][j][k] = MAX;
			}
			while ( k <= m )
			{
				x = k%d;
				if ( x == 0 )
					x = d;
				cost[i][j][k] = cost[i][j][x];
				k++;
			}
		}
	}
	for ( j = 0; j < n; j++ )
		sum[0][j] = MAX;
	sum[0][0] = 0;
	for ( i = 1; i <= m; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			sum[i][j] = MAX;
			for ( k = 0; k < n; k++ )
			{
				if ( sum[i-1][k] != MAX && k != j && cost[k][j][i] != MAX && sum[i][j] > sum[i-1][k]+cost[k][j][i] )
					sum[i][j] = sum[i-1][k] + cost[k][j][i];
			}
		}
	}
	printf("Scenario #%d\n",tc);
	tc++;
	if ( sum[m][n-1] != MAX )
		printf("The best flight costs %d.\n",sum[m][n-1]);
	else
		printf("No flight possible.\n");
	printf("\n");
}
int main ()
{
	while ( cin>>n>>m && !(n==0&&m==0))
	{
		init();
	}
	return 0;
}