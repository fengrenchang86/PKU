#include <iostream>
using namespace std;
int dp[120][120];
int path[120][120][2];
char a[120];
int dfs(int x, int y)
{
	if (dp[x][y] >= 0)
	{
		return dp[x][y];
	}
	if (x == y)
	{
		dp[x][y] = 1;
		return 1;
	}
	else if (y - x == 1)
	{
		if (a[x] == '(' && a[y] == ')' || a[x] == '[' && a[y] == ']')
		{
			dp[x][y] = 0;
			return 0;
		}
		else
		{
			dp[x][y] = 2;
			return 2;
		}
	}
	else
	{
		path[x][y][0] = x+1;
		path[x][y][1] = y-1;
		dp[x][y] = dfs(x+1, y-1);
		if (!(a[x] == '(' && a[y] == ')' || a[x] == '[' && a[y] == ']'))
		{
			dp[x][y] += 2;
		}
		int i, p, q;
		for (i = x; i < y; i++)
		{
			p = dfs(x, i);
			q = dfs(i+1,y);
			if (dp[x][y] > p + q)
			{
				dp[x][y] = p + q;
				path[x][y][0] = x;
				path[x][y][1] = i;
			}
		}
	}
	return dp[x][y];
}
void Show(int x, int y)
{
	if (x == y)
	{
		if (a[x] == '(' || a[x] == ')')
		{
			printf("()");
		}
		else
		{
			printf("[]");
		}
	}
	else if (y - x == 1)
	{
		if (a[x] == '(' && a[y] == ')')
		{
			printf("()");
		}
		else if (a[x] == '[' && a[y] == ']')
		{
			printf("[]");
		}
		else
		{
			if (a[x] == '(' || a[x] == ')')
			{
				printf("()");
			}
			else
			{
				printf("[]");
			}
			if (a[y] == '(' || a[y] == ')')
			{
				printf("()");
			}
			else
			{
				printf("[]");
			}
		}
	}
	else if (path[x][y][0] == x + 1)
	{
		if (a[x] == '(' && a[y] == ')')
		{
			printf("(");
			Show(x+1, y-1);
			printf(")");
		}
		else if (a[x] == '[' && a[y] == ']')
		{
			printf("[");
			Show(x+1, y-1);
			printf("]");
		}
		else
		{
			if (a[x] == '(' || a[x] == ')')
			{
				printf("()");
			}
			else
			{
				printf("[]");
			}
			Show(x+1,y-1);
			if (a[y] == '(' || a[y] == ')')
			{
				printf("()");
			}
			else
			{
				printf("[]");
			}
		}
	}
	else
	{
		Show(x, path[x][y][1]);
		Show(path[x][y][1]+1, y);
	}
}
int main()
{
	
	int i, j;
	int n;
	while (scanf(" %s", &a) != EOF)
	{
		for (i = 0; i < 100; i++)
		{
			for (j = 0; j < 100; j++)
			{
				dp[i][j] = -1;
			}
		}
		n = strlen(a);
		dfs(0, n-1);
		Show(0, n-1);
		printf("\n");
	}
	return 0;
}