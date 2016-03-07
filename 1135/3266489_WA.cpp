#include <iostream>
#include <vector>
using namespace std;
const int inf = 2147483647;

class ac
{
public:
	int v,dis;
};
int c[600][600];
class chang
{
private:
	int system;
	int n,m;
	int dist[600];
	bool visit[600];

public:
	chang();
	void getdata(int x, int y);
	void input ();
	void dij ();
	void solve(int x, int y);
};
chang::chang()
{
	system = 1;
}
void chang::getdata(int x, int y)
{
	n = x;
	m = y;
}
void chang::input()
{
	int i,j,x,y,z;
	for ( i = 0; i <= n; i++ )
	{
		for ( j = 0; j <= n; j++ )
			c[i][j] = inf;
		visit[i] = false;
		dist[i] = inf;
	}
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d%d",&x,&y,&z);
		if ( c[x][y] > z )
		{
			c[x][y] = c[y][x] = z;
		}
	}
}
void chang::dij()
{
	int i,j,k,tmin;
	tmin = inf;
	dist[1] = 0;
	for ( i = 0; i < n; i++ )
	{
		for ( j = 1; j <= n; j++ )
		{
			if ( visit[j] == false && dist[j] < tmin )
			{
				tmin = dist[j];
				k = j;
			}
		}
		if ( tmin == inf )
			break;
		visit[k] = true;
		for ( j = 1; j <= n; j++ )
		{
			if ( c[k][j]+dist[k] < dist[j] )
				dist[j] = dist[k]+c[k][j];
		}
	}
}
void chang::solve( int x, int y )
{
	chang::getdata(x,y);
	chang::input();
	chang::dij();
	int i,tmin=inf;
	x = 0;
	y = 0;
	int j=0;
	for ( i = 2; i <= n; i++ )
	{
		if ( dist[i] < tmin )
		{
			tmin = dist[i];
			x = i;
			j = 0;
		}
		else if ( dist[i] == tmin )
		{
			y = i;
			j = 1;
		}
	}
	printf("System #%d\n",system);
	system++;
	if ( n == 1 )
	{
		printf("The last domino falls after 0.0 seconds, at key domino 1.\n\n");
		return;
	}
	if ( j==0 )
	{
		printf("The last domino falls after %.1lf seconds, at key domino %d.\n",double(dist[x]),x);
	}
	else
	{
		printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n",double(dist[x]+double(c[x][y])/2.0),x,y);
	}
	printf("\n");
}
int main ()
{
	chang t;
	int n,m;
	while ( scanf("%d%d",&n,&m) != EOF )
	{
		if ( n == 0 && m == 0 )
			return 0;
		t.solve(n,m);
	}
	return 0;
}