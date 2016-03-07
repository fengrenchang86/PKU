#pragma warning (disable:4786)
#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
using namespace std;

map<string, int>ma;
char table[1210][100];
int ans;

char strA[100], strB[100];

int n, m, len;

char szStr[100];
//string szStr;

int cmp(const void*a, const void*b)
{
	return strcmp((char*)a, (char*)b);
}
void Getlcs()
{
	int i, j;
	n = strlen(strA);
	m = strlen(strB);
	int dp[100][100];
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
			dp[i][j] = 0;
	}
	for(i = 0; i < n; i++)
	{
		for(j  = 0; j < m; j++)
		{
			if(strA[i] == strB[j])
				dp[i+1][j+1] = dp[i][j] + 1;
			else 
				dp[i+1][j+1] = dp[i][j+1] > dp[i+1][j] ? dp[i][j+1] : dp[i+1][j];
		}
	}
	len = dp[n][m];
}

void dfs(int lay, int pa, int pb)
{
	if(lay == len)
	{
		strcpy(table[ans], szStr);
		ans++;
		return;
	}
	if(pa == n || pb == m)
		return;
	szStr[lay] = strA[pa];
	szStr[lay+1] = NULL;
	int i;
	for(i = pb; i < m; i++)
	{
		if(strB[i] == strA[pa])
			break;
	}
	if(i < m && ma[szStr] == 0)
	{
		ma[szStr] = 1;
		dfs(lay+1, pa+1, i+1);
	}
	szStr[lay] = NULL;
	dfs(lay, pa+1, pb);
}
void Solve()
{
	ans = 0;
	ma.clear();
	Getlcs();
	dfs(0, 0, 0);
	qsort(table, ans, sizeof(table[0]), cmp);
	int i;
	for(i = 0; i < ans; i++)
		printf("%s\n", table[i]);
}
int main()
{
	while(scanf("%s %s", strA, strB) != EOF)
		Solve();
	return 0;
}