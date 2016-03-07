#include <iostream>
#include <stdlib.h>

using namespace std;

#define inf 200000000
int dp[21][21][11];
int bomb[21][21][11];
int n, m, d;
int acMax(int x, int y)
{
	return x > y?x:y;
}
int acMax(int x, int y, int z)
{
	return acMax(x, acMax(y,z));
}
int Gcd(int x, int y)
{
	if(x == 0)
		return y;
	else if(y == 0)
		return x;
	if(x % y == 0)
		return y;
	return Gcd(y, x%y);
}
void init()
{
	int i, j, k;
	for(i = 0; i <= 20; i++)
	{
		for(j = 0; j <= 20; j++)
		{
			for(k = 0; k <= 10; k++)
			{
				dp[i][j][k] = 0;
				bomb[i][j][k] = 0;
			}
		}
	}
}
void Input()
{
	int i, x, y, t;
	init();
	for(i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &t);
		bomb[x][y][t] = 1;
	}
}
void Solve()
{
	int i, j, k, l, temp, sum;
	int dx, dy;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			dp[i][j][1] = bomb[i][j][1];
	}
	for(k = 1; k <= 10; k++)
	{
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				for(dx = -d; dx <= d; dx++)
				{
					for(dy = -d; dy <= d; dy++)
					{
						if(dx*dx + dy*dy > d*d)
							continue;
						else if(i+dx < 0 || i+dx >= n || j+dy < 0 || j+dy >= n)
							continue;
						if(dx == 0 && dy == 0)
						{
							dp[i][j][k] = acMax(dp[i][j][k], dp[i][j][k-1] + bomb[i][j][k]);
							continue;
						}
						temp = Gcd(abs(dx), abs(dy));
						sum = bomb[i][j][k];
						for(l = 1; l <= 5; l++)
						{
							sum += bomb[i+dx/temp*l][j+dy/temp*l][k];
							if(temp == l)
								break;
						}
						dp[i][j][k] = acMax(dp[i][j][k], dp[i+dx][j+dy][k-1] + sum);
					}
				}
			}
		}
	}
	dx = 0;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			for(k = 1; k <= 10; k++)
			{
				if(dp[i][j][k] > dx)
					dx = dp[i][j][k];
			}
		}
	}
	printf("%d\n", dx);
}
int main()
{
	while(scanf("%d %d %d", &n, &d, &m) != EOF)
	{
		if(n + d + m == 0)
			break;
		Input();
		Solve();
	}
	return 0;
}
