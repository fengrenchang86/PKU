#include <iostream>
using namespace std;
int C, G;
int dp[23][16000];
int w[23], p[23];
void Init()
{
	int i, j;
	for(i = 0; i <= 20; i++)
	{
		for(j = 0; j <= 16000; j++)
			dp[i][j] = 0;
	}
}
void Input()
{
	int i;
	for(i = 1; i <= C; i++)
		scanf("%d", &p[i]);
	for(i = 1; i <= G; i++)
		scanf("%d", &w[i]);
}
void Solve()
{
	Init();
	dp[0][7500] = 1;
	int i, j, k;
	for(i = 1; i <= G; i++)
	{
		for(j = 0; j <= 15000; j++)
		{
			for(k = 1; k <= C; k++)
			{
				if(j >= w[i] * p[k])
					dp[i][j] += dp[i-1][j-w[i]*p[k]];
			}
		}
	}
	printf("%d\n", dp[G][7500]);
}
int main()
{
	while(scanf("%d %d", &C, &G) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}