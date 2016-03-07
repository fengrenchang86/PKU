#include <iostream>
using namespace std;
const int MAX = 2000000000;
int cost[15][15][1500];
int sum[1500][15];
int mod[15][15];
int n,m;
int tc=1;
void init ()
{
	int i,j,d,k;
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= n; j++ )
		{
			if ( i == j )
				continue;
			scanf("%d",&mod[i][j]);
			for ( k = 1; k <= mod[i][j]; k++ )
			{
				scanf("%d",&cost[i][j][k]); 
			}
			cost[i][j][0] = cost[i][j][mod[i][j]];
/*			while ( k <= m )
			{
				cost[i][j][k] = cost[i][j][k%d];
				k++;
			}*/
		}
	}
	for ( i = 0; i <= m; i++ )
		for ( j = 1; j <= n; j++ )
			sum[i][j] = MAX;
	sum[0][1] = 0;
	for ( i = 1; i <= m; i++ )
	{
		for ( j = 1; j <= n; j++ )
		{
			sum[i][j] = MAX;
			for ( k = 1; k <= n; k++ )
			{
				if ( j == k )
					continue;
				if ( sum[i-1][k] != MAX && cost[k][j][i%mod[k][j]] != 0 && sum[i][j] > sum[i-1][k]+cost[k][j][i%mod[k][j]] )
					sum[i][j] = sum[i-1][k] + cost[k][j][i%mod[k][j]];
			}
		}
	}
	printf("Scenario #%d\n",tc);
	tc++;
	if ( sum[m][n] != MAX )
		printf("The best flight costs %d.\n",sum[m][n]);
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
	system("pause");
	return 0;
}