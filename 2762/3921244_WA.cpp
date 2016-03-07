#include<iostream>
using namespace std;
bool c[1020][1020];
bool visit[1020];
int n, m, acmCount;
void init()
{
	int i, j;
	for(i = 0 ; i <= n; i++)
	{
		for(j = 0; j <= n; j++)
			c[i][j] = false;
	}
}
void MissHH()
{
	scanf("%d %d", &n, &m);
	init();
	int i, x, y;
	for(i = 0; i < m; i++)
	{
		scanf("%d%d",&x, &y);
		c[x][y] = 1;
	}
}
void dfs(int node)
{
	visit[node] = true;
	acmCount++;
	int i;
	for(i = 1; i <= n; i++)
	{
		if(!visit[i] && c[node][i])
			dfs(i);
	}
}
void fdfs(int node)
{
	visit[node] = true;
	acmCount++;
	int i;
	for(i = 1; i <= n; i++)
	{
		if(!visit[i] && c[i][node])
			fdfs(i);
	}
}
void LoveHH()
{
	memset(visit, false, sizeof(visit));
	acmCount = 0;
	dfs(1);
	fdfs(1);
	acmCount--;
	if(acmCount < n)
		printf("No\n");
	else
		printf("Yes\n");
}
int main ()
{
	int tc;
	scanf(" %d", &tc);
	while(tc--)
	{
		MissHH();
		LoveHH();
	}
	return 0;
}