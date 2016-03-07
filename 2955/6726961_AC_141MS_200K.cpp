#include <iostream>
using namespace std;
int dp[120][120];
char a[120];
int dfs(int x, int y)
{
	if (dp[x][y] >= 0)
	{
		return dp[x][y];
	}
	if (x == y)
	{
		dp[x][y] = 0;
		return 0;
	}
	else if (y - x == 1)
	{
		if (a[x] == '(' && a[y] == ')' || a[x] == '[' && a[y] == ']')
		{
			dp[x][y] = 2;
			return 2;
		}
		else
		{
			dp[x][y] = 0;
			return 0;
		}
	}
	else
	{
		dp[x][y] = dfs(x+1, y-1);
		if (a[x] == '(' && a[y] == ')' || a[x] == '[' && a[y] == ']')
		{
			dp[x][y] += 2;
		}
		int i, p, q;
		for (i = x; i < y; i++)
		{
			p = dfs(x, i);
			q = dfs(i+1,y);
			if (dp[x][y] < p + q)
			{
				dp[x][y] = p + q;
			}
		}
	}
	return dp[x][y];
}
int main()
{

	int i, j;
	int n;
	while (gets(a))
	{
		if (a[0] == 0)
		{
			printf("0\n");
			continue;
		}
		else if (strcmp(a, "end") == 0)
		{
			break;
		}
		for (i = 0; i < 100; i++)
		{
			for (j = 0; j < 100; j++)
			{
				dp[i][j] = -1;
			}
		}
		n = strlen(a);
		i = dfs(0, n-1);
		printf("%d\n", i);
	}
	return 0;
}