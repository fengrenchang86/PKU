#include <iostream>
using namespace std;
bool v[30];
int c[30][30];
int ans, n;
void dfs(int lay, int val)
{
	if (lay == n)
	{
		if (val > ans)
		{
			ans = val;
		}
		return;
	}
	int i, x = 0, y = 0;
	for (i = 0; i < lay; i++)
	{
		if (v[i])
		{
			x += c[i][lay];
		}
		else
		{
			y += c[i][lay];
		}
	}
	v[i] = 0;
	dfs(lay + 1, val + x);
	v[i] = 1;
	dfs(lay + 1, val + y);
}
void Solve()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &c[i][j]);
		}
	}
	v[0] = 1;
	ans = 0;
	dfs(1, 0);
	printf("%d\n", ans);
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			break;
		}
		Solve();
	}
	return 0;
}