#include <iostream>
#include <queue>
using namespace std;
char a[50][50];
int w[50][50];
int n,m;
bool dir,flag;
int b[4][2];
struct ac
{
	int x,y,w;
};
queue<ac>que;
void dfsLeft(int x, int y, int step, int dir);
void dfsRight(int x, int y, int step, int dir);
void solve ( )
{
	cin>>m>>n;
	int i,j,p;
	for ( i = 0; i < n; i++ )
		for ( j = 0; j < m; j++ )
			w[i][j] = 2000000;
	for ( i = 0; i < n; i++ )
		cin>>a[i];
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < m; j++ )
		{
			if ( a[i][j] == 'S' )
				break;
		}
		if ( a[i][j] == 'S' )
			break;
	}
	if ( j > 0 && a[i][j-1]=='.' )
		p = 0;
	else if ( i > 0 && a[i-1][j] == '.' )
		p = 1;
	else if ( j < m-1 && a[i][j+1] == '.' )
		p = 2;
	else
		p = 3;
	a[i][j] = '#';
	flag = false;
	dfsLeft(i+b[p][0],j+b[p][1],2,p);
	flag = false;
	dfsRight(i+b[p][0],j+b[p][1],2,p);
	while ( !que.empty() )
		que.pop();
	ac t,q;
	w[i][j] = 1;
	t.x = i;
	t.y = j;
	t.w = 1;
	que.push(t);
	while ( !que.empty() )
	{
		t = que.front();
		que.pop();
		if ( t.w > w[t.x][t.y] )
			continue;
		if ( t.x > 0 && a[t.x-1][t.y] != '#' && w[t.x-1][t.y] > t.w+1 )
		{
			q = t;
			q.x--;
			q.w = t.w+1;
			w[t.x-1][t.y] = t.w+1;
			que.push(q);
		}
		if ( t.y > 0 && a[t.x][t.y-1] != '#' && w[t.x][t.y-1] > t.w+1 )
		{
			q = t;
			q.y--;
			q.w = t.w+1;
			w[t.x][t.y-1] = t.w+1;
			que.push(q);
		}
		if ( t.x < n-1 && a[t.x+1][t.y] != '#' && w[t.x+1][t.y] > t.w +1 )
		{
			q = t;
			q.x++;
			q.w = t.w+1;
			w[t.x+1][t.y] = t.w+1;
			que.push(q);
		}
		if ( t.y < m-1 && a[t.x][t.y+1] != '#' && w[t.x][t.y+1] > t.w+1 )
		{
			q = t;
			q.y++;
			q.w = t.w+1;
			w[t.x][t.y+1] = t.w+1;
			que.push(q);
		}
	}
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < m; j++ )
		{
			if ( a[i][j] == 'E' )
				break;
		}
		if ( a[i][j] == 'E' )
			break;
	}
	printf("%d\n",w[i][j]);
}
void dfsLeft ( int x, int y, int step, int dir )
{
	if ( a[x][y] == 'E' )
	{
		flag = true;
		printf("%d ",step);
		return;
	}
	int p;
	p = (dir+3)%4;
	if ( a[x+b[p][0]][y+b[p][1]] != '#' )
		dfsLeft(x+b[p][0],y+b[p][1],step+1,p);
	if ( flag )
		return;
	p = dir;
	if ( a[x+b[p][0]][y+b[p][1]] != '#' )
		dfsLeft(x+b[p][0],y+b[p][1],step+1,p);
	if ( flag )
		return;
	p = (dir+1)%4;
	if ( a[x+b[p][0]][y+b[p][1]] != '#' )
		dfsLeft(x+b[p][0],y+b[p][1],step+1,p);
	if ( flag )
		return;
	p = (dir+2)%4;
	if ( a[x+b[p][0]][y+b[p][1]] != '#' )
		dfsLeft(x+b[p][0],y+b[p][1],step+1,p);
}
void dfsRight ( int x, int y, int step, int dir )
{
	if ( a[x][y] == 'E' )
	{
		flag = true;
		printf("%d ",step);
		return;
	}
	int p;
	p = (dir+1)%4;
	if ( a[x+b[p][0]][y+b[p][1]] != '#' )
		dfsRight(x+b[p][0],y+b[p][1],step+1,p);
	if ( flag )
		return;
	p = dir;
	if ( a[x+b[p][0]][y+b[p][1]] != '#' )
		dfsRight(x+b[p][0],y+b[p][1],step+1,p);
	if ( flag )
		return;
	p = (dir+3)%4;
	if ( a[x+b[p][0]][y+b[p][1]] != '#' )
		dfsRight(x+b[p][0],y+b[p][1],step+1,p);
	if ( flag )
		return;
	p = (dir+2)%4;
	if ( a[x+b[p][0]][y+b[p][1]] != '#' )
		dfsRight(x+b[p][0],y+b[p][1],step+1,p);
	if ( flag )
		return;
}
int main ()
{
	b[0][0] = 0;
	b[0][1] = -1;
	b[1][0] = -1;
	b[1][1] = 0;
	b[2][0] = 0;
	b[2][1] = 1;
	b[3][0] = 1;
	b[3][1] = 0;
	int tc;
	cin>>tc;
	while(tc--)
		solve();
	return 0;
}