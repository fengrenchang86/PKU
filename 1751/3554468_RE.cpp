#include <iostream>
using namespace std;
const int inf = 2147483647;
struct point
{
	int x,y;
}p[1000];
bool visit[1000];
int c[800][800];
int w[800];
int next[800];
int n,m;
void input()
{
	int i,j,k=0;
	for ( i = 0; i < n; i++ )
		scanf("%d%d",&p[i].x,&p[i].y);
	for ( i = 0; i < n; i++ )
	{
		visit[i] = false;
		w[i] = inf;
		for ( j = i+1; j < n; j++ )
			c[i][j] = c[j][i] = (p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y);
	}
}
void solve ()
{
	int i,j,num,k,tmax,x,y,Count=n;
	scanf("%d",&num);
	for ( i = 0; i < num; i++ )
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		c[x][y] = c[y][x] = 0;
	}
	if ( num != 0 )
	{
		w[x] = 0;
		next[x] = y;
	}
	else
	{
		for ( i = 1; i < n; i++ )
		{
			w[i] = c[0][i];
			next[i] = 0;
		}
	}
	k = 0;
	while ( Count > 0 )
	{
		tmax = inf;
		for ( i = 0; i < n; i++ )
		{
			if ( visit[i] == false && w[i] <= tmax )
			{
				tmax = w[i];
				j = i;
			}
		}
		p[k].x = j;
		p[k].y = next[j];
		k++;
		Count--;
		visit[j] = true;
		for ( i = 0; i < n; i++ )
		{
			if ( !visit[i] && w[i] > c[i][j] )
			{
				w[i] = c[i][j];
				next[i] = j;
			}
		}
	}
	for ( i = 0; i < k; i++ )
	{
		if ( c[p[i].x][p[i].y] != 0 )
			printf("%d %d\n",p[i].x+1,p[i].y+1);
	}
}
int main ()
{
	while ( scanf("%d",&n) != EOF )
	{
		input();
		solve();
	}
	return 0;
}