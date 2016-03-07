#include<iostream>
using namespace std;
#define INF 2000000
int a[60][60];
int b[60][60];
int c[60][60];
int n, m;
int shang = 200, xia = -1, zuo = 200, you = -1;
void Input()
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i <= n + 1; i++)
	{
		b[i][0] = 0;
		c[i][0] = 0;
	}
	for (j = 0; j <= m + 1; j++)
	{
		b[0][j] = c[0][j] = 0;
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (a[i][j] == 1)
			{
				b[i][j] = b[i-1][j] + b[i][j-1] - b[i-1][j-1] + 1;
			}
			else
			{
				b[i][j] = b[i-1][j] + b[i][j-1] - b[i-1][j-1];
			}
		}
	}
}
int Check(int i, int j, int k, int l, bool flag)
{
	int ii, jj;
	shang = 200, xia = -1, zuo = 200, you = -1;
	for (ii = 1; ii <= n; ii++)
	{
		for (jj = 1; jj <= m; jj++)
		{
			if (flag == (ii >= i && ii <= k && jj >= j && jj <= l) || a[ii][jj] != 2)
			{
				continue;
			}
			if (ii < shang)
			{
				shang = ii;
			}
			if (ii > xia)
			{
				xia = ii;
			}
			if (jj < zuo)
			{
				zuo = jj;
			}
			if (jj > you)
			{
				you = jj;
			}
		}
	}
	if (xia < 0)
	{
		return 0;
	}
	if(0 != b[xia][you] + b[shang-1][zuo-1] - b[xia][zuo-1] - b[shang-1][you])
		return INF;
	return (xia-shang+1) * (you-zuo+1);
}
void Solve()
{
	int ans = INF;
	int i, j, tk1, tk2, l;
	int i1, i2, j1, j2, k1, k2, l1, l2;
	for (i = 1; i < n; i++)
	{
		tk1 = Check(i+1, 1, n, m, 1);
		tk2 = Check(1, 1, i, m, 1);
		if (tk1 + tk2 < ans)
		{
			ans = tk1 + tk2;
		}
	}
	for (i = 1; i < m; i++)
	{
		tk1 = Check(1, i + 1, n, m, 1);
		tk2 = Check(1, 1, n, i, 1);
		if (tk1 + tk2 < ans)
		{
			ans = tk1 + tk2;
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = i; j <= n; j++)
		{
			tk1 = Check(1, i, n, j, 1);
			i1 = shang;
			k1 = xia;
			j1 = zuo;
			l1 = you;
			tk2 = Check(1, i, n, j, 0);
			i2 = shang;
			k2 = xia;
			j2 = zuo;
			l2 = you;
			l = tk1 + tk2;
			if (tk1 == INF || tk2 == INF)
			{
				continue;
			}
			if (!(k1 >= i2 || i1 >= k2 || j1 >= l2 || j2 >= l1))
			{
				l = l - (k1 - i1 + 1) * (l2 - j2 + 1);
			}

			if (l < ans)
			{
				ans = l;
			}
		}
	}
	if (ans >= INF)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", ans);
	}
}
int main()
{
	while(scanf("%d %d", &n, &m) !=EOF)
	{
		Input();
		Solve();
	}
	return 0;
}