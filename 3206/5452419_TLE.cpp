#include <iostream>
using namespace std;
#define N 285
struct BIG
{
	int nSize;
	int dig[N];
}dp[501][501];
void Plus(BIG a, BIG b, BIG *c)
{
	int i, nCarry = 0;
	if (a.nSize < b.nSize)
	{
		for (i = 0; i < a.nSize; i++)
		{
			c->dig[i] = (a.dig[i] + b.dig[i] + nCarry) % 10000;
			nCarry = (a.dig[i] + b.dig[i] + nCarry) / 10000;
		}
		while(i < b.nSize)
		{
			c->dig[i] = (b.dig[i] + nCarry) % 10000;
			nCarry = (b.dig[i] + nCarry) / 10000;
			i++;
		}
		if (nCarry)
		{
			c->dig[i++] = nCarry;
		}
		c->nSize = i;
	}
	else
	{
		for (i = 0; i < b.nSize; i++)
		{
			c->dig[i] = (a.dig[i] + b.dig[i] + nCarry) % 10000;
			nCarry = (a.dig[i] + b.dig[i] + nCarry) / 10000;
		}
		while(i < a.nSize)
		{
			c->dig[i] = (a.dig[i] + nCarry) % 10000;
			nCarry = (a.dig[i] + nCarry) / 10000;
			i ++;
		}
		if (nCarry)
		{
			c->dig[i++] = nCarry;
		}
		c->nSize = i;
	}
}
void Cheng(BIG x, int k, BIG *y)
{
	int i;
	for (i = 0; i < x.nSize; i++)
	{
		y->dig[i] = (x.dig[i]) * k;
	}
	y->dig[i] = 0;
	for (i = 0; i < x.nSize; i++)
	{
		x.dig[i+1] += x.dig[i] / 10000;
		x.dig[i] %= 10000;
	}
	if (y->dig[i])
	{
		y->nSize = i + 1;
	}
	else
		y->nSize = i;
}
void Solve()
{
	int i, j;
	BIG x, y;
	dp[1][1].dig[0] = 1;
	dp[1][1].nSize = 1;
	for (i = 2; i <= 500; i++)
	{
		dp[i][1].dig[0] = 1;
		dp[i][1].nSize = 1;
		dp[i][i].dig[0] = 1;
		dp[i][i].nSize = 1;
		for (j = 2; j < i; j++)
		{
			Cheng(dp[(i-1)][j], j, &x);
			Cheng(dp[(i-1)][j-1], i-j+1, &y);
			Plus(x, y, &dp[i][j]);
		}
	}
}
void Show(BIG x)
{
	printf("%d", x.dig[x.nSize-1]);
	int i;
	for (i = x.nSize - 2; i >= 0; i--)
	{
		printf("%04d", x.dig[i]);
	}
	printf("\n");
}
int main()
{
	int n, m;
	Solve();
//	printf("ok");
	while(scanf("%d %d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		Show(dp[n][m]);
	}
	return 0;
}