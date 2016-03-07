#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int id;
	int val;
	bool use;
}a[400];
int n, m;
int MIN, MAX;
int sum[400];
int c[100];
bool flag;
int cmp(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return d->val - c->val;
}
void Input()
{
	int i;
	for (i = 0; i < 3 * n; i++)
	{
		scanf("%d", &a[i].val);
		a[i].id = 1 + i;
		a[i].use = 0;
	}
	qsort(a, 3 * n, sizeof(a[0]), cmp);
}
void dfs(int lay, int nCount, int sumVal)
{
	if (nCount == n)
	{
		if (sumVal > MIN && sumVal < MAX)
		{
			int i;
			for (i = 0; i < 2 * n; i++)
			{
				if (a[i].use)
				{
					printf("%d\n", a[i].id);
				}
			}
			for (i = 0; i < 2 * n; i++)
			{
				if (!a[i].use)
				{
					printf("%d\n", a[i].id);
				}
			}
			while (i < 3 * n)
			{
				printf("%d\n", a[i].id);
				i++;
			}
			flag = true;
		}
		return;
	}
	if (lay - nCount > n)
	{
		return;
	}
	if (sumVal + sum[lay] - sum[lay+n-nCount] <= MIN)
	{
		return;
	}
	if (sumVal + sum[n + nCount] >= MAX)
	{
		return;
	}
	c[nCount] = a[lay].id;
	a[lay].use = true;
	dfs(lay + 1, nCount + 1, sumVal + a[lay].val);
	a[lay].use = false;
	if (!flag)
	{
		dfs(lay + 1, nCount, sumVal);
	}
}
void Solve()
{
	int i, j, k;
	m = 0;
	sum[2*n] = 0;
	for (i = 2 * n - 1; i >= 0; i--)
	{
		sum[i] = sum[i+1] + a[i].val;
		m += a[i].val;
	}
	MIN = 500 * n;
	MAX = m - 500 * n;
	dfs(0, 0, 0);
}
int main()
{
	scanf("%d", &n);
	Input();
	Solve();
	return 0;
}