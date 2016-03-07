#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int c, h, mxh;
}t[500];

int dp[500][41000];
int n, m;
int cmp(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return c->mxh - d->mxh;
}
void Input()
{
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%d %d %d", &t[i].h, &t[i].mxh, &t[i].c);
	}
	qsort(t, n, sizeof(t[0]), cmp);
}
void Solve()
{
	int i, j, k;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j <= t[i].mxh; j++)
			dp[i][j] = false;
	}
	for(k = 0; k <= t[0].c; k++)
	{
		if(t[0].h * k <= t[0].mxh)
			dp[0][t[0].h * k] = true;
		else
			break;		
	}
	for(i = 1; i < n; i++)
	{
		dp[i][0] = true;
		for(j = 1; j <= t[i].mxh; j++)
		{
			dp[i][j] = dp[i-1][j];
			for(k = 1; !dp[i][j] && k * t[i].h < t[i].mxh && k <= t[i].c; k++)
			{
				if(j >= t[i].h * k)
					dp[i][j] = dp[i-1][j - t[i].h * k];
				else
					break;
			}
		}
	}
	for(j = t[n-1].mxh; j >= 0; j--)
	{
		if(dp[n-1][j])
			break;
	}
	printf("%d\n", j);
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}
