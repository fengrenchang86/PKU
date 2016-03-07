#include <iostream>
using namespace std;
int p[20][20];
double dp[20][20][20];
bool visit[20][20][20];
char szName[20][20];
void Input()
{
	int i, j, k;
	for (i = 0; i < 16; i++)
	{
		scanf(" %s", &szName[i]);
	}
	for (i = 1; i <= 16; i++)
	{
		for (j = 1; j <= 16; j++)
		{
			scanf("%d", &p[i][j]);
			for (k = 0; k <= 16; k++)
			{
				visit[i][j][k] = 0;
			}
		}
	}
}
void dfs(int nBegin, int nEnd, int winner)
{
	if (visit[nBegin][nEnd][winner])
	{
		return;
	}
	visit[nBegin][nEnd][winner] = true;
	if (nEnd == nBegin + 1)
	{
		if (winner == nBegin)
		{
			dp[nBegin][nEnd][winner] = (double)p[nBegin][nEnd] / 100.0;
		}
		else
		{
			dp[nBegin][nEnd][winner] = (double)p[nEnd][nBegin] / 100.0;
		}
		return;
	}
	int i;
	int nMid = (nBegin + nEnd) / 2;
	if (winner <= nMid)
	{
		dfs(nBegin, nMid, winner);
		dp[nBegin][nEnd][winner] = 0;
		for (i = nMid + 1; i <= nEnd; i++)
		{
			dfs(nMid + 1, nEnd, i);
			dp[nBegin][nEnd][winner] += dp[nMid + 1][nEnd][i] * (double)p[winner][i] / 100.0;
		}
		dp[nBegin][nEnd][winner] *= dp[nBegin][nMid][winner];
	}
	else
	{
		dfs(nMid + 1, nEnd, winner);
		dp[nBegin][nEnd][winner] = 0;
		for (i = nBegin; i <= nMid; i++)
		{
			dfs(nBegin, nMid, i);
			dp[nBegin][nEnd][winner] += dp[nBegin][nMid][i] * (double)p[winner][i] / 100.0;
		}
		dp[nBegin][nEnd][winner] *= dp[nMid+1][nEnd][winner];
	}
}
int main()
{
	Input();
	int i, j;
	for (i = 1; i <= 16; i++)
	{
		dfs(1, 16, i);
	}
	for (i = 1; i <= 16; i++)
	{
		printf("%s", szName[i-1]);
		j = 10 - strlen(szName[i-1]);
		while (j--)
		{
			printf(" ");
		}
		printf(" p=%.2lf%%\n", dp[1][16][i]*100);
	}
	return 0;
}