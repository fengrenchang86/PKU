#include <iostream>
using namespace std;
int xm[101], ym[301];
int n, m;
bool visit[301];
bool c[101][301];
bool dfs(int u)
{
	int i;
	for(i = 0; i < m; i++)
	{
		if(!visit[i] && c[u][i])
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
	memset(xm, -1, sizeof(xm));
	memset(ym, -1, sizeof(ym));
	int ncount = 0;
	int i;
	for(i = 0; i < n; i++)
	{
		memset(visit, false, sizeof(visit));
		if(dfs(i))
			ncount++;
	}
	return ncount;
}
void Input()
{
	int i, j, k, x;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
			c[i][j] = false;
	}
	for(i = 0; i < n; i++)
	{
		scanf("%d", &x);
		for(j = 0; j < x; j++)
		{
			scanf("%d", &k);
			c[i][k-1] = true;
		}
	}
}
void Solve()
{
	int k = MaxMatch();
	if(k == n)
		printf("YES\n");
	else
		printf("NO\n");
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		Input();
		Solve();
	}
	return 0;
}