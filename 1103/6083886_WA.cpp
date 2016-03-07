#include <iostream>
using namespace std;
bool visit[100][100][2];
char a[100][100];
int n, m;
int nCount;
bool flag;
void Input()
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%s", &a[i]);
	}
}
void dfs(int x, int y, int z)
{
	if (visit[x][y][z] == 1)
	{
		return;
	}
	visit[x][y][z] = 1;
	nCount++;
	if (z == 0 && x == 0)
	{
		flag = 0;
	}
	if (z == 1 && x == n-1)
	{
		flag = 0;
	}
	if (y == 0 && (a[x][y] == '/' && z == 0 || a[x][y] == '\\' && z == 1))
	{
		flag = 0;
	}
	if (y == m-1 && (a[x][y] == '/' && z == 1 || a[x][y] == '\\' && z == 0))
	{
		flag = 0;
	}
	if (x > 0 && z == 0)
	{
		dfs(x-1, y, 1);
	}
	if (y > 0 && (a[x][y] == '/' && z == 0 || a[x][y] == '\\' && z == 1))
	{
		if (a[x][y-1] == '/')
		{
			dfs(x, y-1, 1);
		}
		else
		{
			dfs(x, y-1, 0);
		}
	}
	if (x < n-1 && z == 1)
	{
		dfs(x+1, y, 0);
	}
	if (y < m-1 && (a[x][y] == '/' && z == 1 || a[x][y] == '\\' && z == 0))
	{
		if (a[x][y+1] == '/')
		{
			dfs(x, y+1, 0);
		}
		else
		{
			dfs(x, y+1, 1);
		}
	}
}
void Solve(int tc)
{
	int i, j;
	int nAns = 0;
	int nCycle = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (visit[i][j][0] == 0)
			{
				flag = true;
				nCount = 0;
				dfs(i, j, 0);
				if (flag && nCount > nAns)
				{
					nAns = nCount;
				}
				if (flag)
				{
					nCycle ++;
				}
			}
			if (visit[i][j][1] == 0)
			{
				flag = true;
				nCount = 0;
				dfs(i ,j, 1);
				if (flag && nCount > nAns)
				{
					nAns = nCount;
				}
				if (flag)
				{
					nCycle ++;
				}
			}
		}
	}
	printf("Maze #%d:\n", tc);
	if (nCycle > 0)
	{
		printf("%d Cycles; the longest has length %d.\n", nCycle, nAns);
	}
	else
	{
		printf("There are no cycles.\n");
	}
	printf("\n");
}
int main()
{
	int tc = 1;
	while (scanf("%d %d", &m, &n) != EOF)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		Input();
		Solve(tc);
		tc++;
	}
	return 0;
}