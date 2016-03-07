#include <iostream>
#include <math.h>
using namespace std;
const double inf = 200000000000.0;
struct point
{
	int x,y;
}b[1100];
double c[1100][1100];
int father[1100];
bool visit[1100];
double key[1100];
int n,m,k;
void input ()
{	
	int i,j,x,y;
	k = 0;
	scanf("%d%d",&n,&m);
	for ( i = 0; i < n; i++ )
		scanf("%d%d",&b[i].x, &b[i].y);
	for ( i = 0; i < n-1; i++ )
	{
		for ( j = i+1; j < n; j++ )
		{
			c[i][j] = double(b[i].x-b[j].x)*double(b[i].x-b[j].x)+double(b[i].y-b[j].y)*double(b[i].y-b[j].y);
			c[i][j] = sqrt(c[i][j]);
			c[j][i] = c[i][j];
		}
	}
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		c[x][y] = c[y][x] = 0;
	}
}
void solve ()
{
	int i,j,k;
	double tmin,ans=0.0;
	for ( i = 0; i < n; i++ )
	{
		key[i] = inf;
		visit[i] = false;
	}
	key[0] = 0;
	father[0] = 0;
	for ( i = 1; i < n; i++ )
	{
		key[i] = c[0][i];
		father[i] = 0;
	}
	visit[0] = true;
	for ( i = 1; i < n; i++ )
	{
		tmin = inf;
		for ( j = 0; j < n; j++ )
		{
			if ( !visit[j] && key[j] < tmin )
			{
				tmin = key[j];
				k = j;
			}
		}
		if ( tmin == inf )
			break;
		visit[k] = true;
		ans += c[k][father[k]];
		for ( j = 0; j < n; j++ )
		{
			if ( !visit[j] && key[j] > c[k][j] )
			{
				key[j] = c[k][j];
				father[j] = k;
			}
		}
	}
	printf("%.2lf\n",ans);
}
int main ()
{
	input();
	solve();
	return 0;
}