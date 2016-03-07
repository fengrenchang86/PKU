#include <iostream>
using namespace std;
int dice[20][10];
int dp[20][10];
int n;
void Input()
{
	int t[10];
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < 6; j++)
			scanf("%d", &t[j]);
		dice[i][t[0]] = t[5];
		dice[i][t[5]] = t[0];
		dice[i][t[1]] = t[3];
		dice[i][t[3]] = t[1];
		dice[i][t[2]] = t[4];
		dice[i][t[4]] = t[2];
	}
}
int GetNum(int x, int y)
{
	int i;
	for(i = 6; i >= 1; i--)
	{
		if(i != x && i != y)
			break;
	}
	return i;
}
void Solve()
{
	int i, j;
	for(i = 1; i <= 6; i++)
	{
		dp[0][i] = GetNum(i, dice[0][i]);
	}
	for(i = 1; i < n; i++)
	{
		for(j = 0; j <= 6; j++)
			dp[i][j] = -1;
	}
	for(i = 1; i < n; i++)
	{
		for(j = 1; j <= 6; j++)
		{
			if(dp[i][j] < GetNum(j, dice[i][j]) + dp[i-1][dice[i][j]])
				dp[i][j] = GetNum(j, dice[i][j]) + dp[i-1][dice[i][j]];
		}
	}
	j = 0;
	for(i = 1; i <= 6; i++)
	{
		if(dp[n-1][i] > j)
			j = dp[n-1][i];
	}
	printf("%d\n", j);
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		Input();
		Solve();
	}
	return 0;
}