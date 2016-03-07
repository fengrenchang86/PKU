#include <iostream>
#include <fstream>
using namespace std;

char board[20][20];
bool visit[20][20];
int stack[200][2];

void FinalBfs ( int x, int y )
{
	int begin,end;
	char ch = board[x][y];
	stack[0][0] = x;
	stack[0][1] = y;
	begin = 0;
	end = 1;
	board[x][y] = 'A';
	while ( begin < end )
	{
		x = stack[begin][0];
		y = stack[begin][1];
		begin++;
		if ( x-1 >= 0 && board[x-1][y] == ch )
		{
			board[x-1][y] = 'A';
			stack[end][0] = x-1;
			stack[end++][1] = y;
		}
		if ( y-1 >= 0 && board[x][y-1] == ch )
		{
			board[x][y-1] = 'A';
			stack[end][0] = x;
			stack[end++][1] = y-1;
		}
		if ( x+1 < 10 && board[x+1][y] == ch )
		{
			board[x+1][y] = 'A';
			stack[end][0] = x+1;
			stack[end++][1] = y;
		}
		if ( y+1 < 15 && board[x][y+1] == ch )
		{
			board[x][y+1] = 'A';
			stack[end][0] = x;
			stack[end++][1] = y+1;
		}
	}
}
int bfs ( int x, int y )
{
	char ch = board[x][y];
	int i,j;
	int c = 1;
	int begin = 0,end = 0;
	for ( i = 0; i < 20; i++ )
		for ( j = 0; j < 20; j++ )
			visit[i][j] = false;
	stack[end][0] = x;
	stack[end][1] = y;
	end++;
	visit[x][y] = true;
	while ( begin < end )
	{
		x = stack[begin][0];
		y = stack[begin][1];
		begin++;
		if ( x-1 >=0 && board[x-1][y] == ch && visit[x-1][y] == false)
		{
			visit[x-1][y] = true;
			stack[end][0] = x-1;
			stack[end++][1] = y;
			c++;
		}
		if ( y-1 >= 0 && board[x][y-1] == ch && visit[x][y-1] == false)
		{
			visit[x][y-1] = true;
			stack[end][0] = x;
			stack[end++][1] = y-1;
			c++;
		}
		if ( x+1 < 10 && board[x+1][y] == ch && visit[x+1][y] == false)
		{
			visit[x+1][y] = true;
			stack[end][0] = x+1;
			stack[end++][1] = y;
			c++;
		}
		if ( y+1 < 15 && board[x][y+1] == ch && visit[x][y+1] == false)
		{
			visit[x][y+1] = true;
			stack[end][0] = x;
			stack[end++][1] = y+1;
			c++;
		}
	}
	return c;
}
void move ()
{
	char ch[20];
	int i,j,k;
	for ( j = 0; j < 15; j++ )
	{
		k = 9;
		for ( i = 9; i >= 0; i-- )
		{
			if ( board[i][j] != 'A' )
			{
				ch[k] = board[i][j];
				k--;
			}
		}
		while ( k >= 0 )
		{
			ch[k] = 'A';
			k--;
		}
		for ( i = 0; i < 10; i++ )
			board[i][j] = ch[i];
	}
	j = 0;
	while ( j < 15 )
	{
		if ( board[9][j] == 'A' )
		{
			k = j;
			while ( k+1 < 15 )
			{
				for ( i = 0; i < 10; i++ )
					board[i][k] = board[i][k+1];
				k++;
			}
			for ( i = 0; i < 10; i++ )
				board[i][14] = 'A';
		}
		j++;
	}
}
void p ()
{
	int i,j;
	for ( i = 0; i < 10; i++ )
	{
		for ( j = 0; j < 15; j++ )
			printf("%c ",board[i][j]);
		printf("\n");
	}
}
int main ()
{
//	fstream cin("in.txt");
	int tcase,it;
	int i,j,c;
	int max;
	int x,y;
	int sum;
	cin>>tcase;
	int count;
	int sum2 = 0;
//	scanf("%d",&tcase);
	for ( it = 1; it <= tcase; it++ )
	{
		sum2 = 0;
		sum = 150;
		printf("Game %d:\n\n",it);
		for ( i = 0; i < 10; i++ )
			cin>>board[i];
		//	scanf("%s",&board[i]);
		count = 1;
		while ( 1 )
		{
			max = 1;
			for ( j = 0; j < 15; j++ )
			{
				for ( i = 9; i >= 0; i-- )
				{
					if ( board[i][j] == 'A' )
						continue;
					c = bfs(i,j);
					if ( c > max )
					{
						max = c;
						x = i;
						y = j;
					}
				}
			}
			if ( max == 1 )
			{
				break;
			}
			sum -= max;
			printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",count,10-x,y+1,max,board[x][y],(max-2)*(max-2));
			count++;
			if ( max != 1 )
				sum2 += (max-2)*(max-2);
//			cout<<10-x<<" "<<y+1<<" :"<<board[x][y]<<"  ";
//			cout<<(max-2)*(max-2)<<endl;
//			printf("================删除前==============\n");
//			p();
//			printf("=====ok======\n");
			FinalBfs(x,y);
			move();
//			p();
//			printf("================完毕=================\n");
		}
		if ( sum == 0 )
			printf("Final score: %d, with 0 balls remaining.\n",sum2+1000);
		else
			printf("Final score: %d, with %d balls remaining.\n",sum2,sum);
			printf("\n");
	}
	return 0;
}