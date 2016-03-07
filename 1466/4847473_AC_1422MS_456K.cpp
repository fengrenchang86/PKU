#include <iostream>
using namespace std;
int n;
int xm[520], ym[520];
bool c[520][520];
bool visit[510];
void Input()
{
	int i, j, x, y, z;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			c[i][j] = false;
	}
	for(i = 0; i < n; i++)
	{
		scanf("%d: (%d)", &x, &y);
		for(j = 0; j < y; j++)
		{
			scanf("%d", &z);
			c[x][z] = c[z][x] = true;
		}
	}
}
bool dfs(int u)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(c[u][i] && !visit[i])
		{
			visit[i] = true;
			if(ym[i] == -1 || dfs(ym[i]))
			{
				ym[i] = u;
				xm[u] = i;
				return true;
			}
		}
	}
	return false;
}

int MaxMatch()
{
	int u;
	int ret = 0;
	memset(xm, -1, sizeof(xm));
	memset(ym, -1, sizeof(ym));
	for(u = 0; u < n; u++)
	{
		if(xm[u] == -1)
		{
			memset(visit, false, sizeof(visit));
			if(dfs(u))
				ret ++;
		}
	}
	return ret;
}

void Solve()
{
	int k = MaxMatch();
	printf("%d\n", n - k/2);
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
			break;
		Input();
		Solve();
	}
	return 0;
}