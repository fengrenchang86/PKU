#include <iostream>
#include <vector>
using namespace std;
bool attack[101][101];
int n, m, t;
char board[11][11];
int ac[11][11];
int knight[8][2] = {{-1, -2}, {1, -2}, {-1, 2}, {1, 2}, {-2, -1}, {-2, 1}, {2, -1}, {2, 1}};
int use[100];
char ch[100000];
void Init()
{
	memset(attack, 0, sizeof(attack));
}
void Input()
{
	int i, j = 0, k = 0;
	t = 0;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			board[i][j] = 'E';
		}
	}
	j = k = 0;
	for (i = 0; ch[i] != 0; i++)
	{
		if (ch[i] == '/')
		{
			k = 0;
			j++;
		}
		else if (ch[i] >= '1' && ch[i] <= '8')
		{
			k += (ch[i] - '0');
		}
		else if (ch[i] >= 'a' && ch[i] <= 'z' && ch[i] != 'p')
		{
			board[j][k] = ch[i] - 'a' + 'A';
			k++;
		}
		else
		{
			board[j][k] = ch[i];
			k++;
		}
	}
}
void DealSth(int x, int y)
{
	int i, j;
	int dx, dy;
	if (board[x][y] == 'K')
	{
		for (i = -1; i <= 1; i++)
		{
			dx = x + i;
			if (dx < 0 || dx >= n)
			{
				continue;
			}
			for (j = -1; j <= 1; j++)
			{
				dy = y + j;
				if (dy < 0 || dy >= m || dx==x && dy==y)
				{
					continue;
				}
				if (board[dx][dy] != 'E')
				{
					break;
				}
				attack[dx][dy] = 1;
			}
		}
	}
	else if (board[x][y] == 'Q')
	{
		i = x-1;
		j = y-1;
		while (i >= 0 && j >= 0)//--
		{
			if (board[i][j] != 'E')
			{
				break;
			}
			attack[i][j] = 1;
			i--;
			j--;
		}
		i = x-1;
		j = y;
		while (i >= 0)//-0
		{
			if (board[i][j] != 'E')
			{
				break;
			}
			attack[i][j] = 1;
			i--;
		}
		i = x;
		j = y-1;
		while (j >= 0)//0-
		{
			if (board[i][j] != 'E')
			{
				break;
			}
			attack[i][j] = 1;
			j--;
		}
		i = x;
		j = y+1;
		while (j < m)//0+
		{
			if (board[i][j] != 'E')
			{
				break;
			}
			attack[i][j] = 1;
			j++;
		}
		i = x-1;
		j = y+1;
		while (i >= 0 && j < m)//-+
		{
			if (board[i][j] != 'E')
			{
				break;
			}
			attack[i][j] = 1;
			i--;
			j++;
		}
		i = x+1;
		j = y+1;
		while (i < n && j < m)//++
		{
			if (board[i][j] != 'E')
			{
				break;
			}
			attack[i][j] = 1;
			i++;
			j++;
		}
		i = x+1;
		j = y;
		while (i < n)//+0
		{
			if (board[i][j] != 'E')
			{
				break;
			}
			attack[i][j] = 1;
			i++;
		}
		i = x+1;
		j = y-1;
		while (i < n && j >= 0)//+-
		{
			if (board[i][j] != 'E')
			{
				break;
			}
			attack[i][j] = 1;
			i++;
			j--;
		}
	}
	else if (board[x][y] == 'B')
	{
		i = x + 1;
		j = y + 1;
		while (i < n && j < m)
		{
			if (board[i][j] != 'E')
			{
				break;
			}
			attack[i][j] = 1;
			i++;
			j++;
		}
		i = x + 1;
		j = y - 1;
		while (i < n && j >= 0)
		{
			if (board[i][j] != 'E')
			{
				break;
			}
			attack[i][j] = 1;
			i++;
			j--;
		}
		i = x - 1;
		j = y - 1;
		while (i >= 0 && j >= 0)
		{
			if (board[i][j] != 'E')
			{
				break;
			}
			attack[i][j] = 1;
			i--;
			j--;
		}
		i = x - 1;
		j = y + 1;
		while (i >= 0 && j < m)
		{
			if (board[i][j] != 'E')
			{
				break;
			}
			attack[i][j] = 1;
			i--;
			j++;
		}
	}
	else if (board[x][y] == 'R')
	{
		i = x-1;
		while (i >= 0)
		{
			if (board[i][y] != 'E')
			{
				break;
			}
			attack[i][y] = 1;
			i--;
		}
		i = x + 1;
		while (i < n)
		{
			if (board[i][y] != 'E')
			{
				break;
			}
			attack[i][y] = 1;
			i++;
		}
		j = y - 1;
		while (j >= 0)
		{
			if (board[x][j] != 'E')
			{
				break;
			}
			attack[x][j] = 1;
			j--;
		}
		j = y + 1;
		while (j < m)
		{
			if (board[x][j] != 'E')
			{
				break;
			}
			attack[x][j] = 1;
			j++;
		}
	}
	else if (board[x][y] == 'N')
	{
		for (i = 0; i < 8; i++)
		{
			dx = x + knight[i][0];
			dy = y + knight[i][1];
			if (dx < 0 || dx >= n || dy < 0 || dy >= m)
			{
				continue;
			}
			if (board[dx][dy] != 'E')
			{
				break;
			}
			attack[dx][dy] = 1;
		}
	}
	else if (board[x][y] == 'P')
	{
		if (x-1 >= 0 && board[x-1][y] == 'E')
		{
			attack[x-1][y] = 1;
		}
	}
	else if (board[x][y] == 'p')
	{
		if (x + 1 < n && board[x+1][y] == 'E')
		{
			attack[x+1][y] = 1;
		}
	}
}

void Solve()
{
	Init();
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (ac[i][j] >= 0)
			{
				DealSth(i, j);
			}
		}
	}
	int ans = 0;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (board[i][j] == 'E' && attack[i][j] == 0)
			{
				ans++;
			}
		}
	}
	printf("%d\n", ans);
}

int main()
{
	n = m = 8;
	while (scanf(" %s", &ch) != EOF)
	{
		Input();
		Solve();
	//	scanf(" %s", &ch);
	}
	return 0;
}
