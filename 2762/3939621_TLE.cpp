
#include<iostream>
using namespace std;
bool c[1020][1020];
bool visit[1020];
bool v[1020];
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
	if(!v[node])
	{
		acmCount++;
		v[node] = true;
	}
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
	if(!v[node])
	{
		acmCount++;
		v[node] = true;
	}
	int i;
	for(i = 1; i <= n; i++)
	{
		if(!visit[i] && c[i][node])
			fdfs(i);
	}
}
void LoveHH()
{
	int i;
	for(i = 1; i <= n; i++)
	{
		memset(visit, false, sizeof(visit));
		memset(v, false, sizeof(v));
		acmCount = 0;
		dfs(i);
		memset(visit, false, sizeof(visit));
		fdfs(i);		
		if(acmCount < n)
			break;
	}
	if(i <= n)
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