#include <iostream>
using namespace std;
bool c[20][20];
bool visit[20];
int val[20];
int a[20];
int n, m, num;
__int64 ans;
void dfs(int lay, int node, __int64 nMax)
{
	if(n == lay)
	{
		if(nMax > ans)
		{
			ans = nMax;
			num = 1;
		}
		else if(nMax == ans)
			num++;
		return;
	}
	int i;
	__int64 j;
	for(i = 0; i < n; i++)
	{
		if(!visit[i] && c[i][node])
		{
			a[lay] = i;
			j = nMax + val[i];
			if(lay >= 1)
				j += val[i] * val[a[lay-1]];
			if(lay >= 2)
				j += val[i] * val[a[lay-1]] * val[a[lay-2]];
			visit[i] = true;
			dfs(lay+1, i, j);
			visit[i] = false;
		}
	}
}
void Init()
{
	memset(visit, false, sizeof(visit));
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			c[i][j] = false;
	}
}
void Input()
{
	scanf("%d %d", &n, &m);
	Init();
	int i, x, y;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &val[i]);
	}
	for(i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		x--;
		y--;
		c[x][y] = c[y][x] = true;
	}
}
void Solve()
{
	int i;
	ans = -1;
	for(i = 0; i < n; i++)
	{
		memset(visit, false, sizeof(visit));
		visit[i] = true;
		a[0] = i;
		dfs(1, i, val[i]);
	}
	if(ans != -1)
		printf("%I64d %d\n", ans, num/2);
	else
		printf("0 0\n");
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		Input();
		Solve();
	}
	return 0;
}