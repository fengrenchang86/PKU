#include <iostream>
using namespace std;
const int MAX = 2000000000;
int cost[15][15][1500];
int sum[15][1500];
int mod[15][15];
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
				scanf("%d",&cost[i][j][k]); 
			}
			cost[i][j][0] = cost[i][j][d];
			while ( k <= m )
			{
				cost[i][j][k] = cost[i][j][k%d];
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
				if ( sum[i-1][k] != MAX && k != j && cost[k][j][i] != 0 && sum[i][j] > sum[i-1][k]+cost[k][j][i] )
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
	while ( cin>>n>>m  )
	{
		if ( n == 0 && m == 0 )
			break;
		init();
	}
	return 0;
}