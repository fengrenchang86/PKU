#include <iostream>
#include <queue>
using namespace std;
const int inf = 2000000000;
struct ac
{
	int x,y;
	int left,right,up,down;
	int step;
}a[210][210];
queue<ac>que;
int w[210][210];
int n,m;
int ex,ey;
void init ()
{
	int i,j;
	for ( i = 0; i < 210; i++ )
	{
		for ( j = 0; j < 210; j++ )
		{
			w[i][j] = inf;
			a[i][j].x = i;
			a[i][j].y = j;
			a[i][j].left = a[i][j].right = a[i][j].up = a[i][j].down = 0;
		}
	}
}
void wall( int x, int y, int dir )
{
	if ( dir == 1 )
	{
		a[x][y].up = 1;
		if ( x > 0 )
			a[x-1][y].down = 1;
	}
	else
	{
		a[x][y].left = 1;
		if ( y > 0 )
			a[x][y-1].right = 1;
	}
}
void door ( int x, int y, int dir )
{
	if ( dir == 1 )
	{
		if ( a[x][y].up == 1 )
			a[x][y].up++;
		if ( x > 0 && a[x-1][y].down == 1 )
			a[x-1][y].down++;
	}
	else
	{
		if ( a[x][y].left == 1 )
			a[x][y].left++;
		if ( y > 0 && a[x][y-1].right == 1 )
			a[x][y-1].right++;
	}
}
void input ()
{
	int i,j;
	int x,y,d,t;
	double dx,dy;
	for ( i = 0; i < n; i++ )
	{
		scanf("%d%d%d%d",&x,&y,&d,&t);
		if ( d == 1 )
		{
			for ( j = 0; j < t; j++ )
				wall(x,y+j,d);
		}
		else
		{
			for ( j = 0; j < t; j++ )
				wall(x+j,y,d);
		}
	}
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d%d",&x,&y,&d);
		door(x,y,d);
	}
//	scanf("%f%f",&dx,&dy);
	cin>>dx>>dy;
	if ( dx > 210 )
		ex = 199;
	else
		ex = int(dx);
	if ( dy > 210 )
		ey = 199;
	else
		ey = int(dy);
}
void solve ( )
{
	input();
	w[ex][ey] = 0;
	ac p,q;
	p = a[ex][ey];
	p.step = 0;
	while ( !que.empty() )
		que.pop();
	que.push(p);
	while ( !que.empty() )
	{
		p = que.front();
		que.pop();
		if ( w[p.x][p.y] < p.step )
			continue;
		if ( p.up != 1 && p.x > 0 )
		{
			q = a[p.x-1][p.y];
			if ( p.up == 0 )
				q.step = p.step;
			else
				q.step = p.step+1;
			if ( w[q.x][q.y] > q.step )
			{
				w[q.x][q.y] = q.step;
				que.push(q);
			}
		}
		if ( p.down != 1 && p.x < 200 )
		{
			q = a[p.x+1][p.y];
			if ( p.down == 0 )
				q.step = p.step;
			else
				q.step = p.step+1;
			if ( w[q.x][q.y] > q.step )
			{
				w[q.x][q.y] = q.step;
				que.push(q);
			}
		}
		if ( p.left != 1 && p.y > 0 )
		{
			q = a[p.x][p.y-1];
			if ( p.left == 0 )
				q.step = p.step;
			else
				q.step = p.step+1;
			if ( w[q.x][q.y] > q.step )
			{
				w[q.x][q.y] = q.step;
				que.push(q);
			}
		}
		if ( p.right != 1 && p.y < 200 )
		{
			q = a[p.x][p.y+1];
			if ( p.right == 0 )
				q.step = p.step;
			else
				q.step = p.step+1;
			if ( w[q.x][q.y] > q.step )
			{
				w[q.x][q.y] = q.step;
				que.push(q);
			}
		}
	}
	if ( w[0][0] == inf )
		printf("-1\n");
	else
		printf("%d\n",w[0][0]);
}
int main ()
{
	while ( scanf("%d%d",&n,&m) != EOF )
	{
		if ( n == -1 && m == -1 )
			break;
		init();
		solve();
	}
	return 0;
}