#include <iostream>
#include <math.h>
using namespace std;
struct ac
{
	int x, y, p;
}a[1020];
int sum[1020];
double dp[1020];
int n;
double GetDist(int i, int j)
{
	return sqrt((double)(a[i].x - a[j].x) * (double)(a[i].x - a[j].x) + 
		(double)(a[i].y - a[j].y) * (double)(a[i].y - a[j].y));
}
void Input()
{
	int i, k = 0;
	a[0].x = 0;
	a[0].y = 0;
	a[0].p = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].p);
		k += a[i].p;
		sum[i] = k;
	}
	n++;
	a[n].x = 100;
	a[n].y = 100;
	a[n].p = 0;
}
void Solve()
{
	int i, j;
	double dx,dy,dz;
	double ans = 0;
	dp[0] = 0;
	for (i = 1; i <= n; i++)
	{
		dp[i] = -1.0;
		for (j = 0; j < i; j++)
		{
			dx = dp[j] + (double)(sum[i-1]-sum[j]) + GetDist(j, i) + 1;
			if (dp[i] < 0 || dp[i] > dx)
			{
				dp[i] = dx;
			}
		}
	}
	printf("%.3lf\n", dp[n]);
}
int main()
{
	while (scanf("%d", &n) != EOF)
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