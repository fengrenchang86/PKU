#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
int acMax(int x, int y)
{
	return x > y ? x : y;
}
struct ac
{
	int x, y;
}t[100], a[11];
int n, m;
char str[200];
int dp[102][102];
int val[102][102][2];
int d[102];
void Init()
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		a[i].x = 3 - (i-1)/3;
		a[i].y = (i+2) % 3 + 1;
	}
	a[0].x = 4;
	a[0].y = 1;
	a[10].x = 4;
	a[10].y = 2;

	m = 0;
	for (i = 0; i <= 10; i++)
	{
		for (j = 0; j <= 10; j++)
		{
			if (a[i].y < a[j].y)
			{
				t[m].x = i;
				t[m].y = j;
				m++;
			}
		}
	}
	val[0][0][0] = val[0][0][1] = 0;
	for (i = 1; i < m; i++)
	{
		val[i][i][0] = val[i][i][1] = 0;
		for (j = 0; j < i; j++)
		{
			val[i][j][0] = abs(a[t[i].x].x - a[t[j].x].x) + abs(a[t[i].x].y - a[t[j].x].y);
			val[i][j][1] = abs(a[t[i].y].x - a[t[j].y].x) + abs(a[t[i].y].y - a[t[j].y].y);
			val[j][i][0] = val[i][j][0];
			val[j][i][1] = val[i][j][1];
		}
	}
}
void Solve()
{
	int i, j, k, l;
	for (i = 0; i < n; i++)
	{
		d[i] = str[i] - '0';
	}
	for (i = 0; i < m; i++)
	{
		if ((t[i].x) % 10 == d[0])
		{
			dp[0][i] = acMax(val[19][i][0] + 1, val[19][i][1]);
		}
		else if ((t[i].y) % 10 == d[0])
		{
			dp[0][i] = acMax(val[19][i][1] + 1, val[19][i][0]);
		}
		else
		{
			dp[0][i] = -1;
		}
	}
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			dp[i][j] = -1;
			if ((t[j].x % 10 != d[i] && (t[j].y % 10 != d[i])))
			{
				continue;
			}
			for (k = 0; k < m; k++)
			{
				if (dp[i-1][k] == -1)
				{
					continue;
				}
				if (t[j].x % 10 == d[i])
				{
					l = acMax(val[j][k][0] + 1, val[j][k][1]);
				}
				else
				{
					l = acMax(val[j][k][1] + 1, val[j][k][0]);
				}
				if (dp[i][j] == -1 || dp[i][j] > dp[i-1][k] + l)
				{
					dp[i][j] = dp[i-1][k] + l;
				}
			}
		}
	}
	int ans = -1;
	for (j = 0; j < m; j++)
	{
		if (t[j].x % 10 != d[n-1] && t[j].y % 10 != d[n-1])
		{
			continue;
		}
		if (dp[n-1][j] != -1 && (dp[n-1][j] < ans || ans == -1))
		{
			ans = dp[n-1][j];
		}
	}
	printf("%d\n", ans);
}
int main()
{
	Init();	
	while (scanf("%s", &str) != EOF)
	{
		if (str[0] == 'e')
		{
			break;
		}
		n = strlen(str);
		Solve();
	}
	return 0;
}