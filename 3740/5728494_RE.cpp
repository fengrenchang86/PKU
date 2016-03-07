#include <iostream>
using namespace std;
int n, m;
int a[20][400];
bool use[20];
bool flag = false;
void dfs(int lay, int t[])
{
	if (lay == n)
	{
		int i;
		for (i = 0; i < n;i ++)
		{
			if (t[i] == 0)
			{
				return;
			}
		}
		flag = true;
		return;
	}
	int i;
	for (i = 0; i < n; i++)
	{
		t[i] += a[lay][i];
	}
	use[lay] = true;
	dfs(lay + 1, t);
	for (i = 0; i < n; i++)
	{
		t[i] -= a[lay][i];
	}
	use[lay] = false;
	dfs(lay + 1, t);
}
void Input()
{
	int i, j;
	int t[400];
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	flag = false;
	memset(use ,false, sizeof(use));
	memset(t, 0, sizeof(t));
	dfs(0, t);
	if (flag)
	{
		printf("Yes, I found it\n");
	}
	else
	{
		printf("It is impossible\n");
	}
}
int main()
{
	while(scanf("%d %d", &m, &n) != EOF)
	{
		Input();
	}
	return 0;
}