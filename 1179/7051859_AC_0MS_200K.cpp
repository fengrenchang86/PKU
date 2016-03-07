#include <iostream>
using namespace std;
int dp[100][100][2];
int a[100];
char ope[100];
int n;
//4
//t -7 t 4 x 2 x 5
int GetMax(int x, int y)
{
	return x > y ? x : y;
}
int GetMax(int x1, int x2, int x3, int x4)
{
	return GetMax(GetMax(x1, x2), GetMax(x3, x4));
}
int GetMin(int x,int y)
{
	return x < y ? x : y;
}
int GetMin(int x1, int x2, int x3, int x4)
{
	return GetMin(GetMin(x1, x2), GetMin(x3,x4));
}
void Solve()
{
	int i, j, k, t;
	for (i = 0; i < n; i++)
	{
		dp[i][i][0] = dp[i][i][1] = a[i];
	}
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (ope[(j+i)%n] == 't')
			{
				dp[j][(j+i)%n][0] = dp[j][(j+i-1)%n][0] + a[(j+i)%n];
				dp[j][(j+i)%n][1] = dp[j][(j+i-1)%n][1] + a[(j+i)%n];
			}
			else
			{
				dp[j][(j+i)%n][0] = GetMin(dp[j][(j+i-1)%n][0] * a[(j+i)%n], dp[j][(j+i-1)%n][1] * a[(j+i)%n]);
				dp[j][(j+i)%n][1] = GetMax(dp[j][(j+i-1)%n][1] * a[(j+i)%n], dp[j][(j+i-1)%n][1] * a[(j+i)%n]);
			}
			for (k = j; k % n != (i + j)%n; k++)
			{
				if (ope[(k+1)%n] == 't')
				{
					dp[j][(j+i)%n][0] = GetMin(dp[j][(j+i)%n][0], dp[j][(k)%n][0] + dp[(k+1)%n][(j+i)%n][0]);
					dp[j][(j+i)%n][1] = GetMax(dp[j][(j+i)%n][1], dp[j][(k)%n][1] + dp[(k+1)%n][(j+i)%n][1]);
				}
				else
				{
					t = GetMax(dp[j][(k)%n][0] * dp[(k+1)%n][(j+i)%n][0], dp[j][(k)%n][0]*dp[(k+1)%n][(j+i)%n][1],
						dp[j][(k)%n][1]*dp[(k+1)%n][(j+i)%n][0], dp[j][(k)%n][1]*dp[(k+1)%n][(j+i)%n][1]);
					dp[j][(j+i)%n][1] = GetMax(t, dp[j][(j+i)%n][1]);
					t = GetMin(dp[j][(k)%n][0] * dp[(k+1)%n][(j+i)%n][0], dp[j][(k)%n][0]*dp[(k+1)%n][(j+i)%n][1],
						dp[j][(k)%n][1]*dp[(k+1)%n][(j+i)%n][0], dp[j][(k)%n][1]*dp[(k+1)%n][(j+i)%n][1]);
					dp[j][(j+i)%n][0] = GetMin(t, dp[j][(j+i)%n][0]);
				}
			}
		}
	}
	k = dp[0][(n-1)%n][1];
	j = 0;
	for (i = 1; i < n; i++)
	{
		if (dp[i][(i+n-1)%n][1] > k)
		{
			j = i;
			k = dp[i][(i+n-1)%n][1];
		}
	}
	printf("%d\n", k);
	printf("%d", j+1);
	for (i = 0; i < n; i++)
	{
		if (dp[i][(i+n-1)%n][1] == k && i != j)
		{
			printf(" %d", i+1);
		}
	}
	printf("\n");
}
void Input()
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf(" %c %d", &ope[i], &a[i]);
	}
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			break;
		}
		Input();
		Solve();
	}
	return 0;
}