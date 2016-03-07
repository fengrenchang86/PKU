#include <iostream>
#include <vector>
using namespace std;
bool attack[101][101];
int n, m, t;
char board[11][11];
int ac[11][11];
int knight[8][2] = {{-1, -2}, {1, -2}, {-1, 2}, {1, 2}, {-2, -1}, {-2, 1}, {2, -1}, {2, 1}};
int use[100];
int ans;
void Init()
{
	memset(attack, 0, sizeof(attack));
}
void Input()
{
	scanf("%d %d", &m, &n);
	int i, j;
	t = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf(" %c", &board[i][j]);
			if (board[i][j] != 'E')
			{
				ac[i][j] = t;
					t++;
			}
			else
				ac[i][j] = -1;
		}
	}
}
void DealSth(int x, int y)
{
	int i, j;
	int dx, dy;
	int z = ac[x][y];
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
				if (ac[dx][dy] >= 0)
				{
					attack[z][ac[dx][dy]] = 1;
				}
			}
		}
	}
	else if (board[x][y] == 'Q')
	{
		i = x-1;
		j = y-1;
		while (i >= 0 && j >= 0)//--
		{
			if (ac[i][j] >= 0)
			{
				attack[z][ac[i][j]] = 1;
			}
			i--;
			j--;
		}
		i = x-1;
		j = y;
		while (i >= 0)//-0
		{
			if (ac[i][j] >= 0)
			{
				attack[z][ac[i][j]] = 1;
			}
			i--;
		}
		i = x;
		j = y-1;
		while (j >= 0)//0-
		{
			if (ac[i][j] >= 0)
			{
				attack[z][ac[i][j]] = 1;
			}
			j--;
		}
		i = x;
		j = y+1;
		while (j < m)//0+
		{
			if (ac[i][j] >= 0)
			{
				attack[z][ac[i][j]] = 1;
			}
			j++;
		}
		i = x-1;
		j = y+1;
		while (i >= 0 && j < m)//-+
		{
			if (ac[i][j] >= 0)
			{
				attack[z][ac[i][j]] = 1;
			}
			i--;
			j++;
		}
		i = x+1;
		j = y+1;
		while (i < n && j < m)//++
		{
			if (ac[i][j] >= 0)
			{
				attack[z][ac[i][j]] = 1;
			}
			i++;
			j++;
		}
		i = x+1;
		j = y;
		while (i < n)//+0
		{
			if (ac[i][j] >= 0)
			{
				attack[z][ac[i][j]] = 1;
			}
			i++;
		}
		i = x+1;
		j = y-1;
		while (i < n && j >= 0)//+-
		{
			if (ac[i][j] >= 0)
			{
				attack[z][ac[i][j]] = 1;
			}
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
			if (ac[i][j] >= 0)
			{
				attack[z][ac[i][j]] = 1;
			}
			i++;
			j++;
		}
		i = x + 1;
		j = y - 1;
		while (i < n && j >= 0)
		{
			if (ac[i][j] >= 0)
			{
				attack[z][ac[i][j]] = 1;
			}
			i++;
			j--;
		}
		i = x - 1;
		j = y - 1;
		while (i >= 0 && j >= 0)
		{
			if (ac[i][j] >= 0)
			{
				attack[z][ac[i][j]] = 1;
			}
			i--;
			j--;
		}
		i = x - 1;
		j = y + 1;
		while (i >= 0 && j < m)
		{
			if (ac[i][j] >= 0)
			{
				attack[z][ac[i][j]] = 1;
			}
			i--;
			j++;
		}
	}
	else if (board[x][y] == 'R')
	{
		i = x-1;
		while (i >= 0)
		{
			if (ac[i][y] >= 0)
			{
				attack[z][ac[i][y]] = 1;
			}
			i--;
		}
		i = x + 1;
		while (i < n)
		{
			if (ac[i][y] >= 0)
			{
				attack[z][ac[i][y]] = 1;
			}
			i++;
		}
		j = y - 1;
		while (j >= 0)
		{
			if (ac[x][j] >= 0)
			{
				attack[z][ac[x][j]] = 1;
			}
			j--;
		}
		j = y + 1;
		while (j < m)
		{
			if (ac[x][j] >= 0)
			{
				attack[z][ac[x][j]] = 1;
			}
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
			if (ac[dx][dy] >= 0)
			{
				attack[z][ac[dx][dy]] = 1;
			}
		}
	}
}
void dfs(int lay)
{
	int i, k;
	if (lay == t)
	{
		k = 0;
		for (i = 0; i < t; i++)
		{
			if (use[i])
			{
				k++;
			}
		}
		if (k < ans)
		{
			ans = k;
		}
		return;
	}
	if (use[lay] == 0)
	{
		for (i = 0; i < t; i++)
		{
			if (attack[lay][i])
			{
				use[i]++;
			}
		}
		dfs(lay + 1);
		for (i = 0; i < t; i++)
		{
			if (attack[lay][i])
			{
				use[i]--;
			}
		}
	}
	use[lay]++;
	dfs(lay + 1);
	use[lay]--;
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
	for (i = 0; i < t; i++)
	{
		for (j = 0; j < t; j++)
		{
			if (attack[i][j])
			{
				attack[j][i] = 1;
			}
		}
	}
	memset(use, 0, sizeof(use));
	ans = 100;
	dfs(0);
	printf("Minimum Number of Pieces to be removed: %d\n", ans);
}
int main()
{
	char ch[100];
	while (scanf(" %s", &ch) != EOF)
	{
		Input();
		Solve();
		scanf(" %s", &ch);
	}
	return 0;
}