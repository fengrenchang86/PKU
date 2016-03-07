#include <iostream>
using namespace std;
const double inf = 2147483647.0;

class ac
{
public:
	int v,dis;
};
double c[600][600];
class chang
{
private:
	int system;
	int n,m;
	double dist[600];
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
	int i,j,k;
	double tmin;
	dist[1] = 0.0;
	for ( i = 0; i < n; i++ )
	{
		tmin = inf;
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
	x = 1;
	y = 1;
	int j=0;
	double ans = 0.0;
	for ( i = 1; i <= n; i++ )
	{
		if ( dist[i] > ans )
		{
			x = i;
			y = i;
			ans = dist[i];
		}
	}
	for ( i = 1; i < n; i++ )
	{
		for ( j = i+1; j <= n; j++ )
		{
			if ( c[i][j] != inf && (dist[i]+dist[j]+double(c[i][j]))/2.0 > ans )
			{
				ans = (dist[i]+dist[j]+double(c[i][j]))/2.0;
				x = i;
				y = j;
			}
		}
	}
	printf("System #%d\n",system);
	system++;
	if ( n == 1 )
	{
		printf("The last domino falls after 0.0 seconds, at key domino 1.\n\n");
		return;
	}
	if ( x==y )
		printf("The last domino falls after %.1lf seconds, at key domino %d.\n",ans,x);
	else
		printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n",ans,x,y);
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