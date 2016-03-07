#include <iostream>
#include <queue>
using namespace std;
const int inf = 2000000000;
struct point
{
	int x,y;
};
queue<point>que;
class game
{
private:
	char input[80][80];
	char board[80][80];
	int c[80][80];
	int w,h;
	int tc;
public:
	int endx,endy;
public:
	game(){tc=1;}
	void init ();
	void dfs ( int x, int y, int dir, int num );
	void solve ( int ww, int hh );
};
void game::init()
{
	int i,j;
	for ( i = 0; i <= w+1; i++ )
		board[0][i] = board[h+1][i] = ' ';
	board[0][i] = board[h+1][i] = NULL;
	for ( j = 0; j <= h+1; j++ )
		board[j][0] = board[j][w+1] = ' ';
	for ( i = 1; i <= h; i++ )
	{
		for ( j = 1; j <= w; j++ )
		{
			board[i][j] = input[i-1][j-1];
	//		c[i][j] = inf;
		}
		board[i][j] = NULL;
	}
	while ( !que.empty() )
		que.pop();
}
void game::dfs( int x, int y, int dir, int num )
{
	if ( c[x][y] > num )
		c[x][y] = num;
	else
		return;
	if ( x == endx && y == endy )
	{
		return;
	}
	if ( x-1 >= 0 && board[x-1][y] == ' ' || x-1 == endx && y==endy )
	{
		if ( dir != 1 )
			dfs(x-1,y,1,num+1);
		else
			dfs(x-1,y,1,num);
	}
	if ( x <= h && board[x+1][y] == ' '|| x+1 == endx && y==endy )
	{
		if ( dir != 2 )
			dfs(x+1,y,2,num+1);
		else
			dfs(x+1,y,2,num);
	}
	if ( y >= 1 && board[x][y-1] == ' ' || x == endx && y-1==endy)
	{
		if ( dir != 3 )
			dfs(x,y-1,3,num+1);
		else
			dfs(x,y-1,3,num);
	}
	if ( y <= w && board[x][y+1] == ' ' || x == endx && y+1==endy)
	{
		if ( dir != 4 )
			dfs(x,y+1,4,num+1);
		else
			dfs(x,y+1,4,num);
	}
}
void game::solve( int ww, int hh )
{
	w = ww;
	h = hh;
	int i,j,t,bx,by;
	cin.ignore();
	for ( i = 0; i < hh; i++ )
		cin.getline(input[i],100,'\n');
	init();
	t = 1;
	printf("Board #%d:\n",tc);
	tc++;
	while ( cin>>by>>bx>>endy>>endx )
	{
		if ( bx == 0 && by == 0 && endx == 0 && endy == 0 )
			break;
	//	bx++;
	//	by++;
	//	endx++;
	//	endy++;
		for ( i = 0; i <= hh+1; i++ )
			for ( j = 0; j <= ww+1; j++ )
				c[i][j] = inf;
		dfs(bx,by,0,0);
		if ( c[endx][endy] != inf )
			printf("Pair %d: %d segments.\n",t,c[endx][endy]);
		else
			printf("Pair %d: impossible.\n",t);
		t++;
	}
}
int main ()
{
	int ww,hh;
	game g;
	while ( cin>>ww>>hh )
	{
		if ( ww+hh==0 )
			break;
		g.solve(ww,hh);
		printf("\n");
	}
	return 0;
}