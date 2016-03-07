#pragma warning (disable:4786)
#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>

using namespace std;

struct ac
{
	int x, y;
}t[100][7000];
int nSize[100];
map<string, int>ma;
char table[1210][100];
int ans;

char strA[100], strB[100];

int n, m, len;

char szStr[100];


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
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= m; j++)
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
	for(i = 0; i < len; i++)
		nSize[i] = 0;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			if(strA[i] == strB[j])
			{
				t[dp[i+1][j+1]][nSize[dp[i+1][j+1]]].x = i;
				t[dp[i+1][j+1]][nSize[dp[i+1][j+1]]].y = j;
				nSize[dp[i+1][j+1]]++;
			}
		}
	}
}

void dfs(int lay, int x, int y)
{
	if(lay == len)
	{
		strcpy(table[ans], szStr);
		ans++;
		return;
	}
	int i, n = nSize[lay+1];
	for(i = 0; i < n; i++)
	{
		if(t[lay+1][i].x > x && t[lay+1][i].y > y)
		{
			szStr[lay] = strA[t[lay+1][i].x];
			szStr[lay+1] = NULL;
			if(ma[szStr] == 0)
			{
				ma[szStr] = 1;
				dfs(lay+1, t[lay+1][i].x, t[lay+1][i].y);
			}
		}
	}
}
void Solve()
{
	ma.clear();
	ans = 0;
	Getlcs();
	dfs(0, -1, -1);
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