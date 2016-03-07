#include <iostream>
using namespace std;
bool w[365][9][7][7][7][7];
int n;
bool c[365][9];
char a[365][16];
bool gflag;
void Input()
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 16; j++)
		{
			scanf("%d", &k);
			if (k == 0)
				a[i][j] = 0;
			else
				a[i][j] = 1;
		}
	}
	for (i = 0; i < n; i++)
	{
		memset(w[i], 0, sizeof(w[i]));
	}
}

void GetPos(int pos, int*x, int *y)
{
	*x = pos / 3;
	*y = pos % 3;
}
int GetPos(int x, int y)
{
	if (x < 0 || x >= 3 || y < 0 || y >= 3)
	{
		return -1;
	}
	return x * 3 + y;
}
void Init()
{
	int i, j;
	int x, y;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 9; j++)
		{
			GetPos(j, &x, &y);
			if (a[i][4*x+y] == true)
			{
				c[i][j] = false;
				continue;
			}
			if (a[i][4*(x+1)+y] == true)
			{
				c[i][j] = false;
				continue;
			}
			if (a[i][4*x+y+1] == true)
			{
				c[i][j] = false;
				continue;
			}
			if (a[i][4*(x+1)+y+1] == true)
			{
				c[i][j] = false;
				continue;
			}
			c[i][j] = true;
		}
	}
}
void dfs(int nDay, int nPos, int x1, int x2, int x3, int x4)
{
	if (gflag)
	{
		return;
	}
	if (nPos == 0)
	{
		x1 = 0;
	}
	else if (nPos == 2)
	{
		x2 = 0;
	}
	else if (nPos == 6)
	{
		x3 = 0;
	}
	else if (nPos == 8)
	{
		x4 = 0;
	}
	if (x1 > 6 || x2 > 6 || x3 > 6 || x4 > 6)
	{
		return;
	}
	if (w[nDay][nPos][x1][x2][x3][x4] || c[nDay][nPos] == false)
	{
		return;
	}
	if (nDay == n-1)
	{
		gflag = true;
		return;
	}
	w[nDay][nPos][x1][x2][x3][x4] = true;
	int x, y, pos;
	GetPos(nPos, &x, &y);
	int i;
	dfs(nDay+1, nPos, x1+1, x2+1, x3+1, x4+1);
	for (i = 1; i <= 2; i++)
	{
		pos = GetPos(x - i, y);
		if (pos >= 0)
		{
			dfs(nDay + 1, pos, x1 + 1, x2 + 1, x3 + 1, x4 + 1);
		}
		pos = GetPos(x + i, y);
		if (pos >= 0)
		{
			dfs(nDay + 1, pos, x1 + 1, x2 + 1, x3 + 1, x4 + 1);
		}
		pos = GetPos(x, y - i);
		if (pos >= 0)
		{
			dfs(nDay + 1, pos, x1 + 1, x2 + 1, x3 + 1, x4 + 1);
		}
		pos = GetPos(x, y + i);
		if (pos >= 0)
		{
			dfs(nDay + 1, pos, x1 + 1, x2 + 1, x3 + 1, x4 + 1);
		}
	}
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			break;
		}
		Input();
		Init();
		gflag = false;
		dfs(0, 4, 1, 1, 1, 1);
		if (gflag)
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
	}
	
	return 0;
}