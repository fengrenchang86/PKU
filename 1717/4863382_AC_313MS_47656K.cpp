
#include <iostream>
using namespace std;
int dp[1010][12100];
int a[1001];
int n;
int GetMin(int x, int y)
{
	return x < y ? x : y;
}
int GetMax(int x, int y)
{
	return x > y ? x : y;
}
void Input()
{
	int i ,x ,y;
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		a[i] = x - y + 6000;
	}
}

void Solve()
{
	int nAdd = 6000;
	int i, j, k = 0, x, y;
	for(i = 0; i < n; i++)
		k += (a[i] - 6000);
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= 12000; j++)
			dp[i][j] = n;
	}
	for(i = 0; i < n; i++)
	{
		dp[i][a[i]] = 1;
	}
	for(i = 0; i < n; i++)
		dp[i][6000] = 0;
	for(i = 1; i < n; i++)
	{
		for(j = 0; j <= 12000; j++)
		{
			if(j >= a[i]-6000)
				dp[i][j] = GetMin(dp[i-1][j], dp[i-1][j-a[i]+6000]+1);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	if(k % 2 == 0)
	{
		k/=2;
		k += 6000;
		j = GetMin(n, dp[n-1][k]);
		if(j == n)
		{
			for(i = 1; k+i <= 12000 || k-i >= 0; i++)
			{
				if(k + i <= 12000 && dp[n-1][k+i] < n)
					break;
				if(k - i >= 0 && dp[n-1][k-1] < n)
					break;
			}
			if(k + i <= 12000)
				j = GetMin(j, dp[n-1][k+i]);
			if(k - i >= 0)
				j = GetMin(j, dp[n-1][k-i]);
			j = GetMin(j, n-j);
		}
	}
	else
	{
		if(k > 0)
		{
			x = k/2+6000;
			y = x+1;
		}
		else
		{
			x = k/2-1+6000;
			y = x + 1;
		}
		if(k == -1 || k == 1)
		{
			printf("0\n");
			return;
		}
		j = GetMin(dp[n-1][x], dp[n-1][y]);
		if(j >= n)
		{
			for(i = 1; x - i >= 0 || y + i <= 12000; i++)
			{
				if(x - i >= 0 && dp[n-1][x-i] < n)
					break;
				if(y + i <= 12000 && dp[n-1][y+i] < n)
					break;
			}
			if(x-i >= 0)
				j = GetMin(j, dp[n-1][x-i]);
			if(y+j <= 12000)
				j = GetMin(j, dp[n-1][y+i]);
			j = GetMin(j, n-j);
		}
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
