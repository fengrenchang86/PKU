#include <iostream>
using namespace std;
int dice[20][6];
int dp[20][8];
int p[6] = {5, 3, 4, 1, 2, 0};
int n;
int f(int a, int b, int i)
{
	int j;
	int k = -1;
	for(j = 0; j < 6; j++)
	{
		if(j == a || j == b)
			continue;
		if(dice[i][j] > k)
		{
			k = dice[i][j];
		}
	}
	return k;
}
void Input()
{
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < 6; j++)
		{
			scanf("%d", &dice[i][j]);
			if(dice[i][j] < 1 || dice[i][j] > 6)
				while(1);
		}
	}
}
void Solve()
{
	int i, j, k, l;
	for(i = 0; i < 6; i++)
	{
		dp[0][i] = f(i, p[i], 0);
	}
	for(i = 1; i < n; i++)
	{
		for(j = 0; j < 6; j++)
		{
			l = f(j, p[j], i);
			dp[i][j] = -1;
			for(k = 0; k < 6; k++)
			{
				if(dice[i][p[j]] == dice[i-1][k])
				{
					if(dp[i][j] < dp[i-1][k] + l && dp[i-1][k] != -1)
						dp[i][j] = dp[i-1][k] + l;
				}
			}
		}
	}
	k = -1;
	for(i = 0; i < 6; i++)
	{
		if(dp[n-1][i] > k)
			k = dp[n-1][i];
	}
	if(k < 0)
		k = 0;
	printf("%d\n", k);
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