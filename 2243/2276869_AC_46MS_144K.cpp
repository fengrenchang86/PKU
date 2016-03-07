#include <iostream>
using namespace std;
int a[12][12];
int stack[10000][3];
int ox,oy;
void init ()
{
	int i,j;
	for ( i = 0; i < 12; i++ )
		for ( j = 0; j < 12; j++ )
			a[i][j] = 100;
}
int bfs ( int x, int y )
{
	if ( x==ox && y==oy )
		return 0;
	int c = 0;
	init();
	int end = 0,begin = 0;
	stack[end][0] = x;
	stack[end][1] = y;
	stack[end][2] = 0;
	end++;
	while ( begin<=end )
	{
		x = stack[begin][0];
		y = stack[begin][1];
		c = stack[begin][2];
		begin++;
		if ( x-1 >= 1 && y-2 >= 1 )
		{
			stack[end][0] = x-1;
			stack[end][1] = y-2;
			stack[end][2] = c+1;
			if ( x-1 == ox && y-2 == oy )
				return c+1;
			end++;
		}
		if ( x-1 >= 1 && y+2 <= 8 )
		{
			stack[end][0] = x-1;
			stack[end][1] = y+2;
			stack[end][2] = c+1;
			if ( x-1 == ox && oy == y+2 )
				return c+1;
			end++;
		}
		if ( x-2 >= 1 && y-1 >= 1 )
		{
			stack[end][0] = x-2;
			stack[end][1] = y-1;
			stack[end][2] = c+1;
			if ( x-2 == ox && y-1 == oy )
				return c+1;
			end++;
		}
		if ( x-2 >= 1 && y+1 <= 8 )
		{
			stack[end][0] = x-2;
			stack[end][1] = y+1;
			stack[end][2] = c+1;
			if ( x-2 == ox && y+1 == oy )
				return c+1;
			end++;
		}
		if ( x+1 <= 8 && y-2 >= 1 )
		{
			stack[end][0] = x+1;
			stack[end][1] = y-2;
			stack[end][2] = c+1;
			if ( ox == x+1 && oy == y-2 )
				return c+1;
			end++;
		}
		if ( x+1 <= 8 && y+2 <= 8 )
		{
			stack[end][0] = x+1;
			stack[end][1] = y+2;
			stack[end][2] = c+1;
			if ( x +1 ==ox && y+2 == oy )
				return c+1;
			end++;
		}
		if ( x+2 <= 8 && y-1 >= 1 )
		{
			stack[end][0] = x+2;
			stack[end][1] = y-1;
			stack[end][2] = c+1;
			if ( ox == x+2 && y-1 == oy )
				return c+1;
			end++;
		}
		if ( x+2 <= 8 && y+1 <= 8 )
		{
			stack[end][0] = x+2;
			stack[end][1] = y+1;
			stack[end][2] = c+1;
			if ( x+2 == ox && oy == y+1 )
				return c+1;
			end++;
		}
	}
	return 0;
}
int main ()
{
	int x,y;
	char ch1[10];
	char ch2[10];
	while ( scanf("%s",&ch1)!=EOF )
	{
		ox = ch1[0]-'a'+1;
		oy = ch1[1]-'0';
		scanf("%s",&ch2);
		x = ch2[0]-'a'+1;
		y = ch2[1]-'0';
		printf("To get from %s to %s takes %d knight moves.\n",ch1,ch2,bfs(x,y));
	}
	return 0;
}