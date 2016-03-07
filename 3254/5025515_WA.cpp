#include <iostream>
#include <vector>
using namespace std;
unsigned int RowStatue[13];
vector<unsigned int>RowValid[13];
vector<unsigned int>CanValid;
int dp[13][5000];
int n, m;
unsigned int t;

void Init()
{
	int i, j;
	t = 1 << (1+n);
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j < 5000; j++)
			dp[i][j] = 0;
	}
	for(i = 0; i < 13; i++)
		RowValid[i].clear();
	CanValid.clear();
	for(i = 0; i < t; i++)
	{
		if((i & (i<<1)) == 0)
			CanValid.push_back(i);
	}
}
void Input()
{
	int i, j, k;
	
	for(i = 0; i < n; i++)
	{
		RowStatue[i] = 0;
		for(j = 0; j < m; j++)
		{
			scanf("%d", &k);
			if(k == 1)
			{
				RowStatue[i] |= (1 << j);
			}
		}
		for(j = 0; j < CanValid.size(); j++)
		{
			k = CanValid[j];
			if((CanValid[j] | RowStatue[i]) == RowStatue[i])
				RowValid[i].push_back(CanValid[j]);
		}
	}
}
void Solve()
{
	int i, j, k;
	for(i = 0; i < RowValid[0].size(); i++)
	{
		k = RowValid[0][i];
		dp[0][RowValid[0][i]] = 1;
	}
	for(i = 1; i < n; i++)
	{
		for(j = 0; j < RowValid[i].size(); j++)
		{
			dp[i][RowValid[i][j]] = 0;
			for(k = 0; k < RowValid[i-1].size(); k++)
			{
				if((RowValid[i][j] & RowValid[i-1][k]) == 0)
				{
					dp[i][RowValid[i][j]] += dp[i-1][RowValid[i-1][k]];
					dp[i][RowValid[i][j]] %= 100000000;
				}
			}
		}
	}
	j = 0;
	for(i = 0; i < RowValid[n-1].size(); i++)
	{
		j += dp[n-1][RowValid[n-1][i]];
		j %= 100000000;
	}
	printf("%d\n", j);
}
int main()
{
	scanf("%d %d", &n, &m);
	Init();
	Input();
	Solve();
	return 0;
}
