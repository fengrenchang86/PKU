#include <iostream >
using namespace std;
#define MAXN 410
bool c[MAXN][MAXN];
int path[MAXN];
bool visit[MAXN];
int w[MAXN];
int dij ( int n )
{
	memset(visit,false,sizeof(visit));
	memset(path,0,sizeof(path));
	w[0] = 0;
	int i,j,k,min;
	for ( i = 0; i <= 401; i++ )
		w[i] = 2000000000;
	for ( i = 1; i <= 100; i++ )
	{
		if ( c[0][i] == true )
		{
			w[i] = 1;
			path[i] = 0;
		}
	}
	for ( i = 1; i <= n; i++ )
	{
		min = 2000000000;
		k = 0;
		for ( j = 1; j <= 400; j++ )
		{
			if ( visit[j] == false && w[j] < min )
			{
				k = j;
				min = w[j];
			}
		}
		visit[k] = true;
		if ( k == 0 )
			break;
		if ( w[k] == 2000000000 )
			break;
		for ( j = 1; j <= 401; j++ )
		{
			if ( visit[j] == false && w[j] > w[k]+1 && c[k][j] == true )
			{
				w[j] = w[k]+1;
				path[j] = k;
			}
		}
	}
	if ( w[401] == 2000000000 )
		return 0;
	else
		return 1;
}
void addPath ( )
{
	int k = 401;
	while ( k != 0 )
	{
		c[path[k]][k] = false;
		c[k][path[k]] = true;
		k = path[k];
	}
}
int main ()
{
	int N,F,D,i,j,k,f,d;
	scanf("%d%d%d",&N,&F,&D);
	for ( i = 0; i <= 100; i++ )
		for ( j = 101; j <= 200; j++ )
			c[i][j] = c[i+100][j+100] = c[i+200][j+200] = false;
	for ( i = 1; i <= F; i++ )
		c[0][i] = true;
	for ( i = 1; i <= D; i++ )
		c[i+300][401] = true;
	for ( i = 1; i <= N; i++ )
	{
		scanf("%d%d",&f,&d);
		for ( j = 0; j < f; j++ )
		{
			scanf("%d",&k);
			c[k][100+i] = true;
		}
		for ( j = 0; j < d; j++ )
		{
			scanf("%d",&k);
			c[200+i][300+k] = true;
		}
		c[100+i][200+i] = true;
	}
	k = 0;
	while ( dij(D+F+N+N) == 1 )
	{
		k++;
		addPath();
	}
	cout<<k<<endl;
	return 0;
}