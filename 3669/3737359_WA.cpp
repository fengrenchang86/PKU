#include<iostream>
#include<queue>
using namespace std;
const int inf = 2000000000;
struct ac
{
	int x,y;
	int dis;
};
int n,m;
int MAXT;
int boke[401][410];
int dis[401][401];
queue<ac>que;
void init ()
{
	int i,j;
	for ( i = 0; i <= 300; i++ )
	{
		for ( j = 0; j <= 300; j++ )
		{
			dis[i][j] = inf;
			boke[i][j] = inf;
		}
	}
	MAXT = -1;
	n = m = 320;
}
void change(int x, int y, int z)
{
	if ( boke[x][y] > z )
		boke[x][y] = z;
	if ( x > 0 && boke[x-1][y] > z )
		boke[x-1][y] = z;
	if ( x+1 <= n && boke[x+1][y] > z)
		boke[x+1][y] = z;
	if ( y > 0 && boke[x][y-1] > z )
		boke[x][y-1] = z;
	if ( y+1 <= m && boke[x][y+1] > z )
		boke[x][y+1] = z;
}
void input ()
{
	int t,i,x,y,z;
	scanf("%d",&t);
	for ( i = 0; i < t; i++ )
	{
		scanf("%d%d%d",&x,&y,&z);
		change(x,y,z);
		if ( z > MAXT )
			MAXT = z;
	}
}
void solve ()
{
	ac p,q;
	p.x = 0;
	p.y = 0;
	p.dis = 0;
	if ( boke[0][0] == 0 )
	{
		printf("-1\n");
		return;
	}
	dis[0][0] = 0;
	que.push(p);
	while ( !que.empty() )
	{
		p = que.front();
		que.pop();
		if ( p.dis > MAXT || boke[p.x][p.y] > MAXT )
		{
			printf("%d\n",p.dis);
			return;
		}
		else if ( p.dis > dis[p.x][p.y] )
			continue;
		q = p;
		q.dis++;
		if ( p.x > 0 && boke[p.x-1][p.y] > q.dis && dis[p.x-1][p.y] > q.dis )
		{
			q.x = p.x-1;
			dis[q.x][q.y] = q.dis;
			que.push(q);
		}
		q = p;
		q.dis++;
		if ( p.y+1 <= n && boke[p.x+1][p.y] > q.dis && dis[p.x+1][p.y] > q.dis )
		{
			q.x = p.x+1;
			dis[q.x][q.y] = q.dis;
			que.push(q);
		}
		q = p;
		q.dis++;
		if ( p.y > 0 && boke[p.x][p.y-1] > q.dis && dis[p.x][p.y-1] > q.dis )
		{
			q.y = p.y-1;
			dis[q.x][q.y] = q.dis;
			que.push(q);
		}
		q = p;
		q.dis++;
		if ( p.y +1 <= m && boke[p.x][p.y+1] > q.dis && dis[p.x][p.y+1] > q.dis )
		{
			q.y = p.y+1;
			dis[q.x][q.y] = q.dis;
			que.push(q);
		}
	}
	printf("-1\n");
}
int main ()
{
	init();
	input();
	solve();
	return 0;
}