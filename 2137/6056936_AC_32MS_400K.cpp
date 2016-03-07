#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define INF 2000000000
struct ac
{
	int x, y;
}a[120][120];
double dp[120][120];
int arrSize[120];
int n;
void Input()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arrSize[i]);
		for (j = 0; j < arrSize[i]; j++)
		{
			scanf("%d %d", &a[i][j].x, &a[i][j].y);
		}
	}
}
double GetDis(ac t1, ac t2)
{
	return double(sqrt(double(t1.x-t2.x)*double(t1.x-t2.x) + double(t1.y-t2.y)*double(t1.y-t2.y)));
}
double GetMin(double t1, double t2)
{
	return t1 < t2 ? t1 : t2;
}
void Solve()
{
	int i, j, k, l;
	double ans = INF;
	for (i = 0; i < 120; i++)
	{
		for (j = 0; j < 120; j++)
		{
			dp[i][j] = INF;
		}
	}
	for (l = 0; l < arrSize[0]; l++)
	{
		for (i = 0; i < arrSize[1]; i++)
		{
			dp[1][i] = GetDis(a[1][i], a[0][l]);
		}
		for (i = 2; i < n - 1; i++)
		{
			for (j = 0; j < arrSize[i]; j++)
			{
				dp[i][j] = INF;
				for (k = 0; k < arrSize[i-1]; k++)
				{
					dp[i][j] = GetMin(dp[i][j], dp[i-1][k]+GetDis(a[i-1][k], a[i][j]));
				}
			}
		}
		i = n - 1;
		for (j = 0; j < arrSize[n-1]; j++)
		{
			dp[i][j] = INF;
			for (k = 0; k < arrSize[i-1]; k++)
			{
				dp[i][j] = GetMin(dp[i][j], dp[i-1][k]+GetDis(a[i-1][k], a[i][j])+GetDis(a[i][j], a[0][l]));
			}
			if (dp[i][j] < ans)
			{
				ans = dp[i][j];
			}
		}
	}
	printf("%d\n", (int)(ans * 100));
}
int main()
{
	scanf("%d", &n);
	Input();
	Solve();
	return 0;
}