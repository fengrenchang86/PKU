#include <iostream>
using namespace std;
int v[101][101];
int visit[101];
const int max = 2000000000;
int main ()
{
	int m,n,i,j,a,b,c;
	int tcase;
	int count;
	int min;
	int add;
	int cost;
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		cost = 0;
		scanf("%d %d",&n,&m);
		for ( i = 0; i < m; i++ )
		{
			scanf("%d%d%d",&a,&b,&c);
			v[a][b] = c;
			v[b][a] = c;
		}
		memset(visit,0,sizeof(visit));
		count = 1;
		visit[1] = 1;
		while ( count <= n )
		{
			min = max;
			for ( i = 1; i <= n; i++ )
			{
				if ( visit[i] == 0 )
					continue;
				for ( j = 2; j <= n; j++ )
				{
					if ( i == j || visit[j] == 1 )
						continue;
					if ( v[i][j] < min )
					{
						add = j;
						min = v[i][j];
					}
					else if ( v[i][j] == min )
					{
						min = -1;
						break;
					}
				}
				if ( min == -1 )
					break;
				visit[j] = 1;
				cost += min;
			}
			count++;
		}
		if ( min > 0 )
			printf("%d\n",cost);
		else
			printf("Not Unique!\n");
	}
	return 0;
}