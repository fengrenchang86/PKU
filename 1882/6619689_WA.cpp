#include <iostream>
using namespace std;
struct ac
{
	int num;
	int a[12];
	int ans, ans2;
}t[12];
int s, n;
int dp[12][1200];
int c[1200];
void Input()
{
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &t[i].num);
		for (j = 1; j <= t[i].num; j++)
		{
			scanf("%d", &t[i].a[j]);
		}
	}
}
void Solve(int m)
{
	int i, j, k;
	for (i = 0; i <= 10; i++)
	{
		for (j = 0; j <= 1000; j++)
		{
			dp[i][j] = 100;
		}
	}
	for (j = 0; j <= 1000; j++)
	{
		c[j] = 200;
	}
	t[m].ans = 0;
	int nMax = 1000;
	dp[0][0] = 0;
	for (i = 1; i <= t[m].num; i++)
	{
		for (j = 0; j <= nMax; j++)
		{
			for (k = 0; k <= s; k++)
			{
				if (j >= k * t[m].a[i])
				{
					if (dp[i][j] > dp[i-1][j-k*t[m].a[i]] + k && dp[i-1][j-k*t[m].a[i]] + k <= s)
					{
						dp[i][j] = dp[i-1][j-k*t[m].a[i]] + k;
						if (c[j] > t[m].a[i])
						{
							c[j] = t[m].a[i];
						}
					}
				}
			}
		}
	}
	for (j = 1; j <= nMax; j++)
	{
		if (dp[t[m].num][j] > s)
		{
			break;
		}
	}
	j--;
	t[m].ans = j;
	t[m].ans2 = c[j];
}
int main()
{
	int i;
	int ans, ans1, nId;;
	while (scanf("%d", &s) != EOF)
	{
		if (s == 0)
		{
			break;
		}
		ans = 0;
		ans1 = 0;
		Input();
		for (i = 0; i < n; i++)
		{
			Solve(i);
			if (t[i].ans > ans || t[i].ans == ans && t[i].ans2 < ans1)
			{
				ans = t[i].ans;
				ans1 = t[i].ans2;
				nId = i;
			}
		}
		if (ans == 0)
		{
			printf("max coverage = 0 :");
			for (i = 1; i <= t[0].num; i++)
			{
				printf(" %d", t[0].a[i]);
			}
			printf("\n");
		}
		else
		{
			printf("max coverage = %d :", t[nId].ans);
			for (i = 1; i <= t[nId].num; i++)
			{
				printf(" %d", t[nId].a[i]);
			}
			printf("\n");
		}
	}
	return 0;
}