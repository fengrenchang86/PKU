#include <iostream>
#include <queue>
using namespace std;
const int inf = 2000000000;
struct ac
{
	int x,y;
	int step;
};
int a[310][310];
int pos[8][2];
int n;
queue<ac>que;
void init ()
{
	int i,j;
	for ( i = 0; i < n; i++ )
	{
		for ( j =0 ; j < n; j++ )
			a[i][j] = inf;
	}
}
void solve ()
{
	int bx,by,ex,ey,i;
	cin>>n;
	cin>>bx>>by>>ex>>ey;
	init();
	ac p,q;
	p.step = 0;
	p.x = bx;
	p.y = by;
	a[bx][by] = 0;
	while ( !que.empty() )
		que.pop();
	que.push(p);
	while ( !que.empty() )
	{
		p = que.front();
		que.pop();
		if ( a[p.x][p.y] < p.step )
			continue;
		if ( p.x == ex && p.y == ey )
			break;
		for ( i = 0; i < 8; i++ )
		{
			if ( p.x+pos[i][0] >= 0 && p.x+pos[i][0] < n && p.y+pos[i][1] >= 0 && p.y+pos[i][1] < n )
			{
				if ( a[p.x+pos[i][0]][p.y+pos[i][1]] > p.step+1 )
				{
					q.x = p.x+pos[i][0];
					q.y = p.y+pos[i][1];
					q.step = p.step+1;
					a[q.x][q.y] = q.step;
					que.push(q);
				}
			}
		}
	}
	printf("%d\n",a[ex][ey]);
}
int main ()
{
	pos[0][0] = 2; pos[0][1] = 1;
	pos[1][0] = 2; pos[1][1] = -1;
	pos[2][0] = -2;pos[2][1] = 1;
	pos[3][0] = -2;pos[3][1] = -1;
	pos[4][0] = 1; pos[4][1] = 2;
	pos[5][0] = 1; pos[5][1] = -2;
	pos[6][0] = -1;pos[6][1] = 2;
	pos[7][0] = -1;pos[7][1] = -2;
	int tc;
	cin>>tc;
	while (tc--)
	{
		solve();
	}
	return 0;
}