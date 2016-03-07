#include <iostream>
using namespace std;
struct ac
{
	int dig[12];
}a[12];
bool visit[12];
int t[12];
int n, m;
bool flag;
void Init()
{
	int i, j, k;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
			a[i].dig[j] = 0;
		a[i].dig[i] = 1;
	}
	for(i = n-1; i >= 1; i--)
	{
		for(j = 1; j <= i; j++)
		{
			for(k = 1; k <= n; k++)
				a[j].dig[k] += a[j+1].dig[k];
		}
	}
	memset(visit, false, sizeof(visit));
	flag = false;
}
void dfs(int lay, int sum)
{
	int i;
	if(lay == n+1 && sum == m)
	{
		flag = true;
		return;
	}
	else if(sum >= m)
		return;
	for(i = 1; i <= n; i++)
	{
		if(visit[i])
			continue;
		visit[i] = true;
		t[lay] = i;
		if(sum + a[1].dig[lay] * i <= m)
			dfs(lay + 1, sum + a[1].dig[lay] * i);
		visit[i] = false;
		if(flag)
			return;
	}
}
int main()
{
	int i;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		Init();
		dfs(1, 0);
		for(i = 1; i < n; i++)
			printf("%d ", t[i]);
		printf("%d\n", t[n]);
	}
	return 0;
}