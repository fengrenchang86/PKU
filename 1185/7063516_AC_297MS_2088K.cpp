#include <iostream>
using namespace std;
int dp[102][70][70];
int vec[70];
int ac[70];
int wa[102];
int n, t, m;
void Init()
{
	m = 0;
	int i, j = (1 << t);
	int k;
	for (i = 0; i < j; i++)
	{
		if ((i & (i<<1)) || (i & (i << 2)))
		{
			continue;
		}
		ac[m] = 0;	// attention:acm=0;
		k = i;
		while (k)
		{
			ac[m] += (k&1);
			k /= 2;
		}
		vec[m++] = i;
	}
}
void DP()
{
	int i, j, k, l;
	memset(dp, 0, sizeof(dp));
	for (j = 0; j < m; j++)
	{
		if (vec[j] & wa[0])
		{
			continue;
		}
		dp[0][j][0] = ac[j];
	}
	for (j = 0; j < m; j++)
	{
		if (vec[j] & wa[1])
		{
			continue;
		}
		for (k = 0; k < m; k++)
		{
			if (!(vec[j] & vec[k]) && !(wa[0] & vec[k]))
			{
				dp[1][j][k] = dp[0][k][0] + ac[j];
			}
		}
	}
	for (i = 2; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (wa[i] & vec[j])
			{
				continue;
			}
			for (k = 0; k < m; k++)
			{
				if (wa[i-1] & vec[k])
				{
					continue;
				}
				if (vec[j] & vec[k])
				{
					continue;
				}
				for (l = 0; l < m; l++)
				{
					if ((vec[j] & vec[l]) || (vec[k] & vec[l]))
					{
						continue;
					}
					if (dp[i][j][k] < dp[i-1][k][l] + ac[j])
					{
						dp[i][j][k] = dp[i-1][k][l] + ac[j];
					}
				}
			}
		}
	}
	int ans = 0;
	for (j = 0; j < m; j++)
	{
		for (k = 0; k < m; k++)
		{
			if (ans < dp[n-1][j][k])
			{
				ans = dp[n-1][j][k];
			}
		}
	}
	printf("%d\n", ans);
}
int main()
{
	int i, j, k;
	char ch[500];
	while (scanf("%d %d", &n, &t) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			wa[i] = 0;
			k = 1;
			scanf(" %s", &ch);
			for (j = 0; j < t; j++)
			{
				if (ch[j] == 'H')
				{
					wa[i] += (1 << (t-1-j));
				}
				k *= 2;
			}
		}
		Init();
		DP();
	}
	return 0;
}