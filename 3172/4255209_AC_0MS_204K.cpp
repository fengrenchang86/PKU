#include <iostream>
using namespace std;
int a[100], asum[100];
bool visit[100];
int c, n, ans = a[0];
void Input()
{
	int i;
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	asum[0] = a[0];
	for(i = 1; i < n; i++)
		asum[i] = asum[i-1] + a[i];
}
void dfs(int lay, int sum)
{
	if(sum < 0)
		return;
	if(ans < c - sum)
		ans = c-sum;
	if(lay == -1)
		return;
	if(sum >= asum[lay])
		dfs(-1, sum-asum[lay]);
	else
		dfs(lay-1, sum-a[lay]);
	dfs(lay-1, sum);
	return;
	if(lay >= 1 && (__int64)a[lay]+(__int64)a[lay-1] <= sum)
	{
		visit[lay] = true;
		dfs(lay-1, sum - a[lay]);
		visit[lay] = false;
	}
	else if(lay == 0)
	{
		if(a[0] <= sum)
			dfs(lay-1, sum-a[0]);
	}
	else if(lay < n-1 && (__int64)a[lay+1]+(__int64)a[lay] > sum)
	{
		if(visit[lay+1])
			dfs(lay-1, sum);
		else
		{
			visit[lay] = true;
			dfs(lay-1, sum - a[lay]);
			visit[lay] = false;
		}
	}
	else
		dfs(lay-1, sum);
}
void Solve()
{
	ans = 0;
	memset(visit, false, sizeof(visit));
	dfs(n-1, c);
	printf("%d\n", ans);
}
int main()
{
	while(scanf("%d %d", &n, &c) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}