
#include <iostream>
#include <stdlib.h>
using namespace std;

int a[2100], b[2100];
int ans, n, m;
int acMin[2100][2100];
int dp[2100][2100];

int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int cmp2(const void* a, const void* b)
{
	return *(int*)b - *(int*)a;
}
int GetMin(int x, int y)
{
	return x < y ? x : y;
}
void Input()
{
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
}

void Solve()
{
	int i, j;
	qsort(b, n, sizeof(b[0]), cmp);
	j = 1;
	for(i = 1; i < n; i++)
	{
		if(b[i] != b[i-1])
			b[j++] = b[i];
	}
	m = j;
	
	dp[0][0] = abs(a[0] - b[0]);
	acMin[0][0] = dp[0][0];
	for(j = 1; j < m; j++)
	{
		dp[0][j] = abs(a[0] - b[j]);
		acMin[0][j] = GetMin(acMin[0][j-1], dp[0][j]);
	}
	for(i = 1; i < n; i++)
	{
		dp[i][0] = dp[i-1][0] + abs(a[i] - b[0]);
		acMin[i][0] = dp[i][0];
		for(j = 1; j < m; j++)
		{
			dp[i][j] = acMin[i-1][j] + abs(a[i] - b[j]);
			acMin[i][j] = GetMin(acMin[i][j-1], dp[i][j]);
		}
	}
	ans = 2000000000;
	
	for(j = 0; j < m; j++)
	{
		if(dp[n-1][j] < ans)
			ans = dp[n-1][j];
	}
	
	for(i = 0; i < n; i++)
		b[i] = a[i];
	qsort(b, n, sizeof(b[0]), cmp2);
	j = 1;
	for(i = 1; i < n; i++)
	{
		if(b[i] != b[i-1])
			b[j++] = b[i];
	}
	
	m = j;
	
	dp[0][0] = abs(a[0] - b[0]);
	acMin[0][0] = dp[0][0];
	for(j = 1; j < m; j++)
	{
		dp[0][j] = abs(a[0] - b[j]);
		acMin[0][j] = GetMin(acMin[0][j-1], dp[0][j]);
	}
	for(i = 1; i < n; i++)
	{
		dp[i][0] = dp[i-1][0] + abs(a[i] - b[0]);
		acMin[i][0] = dp[i][0];
		for(j = 1; j < m; j++)
		{
			dp[i][j] = acMin[i-1][j] + abs(a[i] - b[j]);
			acMin[i][j] = GetMin(acMin[i][j-1], dp[i][j]);
		}
	}
	for(j = 0; j < m; j++)
	{
		if(dp[n-1][j] < ans)
			ans = dp[n-1][j];
	}
	printf("%d\n", ans);
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