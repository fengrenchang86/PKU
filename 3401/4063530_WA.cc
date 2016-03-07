#include <iostream>
using namespace std;
struct ac
{
	int data;
	bool visit;
	char ch;
}dp[300][300];
int n;
char str[300];
void Init()
{
	n = strlen(str);
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = i; j < n; j++)
		{
			dp[i][j].data = j-i+1;
			dp[i][j].visit = false;
		}
		dp[i][i].ch = str[i];
		dp[i][i].visit = true;
	}
}
void Solve(int i, int j)
{
	if(dp[i][j].visit)
		return;
	int k;
	for(k = i+1; k < j; k++)
	{
		Solve(i, k-1);
		Solve(k+1, j);
		if(dp[i][k-1].data == 1 && dp[k+1][j].data == 1 && dp[i][k-1].ch == dp[k+1][j].ch)
		{
			dp[i][j].data = 1;
			dp[i][j].ch = str[k];
		}
		else if(dp[i][j].data > dp[i][k-1].data+1+dp[k+1][j].data)
		{
			dp[i][j].data = dp[i][k-1].data+1+dp[k+1][j].data;
		}
	}
	Solve(i+1, j);
	Solve(i, j-1);
	if(dp[i][j].data > dp[i+1][j].data + 1)
		dp[i][j].data = dp[i+1][j].data + 1;
	if(dp[i][j].data > dp[i][j-1].data + 1)
		dp[i][j].data = dp[i][j-1].data + 1;
	dp[i][j].visit = true;
}
int main ()
{
	while(scanf(" %s", &str) != EOF)
	{
		Init();
		Solve(0, n-1);
		printf("%d\n", dp[0][n-1].data);
	}
	return 0;
}