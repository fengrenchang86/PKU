#include <iostream>
using namespace std;
int dp[30][30];
int Arr[30];
char szStr[30];
void Init()
{
	int i, j, k;
	for(i = 1; i <= 26; i++)
		dp[1][i] = 1;
	Arr[1] = 26;
	for(i = 2; i <= 26; i++)
	{
		Arr[i] = 0;
		for(j = 1; j <= 27 - i; j++)
		{
			dp[i][j] = 0;
			for(k = j + 1; k <= 28 - i; k++)
				dp[i][j] += dp[i-1][k];
			Arr[i] += dp[i][j];
		}
	}
}
int Solve()
{
	int i, j, k = 0;
	int n = strlen(szStr);
	if(n == 1)
		return int(szStr[0] - 'a' + 1);
	for(i = 1; szStr[i] != NULL; i++)
	{
		if(szStr[i] <= szStr[i-1])
			return 0;
	}
	for(j = 1; j < i; j++)
		k += Arr[j];
	for(j = 1; j < szStr[0] - 'a' + 1; j++)
		k += dp[n][j];
	for(i = n - 1; i >= 1; i--)
	{
		for(j = szStr[n - i - 1] - 'a' + 2; j < szStr[n - i] - 'a' + 1; j++)
			k += dp[i][j];
	}
	k++;
	return k;
}
int main()
{
	Init();
	int x;
	while(scanf("%s", szStr) != EOF)
	{
		x = Solve();
		printf("%d\n", x);
	}
	return 0;
}