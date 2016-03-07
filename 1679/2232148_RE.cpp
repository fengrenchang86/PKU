#include <iostream>
#include <fstream>
using namespace std;
int v[101][101];
int visit[101];
const int max = 2000000000;
int main ()
{
//	fstream cin("in.txt");
	int m,n,i,j,a,b,c;
	int tcase;
	int count;
	int min;
	int add;
	int cost;
	cin>>tcase;
	while ( tcase )
	{
		for ( i = 1; i <= n; i++ )
		{
			for ( j = 1; j <= n; j++ )
				v[i][j] = 0;
		}
		tcase--;
		cost = 0;
		cin>>n>>m;
		for ( i = 0; i < m; i++ )
		{
			cin>>a>>b>>c;
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
				visit[add] = 1;
				cost += min;
			}
			if ( min == -1 )
				break;
			count++;
		}
		if ( min > 0 )
			printf("%d\n",cost);
		else
			printf("Not Unique!\n");
	}
	return 0;
}