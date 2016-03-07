#include <iostream>
using namespace std;
int a[100100];
int b[100100];
int sum[100100];
int n, m, ans;
void Solve()
{
	int i, x, y;
	ans = -1;
	sum[0] = 0;
	for (i = 1; i <= m; i++)
	{
		b[i] = -1;
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (ans != -1)
		{
			continue;
		}
		sum[i] = sum[i-1] + a[i];
		sum[i] %= m;
		if (sum[i] == 0)
		{
			ans = i;
			x = 1;
			y = i;
			continue;
		}
		if (b[sum[i]] == -1)
		{
			b[sum[i]] = i;
		}
		else
		{
			ans = 1;
			x = b[sum[i]]+1;
			y = i;
		}
	}
	if (ans != -1)
	{
		for (i = x; i <= y; i++)
		{
			printf("%d ", i);
		}
		printf("\n");
		return;
	}
}

int main()
{
	while (scanf("%d %d", &m, &n) != EOF)
	{
		if (m+n==0)
		{
			break;
		}
		Solve();
	}
	return 0;
}