#include <iostream>
using namespace std;
struct ac
{
	int x, y;
}path[30];
int n, m;
bool board[30][30];
char Finalans[10000];
int Flag;
char ans[10000];
int dir[8][2] = {{-2,-1},{-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
void dfs(int lay, int x, int y, int pos)
{
	if (lay == n * m)
	{
		ans[pos] = 0;
		printf("%s\n", ans);
		strcpy(Finalans, ans);
		Flag = 1;
		return;
	}
	if (Flag)
	{
		return;
	}
	board[x][y] = 1;
	int i, j, k, dx, dy;
	for (i = 0; i < 8; i++)
	{
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if (dx >= 0 && dx < n && dy >= 0 && dy < m && board[dx][dy] == 0)
		{
			k = pos;
			ans[k++] = (char)('A'+dx);
			if (dy >= 10)
			{
				ans[k++] = (char)('1'+dy/10);
			}
			ans[k++] = (char)('1' + dy % 10);
			if (Flag == 1)
			{
				for (j = pos; j < k; j++)
				{
					if (ans[j] > Finalans[j])
					{
						break;
					}
				}
				if (j == k)
				{
					dfs(lay + 1, dx, dy, k);
				}
			}
			else
			{
				dfs(lay + 1, dx, dy, k);
			}
		}
	}
	board[x][y] = 0;
}
void Solve()
{
	int i, j, k, l;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			board[i][j] = 0;
		}
	}
	Flag = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			k = 0;
			ans[k++] = (char)('A' + i);
			if (j >= 10)
			{
				ans[k++] = (char)('1' + j/10);
			}
			ans[k++] = (char)('1' + j % 10);
			if (Flag)
			{
				for (l = 0; l < k; l++)
				{
					if (ans[l] > Finalans[l])
					{
						break;
					}
				}
				if (l == k)
				{
					dfs(1, i, j, k);
				}
			}
			else
			{
				dfs(1, i, j, k);
			}
		}
	}
	if (!Flag)
	{
		printf("impossible\n");
	}
	else
	{
//		printf("%s\n", Finalans);
	}
}
int main()
{
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++)
	{
		scanf("%d %d", &m, &n);
		printf("Scenario #%d:\n", i);
		Solve();
		printf("\n");
	}
	return 0;
}