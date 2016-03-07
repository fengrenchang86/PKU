#include <iostream>
using namespace std;
int v[21];
int a[21][21];

int flag;
int count = 0;

void dfs ( int x, int n )
{
	if ( x > n )
	{
		count++;
		return ;
	}
	int i,q;
	for ( i = 1; i <= a[x][0]; i++ )
	{
		q = a[x][i];
		if ( v[q] == 0 )
		{
			v[q] = 1;
			dfs(x+1,n);
			v[q] = 0;
		}
	}
}

int main ()
{
	int n,m;
	int i,j;
	scanf("%d%d",&n,&m);
	for ( i = 0; i <= m; i++ )
		v[i] = 0;
	for ( i = 1; i <= n; i++ )
	{
		scanf("%d",&a[i][0]);
		for ( j = 1; j <= a[i][0]; j++ )
			scanf("%d",&a[i][j]);
	}
	dfs(1,n);
	printf("%d\n",count);
	return 0;
}