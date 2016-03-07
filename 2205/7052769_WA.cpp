
#include <iostream>
#include <vector>
using namespace std;
struct ac
{
	int size;
	int dig[2100];
}x, y, yy[2100];
int n, m, ans;
char table[2000][2100];
void Pingfang(ac *x, ac *y)
{
	int i, j;
	i = x->size-1;
	for (j = 0; j < x->size - 1 && i + j < n; j++)
	{
		y->dig[i+j] += 2 * x->dig[i] * x->dig[j];
		y->dig[i+j+1] += y->dig[i+j] / m;
		y->dig[i+j] %= m;
	}
	if (i + i < n)
	{
		y->dig[i+i] += x->dig[i] * x->dig[i];
		y->dig[i+i+1] += y->dig[i+i] / m;
		y->dig[i+i] %= m;
		y->size = i + i + 1;
	}
	
	if (y->size > n)
	{
		y->size = n;
	}
	while (y->dig[y->size] == 0)
	{
		y->size--;
	}
	y->size++;
}
int IsEqual(ac *x, ac *y, int nlen)
{
	for (int i = 0; i < nlen; i++)
	{
		if (x->dig[i] != y->dig[i])
		{
			return 0;
		}
	}
	return 1;
}
void dfs(int lay, ac *x)
{
	int i;
	if (lay == n)
	{
		if (x->dig[lay-1] == 0)
		{
			return;
		}
		for (i = lay - 1; i >= 0; i--)
		{
			if (x->dig[i] < 10)
			{
				table[ans][lay-1-i] = (x->dig[i] + '0');
//				printf("%d", x->dig[i]);
			}
			else
			{
				table[ans][lay-1-i] = (x->dig[i] - 10 + 'A');
//				printf("%c", x->dig[i]-10+'A');
			}
		}
		table[ans][lay] = 0;
//		printf("\n");
		ans ++;
		return;
	}
	yy[lay] = y;
	for (i = 0; i < m; i++)
	{
		x->dig[lay] = i;
		x->size = lay + 1;
		y = yy[lay];
		Pingfang(x, &y);
		if (IsEqual(x, &y, x->size))
		{
			dfs(lay + 1, x);
		}
	}
}
int main()
{
	int i;
	m = 10;
	n = 4;
	x.dig[4] = 1;
	x.dig[3] = 2;
	x.dig[2] = 3;
	x.dig[1] = 4;
	x.dig[0] = 5;
	for (i = 1; i <= 5; i++)
	{
		x.size = i;
		Pingfang(&x, &y);
	}
	while (scanf("%d %d", &m, &n) != EOF)
	{
		if (n == 1 && m == 1)
		{
			printf("1\n0\n");
			continue;
		}
		for (i = 0; i <= n; i++)
		{
			x.dig[i] = y.dig[i] = 0;
		}
		ans = 0;
		dfs(0, &x);
		printf("%d\n", ans);
		for (i = 0; i < ans; i++)
		{
			printf("%s\n", table[i]);
		}
	}
	return 0;
}