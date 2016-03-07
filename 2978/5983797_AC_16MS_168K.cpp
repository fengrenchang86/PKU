#include <iostream>
#include <stdlib.h>
using namespace std;
int a[200];
int b[200];
int c[20];
int d[20];
int dp[200][10];
bool visit[20];
int n, k;
int g_ans;
int cmp(const void*a, const void*b)
{
	if (*(int*)a > *(int*)b)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
void Input()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	qsort(b, n, sizeof(b[0]), cmp);
	c[0] = b[0];
	j = 1;
	for (i = 1; i < n; i++)
	{
		if (b[i] != b[i-1])
		{
			c[j] = b[i];
			j++;
		}
	}
	k = j;
	g_ans = 2000000000;
	memset(visit, 0, sizeof(visit));
}
int GetAns()
{
	int ans = 2000000000;
	int i, j;
	for (i = 0; i < k; i++)
	{
		if (a[0] != d[i])
		{
			dp[0][i] = 1;
		}
		else
			dp[0][i] = 0;
	}
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < k; j++)
		{
			dp[i][j] = 2000000000;
			if (a[i] == d[j])
			{
				if (j == 0)
				{
					dp[i][j] = dp[i-1][j];
				}
				if (j > 0 && dp[i-1][j-1] < dp[i-1][j])
				{
					dp[i][j] = dp[i-1][j-1];
				}
				else if (j > 0)
				{
					dp[i][j] = dp[i-1][j];
				}
			}
			else
			{
				if (j == 0)
				{
					dp[i][j] = dp[i-1][j] + 1;
				}
				if (j > 0 && dp[i-1][j-1] < dp[i-1][j])
				{
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				else if(j > 0)
				{
					dp[i][j] = dp[i-1][j] + 1;
				}
			}
		}
	}
	for (i = 0; i < k; i++)
	{
		if (dp[n-1][i] < ans)
		{
			ans = dp[n-1][i];
		}
	}
	return ans;
}

void dfs(int lay)
{
	if (lay == k)
	{
		int x = GetAns();
		if (x < g_ans)
		{
			g_ans = x;
		}
		return;
	}
	int i;
	for (i = 0; i < k; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			d[lay] = c[i];
			dfs(lay + 1);
			visit[i] = false;
		}
	}
}
int main()
{
	while(scanf("%d %d", &n, &k) != EOF)
	{
		if (n == 0 && k == 0)
		{
			break;
		}
		Input();
		dfs(0);
		printf("%d\n", g_ans);
	}
	return 0;
}