#include<iostream>
using namespace std;
char board[1200][1200];
int v[1200][1200];
int n, m, acCount;
int Left,Right,down,up;
void init()
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j <= m; j++)
			v[i][j] = -1;
	}
	acCount = 0;
}
void dfs(int x, int y)
{
	v[x][y] = acCount;
	if(y < Left)
		Left = y;
	if(y > Right)
		Right = y;
	if(x < down)
		down = x;
	if(x > up)
		up = x;
	board[x][y] = '.';
	if(x-1 >= 0 && board[x-1][y] == '#')
		dfs(x-1, y);
	if(x+1 < n && board[x+1][y] == '#')
		dfs(x+1, y);
	if(y-1 >= 0 && board[x][y-1] == '#')
		dfs(x, y-1);
	if(y+1 < m && board[x][y+1] == '#')
		dfs(x, y+1);
}
bool MeetHH()
{
	int i, j;
	for(i = down; i <= up; i++)
	{
		for(j = Left; j <= Right; j++)
		{
			if(v[i][j] != v[down][Left])
				return false;
		}
	}
	return true;
}
void MissHH()
{
	int i;
	init();
	for(i = 0; i < n; i++)
	{
		scanf(" %s", &board[i]);
	}
}
void LoveHH()
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			if(board[i][j] == '#')
			{
				acCount++;
				down = Left = 2000000000;
				up = Right = -2000000000;
				dfs(i, j);
				if(MeetHH() == false)
				{
					printf("Bad placement.\n");
					return;
				}
			}
		}
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			if(v[i][j] < 0 )
				continue;
			if(i-1 >= 0 && j-1 >= 0 && v[i-1][j-1] > 0 && v[i-1][j-1] != v[i][j])
			{
				printf("Bad placement.\n");
				return;
			}
			if(i+1 < n && j-1 >= 0 && v[i+1][j-1] > 0 && v[i+1][j-1] != v[i][j])
			{
				printf("Bad placement.\n");
				return;
			}
			if(i-1 >= 0 && j+1 < m && v[i-1][j+1] > 0 && v[i-1][j+1] != v[i][j])
			{
				printf("Bad placement.\n");
				return;
			}
			if(i+1 < n && j+1 < m && v[i+1][j+1] > 0 && v[i+1][j+1] != v[i][j])
			{
				printf("Bad placement.\n");
				return;
			}
		}
	}
	printf("There are %d ships.\n", acCount);
}
int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		if(n == 0 && m == 0)
			break;
		MissHH();
		LoveHH();
	}
	return 123;
}