#include <iostream>
#include <vector>
using namespace std;
int n, m, ans;
bool flag;
int arrType[65][65];
char board[500][500];
bool visit[65][65];
int path[70][2];
int lay;
char tmp[1000];
void PrintBoard()
{
	int i, j;
	for (i = 0; i < 4*n + 1; i++)
	{
		for (j = 0; j < 4 * m + 1; j++)
		{
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}
void InitBoard()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			board[4*i][4*j] = '+';
			board[4*i][4*j+1] = '-';
			board[4*i][4*j+2] = '-';
			board[4*i][4*j+3] = '-';
		}
		board[4*i][4*m] = '+';
		for (j = 0; j < m; j++)
		{
			board[4*i+1][4*j] = '|';
			board[4*i+1][4*j+1] = ' ';
			board[4*i+1][4*j+2] = ' ';
			board[4*i+1][4*j+3] = ' ';
		}
		board[4*i+1][4*m] = '|';
		for (j = 0; j < m; j++)
		{
			board[4*i+2][4*j] = '|';
			board[4*i+2][4*j+1] = ' ';
			board[4*i+2][4*j+2] = ' ';
			board[4*i+2][4*j+3] = ' ';
		}
		board[4*i+2][4*m] = '|';
		for (j = 0; j < m; j++)
		{
			board[4*i+3][4*j] = '|';
			board[4*i+3][4*j+1] = ' ';
			board[4*i+3][4*j+2] = ' ';
			board[4*i+3][4*j+3] = ' ';
		}
		board[4*i+3][4*m] = '|';
	}
	for (j = 0; j < 4 * m + 1; j++)
	{
		board[4*n][j] = board[0][j];
	}
}

void Input()
{
	char ch[3][1000];
	cin.ignore();
	gets(tmp);
//	cin.ignore();
	int i, j;
	for (i = 0; i < n; i++)
	{
		gets(ch[0]);
		gets(ch[1]);
		gets(ch[2]);
		gets(tmp);
		for (j = 0; j < m; j++)
		{
			if (ch[1][4*j+1] == '*' && ch[1][4*j+2] == '*' && ch[1][4*j+3] == '*')
			{
				arrType[i][j] = 1;
			}
			else if (ch[1][4*j+2] == '*' && ch[0][4*j+2] == '*' && ch[2][4*j+2] == '*')
			{
				arrType[i][j] = 1;
			}
			else if (ch[1][4*j+2] == '*')
			{
				arrType[i][j] = 2;
			}
			else
				arrType[i][j] = 0;
		}
	}
}
void dfs(int x, int y, int nDir)
{
	if (x < 0 || x >= n || y < 0 || y >=m ||
		arrType[x][y] == 0 || visit[x][y])
	{
		return;
	}
	if (x == n-1 && y == m-1)
	{
		ans++;
		if (!flag)
		{
			flag = 1;
		}
		return;
	}
	if (!flag)
	{
		path[lay][0] = x;
		path[lay][1] = y;
		lay++;
	}
	visit[x][y] = 1;
	if (arrType[x][y] == 1)
	{
		switch (nDir)
		{
		case 0:
			dfs(x+1, y, 0);
			break;
		case 1:
			dfs(x, y-1, 1);
			break;
		case 2:
			dfs(x-1, y, 2);
			break;
		case 3:
			dfs(x, y+1, 3);
			break;
		}
	}
	else
	{
		switch (nDir)
		{
		case 0:
		case 2:
			dfs(x, y-1, 1);
			dfs(x, y+1, 3);
			break;
		case 1:
		case 3:
			dfs(x-1, y, 2);
			dfs(x+1, y, 0);
			break;
		}
	}
	if (!flag)
	{
		lay--;
	}
	visit[x][y] = 0;
}
void Solve()
{
	ans = 0;
	lay = 0;
	flag = 0;
	memset(visit, 0, sizeof(visit));
	dfs(0, 0, 0);
	dfs(0, 0, 3);
	int i;
	if (ans)
	{
		InitBoard();
		path[lay][0] = n-1;
		path[lay][1] = m-1;
		int x, y, x1, y1, x2, y2;
		x = path[1][0];
		y = path[1][1];
		board[2][2] = '*';
		if (x == 1)
		{
			if (arrType[0][0] == 1)
			{
				board[3][2] = '*';
				board[1][2] = '*';
			}
			else
			{
				board[3][2] = '*';
				board[2][1] = '*';
			}
		}
		else
		{
			if (arrType[0][0] == 1)
			{
				board[2][1] = '*';
				board[2][3] = '*';
			}
			else
			{
				board[1][2] = '*';
				board[2][3] = '*';
			}
		}
		x = path[lay-1][0];
		y = path[lay-1][1];
		board[4*(n-1)+2][4*(m-1)+2] = '*';
		if (x == n-2)
		{
			if (arrType[n-1][m-1] == 1)
			{
				board[4*(n-1)+1][4*(m-1)+2] = '*';
				board[4*(n-1)+3][4*(m-1)+2] = '*';
			}
			else
			{
				board[4*(n-1)+1][4*(m-1)+2] = '*';
				board[4*(n-1)+2][4*(m-1)+3] = '*';
			}
		}
		else
		{
			if (arrType[n-1][m-1] == 1)
			{
				board[4*(n-1)+2][4*(m-1)+1] = '*';
				board[4*(n-1)+2][4*(m-1)+3] = '*';
			}
			else
			{
				board[4*(n-1)+2][4*(m-1)+1] = '*';
				board[4*(n-1)+3][4*(m-1)+2] = '*';
			}
		}
		for (i = 1; i < lay ; i++)
		{
			x1 = path[i-1][0];
			y1 = path[i-1][1];
			x = path[i][0];
			y = path[i][1];
			x2 = path[i+1][0];
			y2 = path[i+1][1];
			board[4*x + 2][4*y+2] = '*';
			if (x - x1 == 1)
			{
				board[4*x+1][4*y+2] = '*';
				if (y - y2 == 1)
				{
					board[4*x+2][4*y+1] = '*';
				}
				else if (y2 - y == 1)
				{
					board[4*x+2][4*y+3] = '*';
				}
				else
				{
					board[4*x+3][4*y+2] = '*';
				}
			}
			else if (x1 - x == 1)
			{
				board[4*x+3][4*y+2] = '*';
				if (y - y2 == 1)
				{
					board[4*x+2][4*y+1] = '*';
				}
				else if (y2 - y == 1)
				{
					board[4*x+2][4*y+3] = '*';
				}
				else
				{
					board[4*x+1][4*y+2] = '*';
				}
			}
			else if (y - y1 == 1)
			{
				board[4*x+2][4*y+1] = '*';
				if (x - x2 == 1)
				{
					board[4*x+1][4*y+2] = '*';
				}
				else if (x2 - x == 1)
				{
					board[4*x+3][4*y+2] = '*';
				}
				else
				{
					board[4*x+2][4*y+3] = '*';
				}
			}
			else
			{
				board[4*x+2][4*y+3] = '*';
				if (x - x2 == 1)
				{
					board[4*x+1][4*y+2] = '*';
				}
				else if (x2 - x == 1)
				{
					board[4*x+3][4*y+2] = '*';
				}
				else
				{
					board[4*x+2][4*y+1] = '*';
				}
			}
		}
		PrintBoard();
		printf("Number of solutions: %d\n", ans);
	}
	else
	{
		printf("Number of solutions: 0\n");
}
}
int main()
{
	int tc;
	n = 4, m = 6;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d %d", &n, &m);
		Input();
		Solve();
	}
	return 0;
}
